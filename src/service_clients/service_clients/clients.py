import sys

from communication_interface.srv import Command
import rclpy
from rclpy.node import Node


class Client(Node):

    def __init__(self, node_name):
        rclpy.init()
        super().__init__(node_name)
        self.service_name = node_name

    def send_request(self, cmd_code, cmd_value):
        self.client = self.create_client(Command, self.service_name)
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        self.req = Command.Request()
        self.req.cmd_code = cmd_code
        self.req.cmd_value = cmd_value
        self.future = self.client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        
        return self.future.result()


def main(args=None):
    rclpy.init(args=args)

    action_service_client = Client('action')
    response = action_service_client.send_request(sys.argv[1], sys.argv[2])
    action_service_client.get_logger().info(
        'Result of Action: for %s + %s = %s' %
        (sys.argv[1], sys.argv[2], response.message))

    action_service_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
