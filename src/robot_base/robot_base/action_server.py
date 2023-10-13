#!/usr/bin/env python3
import rclpy
import json
from rclpy.node import Node
from communication_interface.srv import Command


class ActionServer(Node):

    def __init__(self):
        super().__init__('action_server')
        self.action_service = self.create_service(Command, 'action', self.action_callback)

    def action_callback(self, request, response):
        response.message = json.dumps(
                                        {
                                            'cmd_code': request.cmd_code,
                                            'cmd_value': request.cmd_value
                                        }
                                    )
        self.get_logger().info('Request: cmd_code: %s cmd_value: %s ' % (request.cmd_code, request.cmd_value))
        self.get_logger().info('Response: %s' % response.message)
        
        return response


def main():
    rclpy.init()

    action_server = ActionServer()

    rclpy.spin(action_server)

    rclpy.shutdown()



if __name__ == "__main__":
    main()
