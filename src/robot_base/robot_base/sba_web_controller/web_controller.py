#!/usr/bin/env python3.8
# import rospy
# from sba_robot_pkg.srv._Service import *
#
# from lib.ros_clients import Clients
# import lib.rtsp_cam as camera
# from lib.move import OnvifCamera

from fastapi.responses import PlainTextResponse, StreamingResponse, HTMLResponse
from fastapi.templating import Jinja2Templates
from fastapi.staticfiles import StaticFiles
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from fastapi import FastAPI, Request, Depends, HTTPException
from typing import Optional
from pydantic import BaseModel
from passlib.context import CryptContext
import jwt
import json
from starlette.responses import JSONResponse
from datetime import datetime, timedelta
import logging
import time
import os
import subprocess
import uvicorn

app = FastAPI()
# templates_path = r"D:\work\totalcare\web\templates"
# static_path = r"D:\work\totalcare\web\static"
templates_path = r"/home/kkk/Downloads/TalkFile_web.zip/templates"
static_path = r"/home/kkk/Downloads/TalkFile_web.zip/static"
templates = Jinja2Templates(directory=templates_path)
app.mount("/static", StaticFiles(directory=static_path), name="static")
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
# client = Clients()  # ROS Clients
# onvifCam = OnvifCamera()

user = None


class User:
    def __init__(self, user_id: str, hashed_password: str):
        self.user_id = user_id
        self.hashed_password = hashed_password


class ROBOT_MOVE_CMD(BaseModel):
    cmdCode: str
    cmdValue: str


class ROBOT_CAM_CMD(BaseModel):
    cmdCode: str
    cmdTime: str


class ROBOT_LED_CMD(BaseModel):
    cmdCode: str
    cmdValue: str

# 가짜 사용자 데이터베이스를 만듭니다.
# fake_users_db = {
#     "master": User("master", pwd_context.hash("1234")),
#     "admin": User("admin", pwd_context.hash("admin")),
# }

# JWT 설정을 정의합니다.
JWT_SECRET = "39b85242046588463de3c2f8083d52a629f790ab97aa79b13d6729614048912fdcec513d031958e109ac121eebf40c5cb54c69ae2e146a4f79cf00c257d5cb6f"
JWT_ALGORITHM = "HS256"
JWT_EXPIRATION_TIME_MINUTES = 30

# OAuth2 액세스 토큰을 요청하는데 사용되는 객체를 만듭니다.
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")


# 사용자를 인증하는 함수를 정의합니다.
def authenticate_user(user_id: str, password: str):
    users_db = {}
    with open(r"./lib/user.json", "r") as fp:
        user_data = json.load(fp)
        for user in user_data["user"]:
            users_db[user["id"]] = User(user["id"], pwd_context.hash(user["password"]))
    if user_id not in users_db:
        return False
    user = users_db[user_id]
    if not pwd_context.verify(password, user.hashed_password):
        return False
    return user


# JWT 토큰을 생성하는 함수를 정의합니다.
def create_jwt_token(user_id: str):
    expiration_time = datetime.utcnow() + timedelta(minutes=JWT_EXPIRATION_TIME_MINUTES)
    jwt_payload = {"sub": user_id, "exp": expiration_time}
    jwt_token = jwt.encode(jwt_payload, JWT_SECRET, algorithm=JWT_ALGORITHM)
    return jwt_token


# 토큰을 디코딩하여 사용자 정보를 가져오는 함수를 정의합니다.
def decode_jwt_token(token: str):
    try:
        decoded_token = jwt.decode(token, JWT_SECRET, algorithms=[JWT_ALGORITHM])
        user_id = decoded_token["sub"]
        return user_id
    except jwt.ExpiredSignatureError:
        raise HTTPException(status_code=401, detail="Token has expired")
    except jwt.InvalidTokenError:
        raise HTTPException(status_code=401, detail="Invalid token")


# 파일 리스트를 가져오는 함수
def get_file_list():
    path = "/home/soc/image"
    files = []
    for file in os.listdir(path):
        if os.path.isfile(path+"/"+file):
            files.append(file)
    return files


# 로그 파일 생성 함수
@app.on_event("startup")
async def startup():
    now = time.localtime(time.time())
    dir = os.path.join('log', str(now.tm_year), str(now.tm_mon))
    os.makedirs(dir, exist_ok=True)
    # file name
    file_name = dir + f'/data_{str(now.tm_mday)}.log'

    app.logger = logging.getLogger('[TotalCare_Robot]')
    app.logger.setLevel(logging.INFO)

    # create console handler and set level to debug
    ch = logging.StreamHandler()
    ch.setLevel(logging.INFO)

    # File addHandler
    fileHandler = logging.handlers.TimedRotatingFileHandler(filename=file_name, when='midnight', interval=1,
                                                            encoding='utf-8')

    # create formatter
    formatter = logging.Formatter('%(asctime)s: %(message)s')

    # add formatter to ch
    ch.setFormatter(formatter)
    fileHandler.setFormatter(formatter)

    # add ch to logger
    app.logger.addHandler(ch)
    app.logger.addHandler(fileHandler)


# 로그인 페이지
@app.get("/", response_class=HTMLResponse)
async def login_page(request: Request):
    app.logger.info("TotalCare Robot Home")
    return templates.TemplateResponse("login.html", {"request": request})


# 인덱스 페이지 (로그인 후)
@app.get("/index", response_class=HTMLResponse)
async def index_page(request: Request):
    global user
    if not user:
        raise HTTPException(status_code=422, detail="로그인 정보가 없습니다.")
    return templates.TemplateResponse("index.html", {"request": request, "username": user.user_id})


# robot status
@app.get("/status")
async def robot_status():
    response_data = {}
    # serverStatus = json.loads(client.robot_status("/status", None))  # data from Robot Status
    serverStatus = {
        "status": "stop",
        "position": 0.0,
        "current_velocity": 0.0,
        "battery": 100
    }
    # app.logger.info(f"SBA Robot Status: {serverStatus}")
    response_data["status"] = serverStatus["status"]
    response_data["position"] = round(serverStatus["position"], 1)
    response_data["speed"] = round(serverStatus["current_velocity"], 1)
    response_data["battery"] = serverStatus["battery"]
    return JSONResponse(response_data)


# rtsp camera
@app.get('/stream')
async def rtsp_camera():
    app.logger.info(f"SBA Robot Streaming")
    return StreamingResponse(camera.gen_frames(), media_type='multipart/x-mixed-replace; boundary=frame')


# robot move
@app.post("/move", status_code=200)
async def robot_move(request: ROBOT_MOVE_CMD):
    response_data = {"rTime": int(round(time.time(), 0))}
    req_dict = request.dict()
    app.logger.info(req_dict)
    # client.action(req_dict["cmdCode"], req_dict["cmdValue"])
    return JSONResponse(response_data)


# robot camera led
@app.post("/led", status_code=200)
async def robot_camera_led(request: ROBOT_LED_CMD):
    response_data = {"rTime": int(round(time.time(), 0))}
    req_dict = request.dict()
    app.logger.info(req_dict)
    client.led_control(req_dict["cmdCode"], req_dict["cmdValue"])
    return JSONResponse(response_data)


# cam ptz
@app.post("/ptz", status_code=200)
async def robot_ptz(request: ROBOT_CAM_CMD):
    response_data = {"rTime": int(round(time.time(), 0))}
    timeout = 0.1
    req_dict = request.dict()
    if req_dict["cmdTime"] == "slow":
        timeout = 0.1
    elif req_dict["cmdTime"] == "medium":
        timeout = 0.3
    elif req_dict["cmdTime"] == "fast":
        timeout = 0.5
    else:
        raise HTTPException(status_code=422, detail="커맨드 시간을 확인해주세요")
    if req_dict["cmdCode"] == "left":
        onvifCam.move_left(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "right":
        onvifCam.move_right(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "up":
        onvifCam.move_up(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "down":
        onvifCam.move_down(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "zoom up":
        onvifCam.zoom_up(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "zoom down":
        onvifCam.zoom_down(timeout=timeout)
        pass
    else:
        raise HTTPException(status_code=422, detail="커맨드 코드를 확인해주세요")
    return JSONResponse(response_data)


# reboot
@app.post("/reboot", status_code=200)
async def reboot():
    subprocess.call(["sudo", "reboot"])
    return {"result": "success"}


# 로그인 엔드포인트를 정의합니다.
@app.post("/login")
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
    global user
    user = authenticate_user(form_data.username, form_data.password)
    if not user:
        raise HTTPException(status_code=401, detail="사용자 이름 또는 비밀번호를 확인해주세요")
    jwt_token = create_jwt_token(user.user_id)
    return {"access_token": jwt_token, "token_type": "bearer"}


# 파일 리스트를 가져옵니다.
'''
@app.get("/file_list", response_class=HTMLResponse)
async def read_file_list():
    files = get_file_list()
    app.logger.info(files)
    content = "<h1>File List</h1>"
    for file in files:
        content += f"<p>{file}</p>"
    return content
'''


# 보호된 엔드포인트를 정의합니다.
@app.get("/protected")
def protected(username: str = Depends(decode_jwt_token)):
    return {"username": username}


@app.on_event("shutdown")
async def shutdown():
    app.logger.info("Server shutdown")


if __name__ == "__main__":
    try:
        # rospy.init_node("web_controller", anonymous=True)
        uvicorn.run("web_controller:app", host="0.0.0.0", port=5005, log_level="info", reload=True, timeout_keep_alive=5)
        # uvicorn.run("web_controller:app",
        #             host="0.0.0.0",
        #             port=5005,
        #             ssl_keyfile="/home/soc/key.pem",
        #             ssl_certfile="/home/soc/cert.pem",
        #             log_level="info",
        #             reload=True,
        #             timeout_keep_alive=5)
    except Exception as e:
    # except rospy.ROSInterruptException:
        print("Web Controller Exception")
        uvicorn.stop()
