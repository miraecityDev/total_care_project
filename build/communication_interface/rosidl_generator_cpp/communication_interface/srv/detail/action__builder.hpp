// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_interface:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__BUILDER_HPP_
#define COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_interface/srv/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_interface
{

namespace srv
{

namespace builder
{

class Init_Action_Request_cmd_value
{
public:
  explicit Init_Action_Request_cmd_value(::communication_interface::srv::Action_Request & msg)
  : msg_(msg)
  {}
  ::communication_interface::srv::Action_Request cmd_value(::communication_interface::srv::Action_Request::_cmd_value_type arg)
  {
    msg_.cmd_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_interface::srv::Action_Request msg_;
};

class Init_Action_Request_cmd_code
{
public:
  Init_Action_Request_cmd_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Action_Request_cmd_value cmd_code(::communication_interface::srv::Action_Request::_cmd_code_type arg)
  {
    msg_.cmd_code = std::move(arg);
    return Init_Action_Request_cmd_value(msg_);
  }

private:
  ::communication_interface::srv::Action_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_interface::srv::Action_Request>()
{
  return communication_interface::srv::builder::Init_Action_Request_cmd_code();
}

}  // namespace communication_interface


namespace communication_interface
{

namespace srv
{

namespace builder
{

class Init_Action_Response_message
{
public:
  Init_Action_Response_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::communication_interface::srv::Action_Response message(::communication_interface::srv::Action_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_interface::srv::Action_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_interface::srv::Action_Response>()
{
  return communication_interface::srv::builder::Init_Action_Response_message();
}

}  // namespace communication_interface

#endif  // COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__BUILDER_HPP_
