"""
Web Controller Module
"""
from datetime import datetime, timedelta
import json
import logging
import os
import subprocess
import time

import jwt
# pylint: disable=E0611
from pydantic import BaseModel
from fastapi.responses import StreamingResponse, HTMLResponse, JSONResponse, RedirectResponse
from fastapi.templating import Jinja2Templates
from fastapi.staticfiles import StaticFiles
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from fastapi import FastAPI, Form, Request, Depends, HTTPException
from passlib.context import CryptContext
import user_management as user_manage
import uvicorn
import rclpy
from rclpy.node import Node


class WebController(Node):
    def __init__(self):
        super().__init__('web_controller')


# 상수
TEMPLATES_PATH = r"templates"
STATIC_PATH = r"static"
USER = None
JWT_SECRET = (
    "39b85242046588463de3c2f8083d52a629f790ab97aa79b13d6729614048912f"
    "dcec513d031958e109ac121eebf40c5cb54c69ae2e146a4f79cf00c257d5cb6f"
)
JWT_ALGORITHM = "HS256"
JWT_EXPIRATION_TIME_MINUTES = 30

LOGIN_USER = []

# OAuth2 access token request object
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

# FastAPI settings
app = FastAPI()
templates = Jinja2Templates(directory=TEMPLATES_PATH)
app.mount("/static", StaticFiles(directory=STATIC_PATH), name="static")
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")


# Model definitions
class User:
    """
    This class represents a user.

    Attributes:
        user_id (str): The user's unique identifier.
        hashed_password (str): The hashed password associated with the user.
    """
    def __init__(self, user_id: str, hashed_password: str):
        self.user_id = user_id
        self.hashed_password = hashed_password


class LoggedInUser:
    """
    Class representing a logged-in user.

    Attributes:
        user_id (str): The user's unique identifier.
        access_token (str): The user's access token.
    """
    def __init__(self, user_id: str, access_token: str):
        self.user_id = user_id
        self.access_token = access_token


class CreateUser(BaseModel):
    """
    Model for creating a new user account.

    Attributes:
        username (str): The username for the new user.
        password (str): The password for the new user.
    """
    username: str
    password: str


class RobotMoveCmd(BaseModel):
    """
    This class represents a robot movement command.

    Attributes:
        cmdCode (str): The code of the movement command.
        cmdValue (str): The value associated with the command.
    """
    cmdCode: str
    cmdValue: str


class RobotCamCmd(BaseModel):
    """
    This class represents a robot camera command.

    Attributes:
        cmdCode (str): The code of the camera command.
        cmdTime (str): The time associated with the command.
    """
    cmdCode: str
    cmdTime: str


class RobotLedCmd(BaseModel):
    """
    This class represents a robot LED command.

    Attributes:
        cmdCode (str): The code of the LED command.
        cmdValue (str): The value associated with the command.
    """
    cmdCode: str
    cmdValue: str


def authenticate_user(user_id: str, password: str):
    """
    Verify an authenticated user and validate the password provided by the user.

    Args:
        user_id (str): The user's unique identifier.
        password (str): The password provided by the user.

    Returns:
        Union[User, bool]: Returns a User object if the user is authenticated,
        or False if authentication fails.
    """
    users_db = {}
    with open(r"./lib/users.json", "r", encoding="utf-8") as file_pointer:
        user_data = json.load(file_pointer)
        for user in user_data["user"]:
            users_db[user["id"]] = User(user["id"], user["password"])
    if user_id not in users_db:
        raise HTTPException(status_code=404, detail="사용자를 찾을 수 없습니다.")
    user = users_db[user_id]
    if not pwd_context.verify(password, user.hashed_password):
        raise HTTPException(status_code=401, detail="비밀번호가 일치하지 않습니다.")
    return user


# Function to create a JWT token
def create_jwt_token(user_id: str):
    """
    Generate a JSON Web Token (JWT) for a user.

    Args:
        user_id (str): The user's unique identifier.

    Returns:
        str: The JWT token.
    """
    expiration_time = datetime.utcnow() + timedelta(minutes=JWT_EXPIRATION_TIME_MINUTES)
    jwt_payload = {"id": user_id, "exp": expiration_time}
    jwt_token = jwt.encode(jwt_payload, JWT_SECRET, algorithm=JWT_ALGORITHM)
    return jwt_token


# Function to decode a JWT token and get user information
def decode_jwt_token(token: str):
    """
    Decode a JSON Web Token (JWT) and extract user information.

    Args:
        token (str): The token to decode.

    Returns:
        str: The user ID extracted from the token.

    Raises:
        HTTPException: Raise an exception if the token has expired or is invalid.
    """
    try:
        decoded_token = jwt.decode(token, JWT_SECRET, algorithms=[JWT_ALGORITHM])
        user_id = decoded_token["id"]
        return user_id
    except jwt.ExpiredSignatureError as exc:
        app.logger.error("Token has expired")
        raise HTTPException(status_code=401, detail="Token has expired") from exc
    except jwt.InvalidTokenError as exc:
        app.logger.error("Invalid token")
        raise HTTPException(status_code=401, detail="Invalid token") from exc


# Function to get a list of files
def get_file_list():
    """
    Get a list of files in a specific directory.

    Returns:
        List[str]: List of file names.
    """
    path = "/home/soc/image"
    files = []
    for file in os.listdir(path):
        if os.path.isfile(os.path.join(path, file)):
            files.append(file)
    return files


# Function to create log files
@app.on_event("startup")
async def startup():
    """
    Initialize logging when the application starts.
    """
    now = time.localtime(time.time())
    log_dir = os.path.join('log', str(now.tm_year), str(now.tm_mon))
    os.makedirs(log_dir, exist_ok=True)
    # File name
    file_name = os.path.join(log_dir, f'data_{str(now.tm_mday)}.log')

    app.logger = logging.getLogger('[TotalCare_Robot]')
    app.logger.setLevel(logging.INFO)

    # Create console handler and set the log level to INFO
    console_handler = logging.StreamHandler()
    console_handler.setLevel(logging.INFO)

    # File handler
    file_handler = logging.handlers.TimedRotatingFileHandler(
        filename=file_name,
        when='midnight',
        interval=1,
        encoding='utf-8'
    )
    # Create a formatter
    formatter = logging.Formatter('%(asctime)s: %(message)s')

    # Add the formatter to the console handler and file handler
    console_handler.setFormatter(formatter)
    file_handler.setFormatter(formatter)

    # Add the console handler and file handler to the logger
    app.logger.addHandler(console_handler)
    app.logger.addHandler(file_handler)


# Login page
@app.get("/", response_class=HTMLResponse)
async def login_page(request: Request):
    """
    Provide the login page.

    Args:
        request (Request): The incoming request.

    Returns:
        TemplateResponse: The login page template.
    """
    app.logger.info("TotalCare Robot Home")
    return templates.TemplateResponse("login.html", {"request": request})


# Index page (after login)
@app.get("/index", response_class=HTMLResponse)
async def index_page(request: Request, current_user: str = Depends(decode_jwt_token)):
    """
    Provide the index page after login.

    Args:
        request (Request): The incoming request.
        user (User, optional): The current logged-in user. The default is obtained
        through Depends on(decode_jwt_token).

    Returns:
        TemplateResponse: The index page template.

    Raises:
        HTTPException: Return a 422 status code if not logged in.
        :param request:
        :param current_user:
    """
    if current_user is None:
        app.logger.warning("No current user")
        return RedirectResponse("/", status_code=302)
        # raise HTTPException(status_code=422, detail="로그인 정보가 없습니다.")
    # 현재 사용자와 일치하는 로그인된 사용자를 찾습니다.
    logged_in_user = next((user for user in LOGIN_USER if user.user_id == current_user), None)
    if logged_in_user is None:
        app.logger.warning("No logged in user")
        return RedirectResponse("/", status_code=302)
        # raise HTTPException(status_code=422, detail="로그인 정보가 없습니다.")
    return templates.TemplateResponse("index.html", {"request": request, "username": current_user})


# Robot status
@app.get("/status")
async def robot_status():
    """
    Check the robot's status.

    Returns:
        JSONResponse: JSON response containing the robot's status.
    """
    response_data = {}
    # serverStatus = json.loads(client.robot_status("/status", None))  # data from Robot Status
    server_status = {
        "status": "stop",
        "position": 0.0,
        "current_velocity": 0.0,
        "battery": 100
    }
    # app.logger.info(f"SBA Robot Status: {serverStatus}")
    response_data["status"] = server_status["status"]
    response_data["position"] = round(server_status["position"], 1)
    response_data["speed"] = round(server_status["current_velocity"], 1)
    response_data["battery"] = server_status["battery"]
    return JSONResponse(response_data)


# RTSP camera
@app.get('/stream')
async def rtsp_camera():
    """
    Stream the robot's camera.

    Returns:
        StreamingResponse: Streaming response containing video frames.
    """
    app.logger.info("SBA Robot Streaming")
    # return StreamingResponse(
        # camera.gen_frames(),
        # media_type='multipart/x-mixed-replace; boundary=frame'
    # )


# Robot move
@app.post("/move", status_code=200)
async def robot_move(request: RobotMoveCmd):
    """
    Control the robot's movement.

    Args:
        request (RobotMoveCmd): Robot movement command.

    Returns:
        JSONResponse: JSON response containing a timestamp.
    """
    response_data = {"rTime": int(round(time.time(), 0))}
    req_dict = request.dict()
    app.logger.info(req_dict)
    # client.action(req_dict["cmdCode"], req_dict["cmdValue"])
    return JSONResponse(response_data)


# Robot camera LED
@app.post("/led", status_code=200)
async def robot_camera_led(request: RobotLedCmd):
    """
    Control the robot's camera LED.

    Args:
        request (RobotLedCmd): LED control command.

    Returns:
        JSONResponse: JSON response containing a timestamp.
    """
    response_data = {"rTime": int(round(time.time(), 0))}
    req_dict = request.dict()
    app.logger.info(req_dict)
    # client.led_control(req_dict["cmdCode"], req_dict["cmdValue"])
    return JSONResponse(response_data)


# Camera PTZ
@app.post("/ptz", status_code=200)
async def robot_ptz(request: RobotCamCmd):
    """
    Control the robot's camera PTZ (Pan, Tilt, Zoom).

    Args:
        request (RobotCamCmd): Camera PTZ command.

    Returns:
        JSONResponse: JSON response containing a timestamp.
    """
    response_data = {"rTime": int(round(time.time(), 0))}
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
        # onvifCam.move_left(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "right":
        # onvifCam.move_right(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "up":
        # onvifCam.move_up(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "down":
        # onvifCam.move_down(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "zoom up":
        # onvifCam.zoom_up(timeout=timeout)
        pass
    elif req_dict["cmdCode"] == "zoom down":
        # onvifCam.zoom_down(timeout=timeout)
        pass
    else:
        raise HTTPException(status_code=422, detail="커맨드 코드를 확인해주세요")
    return JSONResponse(response_data)


# Reboot
@app.post("/reboot", status_code=200)
async def reboot():
    """
    Restart the system.

    Returns:
        dict: Dictionary indicating the restart result.
    """
    subprocess.call(["sudo", "reboot"])
    return {"result": "success"}


# Create user
@app.get("/create", response_class=HTMLResponse)
async def create_user_form(request: Request):
    """
    Create the user registration form.

    Args:
        request (Request): The incoming HTTP request.

    Returns:
        HTMLResponse: A response containing the user registration form.
    """
    return templates.TemplateResponse("create.html", {"request": request})

# Created user
@app.post("/create_user", response_class=HTMLResponse)
async def create_user(request: Request, username: str = Form(...), password: str = Form(...)):
    """
    Create a new user account.

    Args:
        username (str): Username
        password (str): Password

    Returns:
        dict: A dictionary representing the result of the account creation.
        :param password:
        :param username:
        :param request:
    """
    try:
        ret = user_manage.create_user(username, password)
        if ret:
            app.logger.info(f"User {username} has been created")
        else:
            raise HTTPException(status_code=422, detail="계정 생성 실패")
        return templates.TemplateResponse("user_created.html", {"request": request, "username": username})
    except Exception as err:
        app.logger.error(f"Error creating user: {str(err)}")
        raise


# Login endpoint
@app.post("/login")
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
    """
    Authenticate the user and generate an access token.

    Args:
        form_data (OAuth2PasswordRequestForm, optional): Obtain the username and password
        using OAuth2PasswordRequestForm.

    Returns:
        dict: A dictionary containing the access token and token type.
    """
    try:
        user = authenticate_user(form_data.username, form_data.password)
        if user is None:
            raise HTTPException(status_code=401, detail="사용자 이름 또는 비밀번호를 확인해주세요")
        # Generates an access token for the user.
        jwt_token = create_jwt_token(user.user_id)

        # Add login users to the list.
        LOGIN_USER.append(LoggedInUser(user.user_id, jwt_token))
        app.logger.info(f"User '{user.user_id}' has logged in")
        return {"access_token": jwt_token, "token_type": "bearer"}
    except Exception as err:
        app.logger.error(f"Error during login: {str(err)}")
        raise


# Logout endpoint
@app.post("/logout", status_code=200)
async def logout(request: Request):
    """
    Logout endpoint to handle user logout.
    """
    json_data = await request.json()  # JSON data from POST request
    # Find logout users and remove them from the list.
    username_to_logout = json_data.get("username")
    global LOGIN_USER
    LOGIN_USER = [user for user in LOGIN_USER if user.user_id != username_to_logout]
    app.logger.info(f"User '{username_to_logout}' has logged out")
    return {"message": "로그아웃되었습니다."}


# Protected endpoint
@app.get("/protected")
def protected(current_user: str = Depends(decode_jwt_token)):
    """
    A protected endpoint that decodes the JWT token to return the username.

    Args:
        current_user (str): The user ID obtained through JWT token decoding.

    Returns:
        dict: A dictionary containing the user's username.
    """
    return {"username": current_user}


@app.on_event("shutdown")
async def shutdown():
    """
    Event handler called when the server is shutting down.
    """
    app.logger.info("Server shutdown")

def main():
    rclpy.init()

    web_controller = WebController()

    try:
        uvicorn.run("web_controller.web_controller:app",
                    host="0.0.0.0",
                    port=5005,
                    log_level="info",
                    reload=True,
                    timeout_keep_alive=5)
        # uvicorn.run("web_controller:app",
        #             host="0.0.0.0",
        #             port=5005,
        #             ssl_keyfile="/home/soc/key.pem",
        #             ssl_certfile="/home/soc/cert.pem",
        #             log_level="info",
        #             reload=True,
        #             timeout_keep_alive=5)
    except Exception as e:
        print("Web Controller Exception")
        uvicorn.stop()

    web_controller.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
