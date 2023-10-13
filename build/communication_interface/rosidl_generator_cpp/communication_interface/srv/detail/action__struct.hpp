// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from communication_interface:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__STRUCT_HPP_
#define COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__communication_interface__srv__Action_Request __attribute__((deprecated))
#else
# define DEPRECATED__communication_interface__srv__Action_Request __declspec(deprecated)
#endif

namespace communication_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Action_Request_
{
  using Type = Action_Request_<ContainerAllocator>;

  explicit Action_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_code = "";
      this->cmd_value = "";
    }
  }

  explicit Action_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd_code(_alloc),
    cmd_value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_code = "";
      this->cmd_value = "";
    }
  }

  // field types and members
  using _cmd_code_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cmd_code_type cmd_code;
  using _cmd_value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cmd_value_type cmd_value;

  // setters for named parameter idiom
  Type & set__cmd_code(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cmd_code = _arg;
    return *this;
  }
  Type & set__cmd_value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cmd_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_interface::srv::Action_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_interface::srv::Action_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_interface::srv::Action_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_interface::srv::Action_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_interface::srv::Action_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_interface::srv::Action_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_interface::srv::Action_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_interface::srv::Action_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_interface::srv::Action_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_interface::srv::Action_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_interface__srv__Action_Request
    std::shared_ptr<communication_interface::srv::Action_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_interface__srv__Action_Request
    std::shared_ptr<communication_interface::srv::Action_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_Request_ & other) const
  {
    if (this->cmd_code != other.cmd_code) {
      return false;
    }
    if (this->cmd_value != other.cmd_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_Request_

// alias to use template instance with default allocator
using Action_Request =
  communication_interface::srv::Action_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace communication_interface


#ifndef _WIN32
# define DEPRECATED__communication_interface__srv__Action_Response __attribute__((deprecated))
#else
# define DEPRECATED__communication_interface__srv__Action_Response __declspec(deprecated)
#endif

namespace communication_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Action_Response_
{
  using Type = Action_Response_<ContainerAllocator>;

  explicit Action_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  explicit Action_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_interface::srv::Action_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_interface::srv::Action_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_interface::srv::Action_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_interface::srv::Action_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_interface::srv::Action_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_interface::srv::Action_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_interface::srv::Action_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_interface::srv::Action_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_interface::srv::Action_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_interface::srv::Action_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_interface__srv__Action_Response
    std::shared_ptr<communication_interface::srv::Action_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_interface__srv__Action_Response
    std::shared_ptr<communication_interface::srv::Action_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_Response_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_Response_

// alias to use template instance with default allocator
using Action_Response =
  communication_interface::srv::Action_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace communication_interface

namespace communication_interface
{

namespace srv
{

struct Action
{
  using Request = communication_interface::srv::Action_Request;
  using Response = communication_interface::srv::Action_Response;
};

}  // namespace srv

}  // namespace communication_interface

#endif  // COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__STRUCT_HPP_
