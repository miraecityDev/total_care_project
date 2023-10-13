// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from communication_interface:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__TRAITS_HPP_
#define COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "communication_interface/srv/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace communication_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Action_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_code
  {
    out << "cmd_code: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_code, out);
    out << ", ";
  }

  // member: cmd_value
  {
    out << "cmd_value: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_code: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_code, out);
    out << "\n";
  }

  // member: cmd_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_value: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace communication_interface

namespace rosidl_generator_traits
{

[[deprecated("use communication_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const communication_interface::srv::Action_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  communication_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use communication_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const communication_interface::srv::Action_Request & msg)
{
  return communication_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<communication_interface::srv::Action_Request>()
{
  return "communication_interface::srv::Action_Request";
}

template<>
inline const char * name<communication_interface::srv::Action_Request>()
{
  return "communication_interface/srv/Action_Request";
}

template<>
struct has_fixed_size<communication_interface::srv::Action_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<communication_interface::srv::Action_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<communication_interface::srv::Action_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace communication_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Action_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace communication_interface

namespace rosidl_generator_traits
{

[[deprecated("use communication_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const communication_interface::srv::Action_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  communication_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use communication_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const communication_interface::srv::Action_Response & msg)
{
  return communication_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<communication_interface::srv::Action_Response>()
{
  return "communication_interface::srv::Action_Response";
}

template<>
inline const char * name<communication_interface::srv::Action_Response>()
{
  return "communication_interface/srv/Action_Response";
}

template<>
struct has_fixed_size<communication_interface::srv::Action_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<communication_interface::srv::Action_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<communication_interface::srv::Action_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<communication_interface::srv::Action>()
{
  return "communication_interface::srv::Action";
}

template<>
inline const char * name<communication_interface::srv::Action>()
{
  return "communication_interface/srv/Action";
}

template<>
struct has_fixed_size<communication_interface::srv::Action>
  : std::integral_constant<
    bool,
    has_fixed_size<communication_interface::srv::Action_Request>::value &&
    has_fixed_size<communication_interface::srv::Action_Response>::value
  >
{
};

template<>
struct has_bounded_size<communication_interface::srv::Action>
  : std::integral_constant<
    bool,
    has_bounded_size<communication_interface::srv::Action_Request>::value &&
    has_bounded_size<communication_interface::srv::Action_Response>::value
  >
{
};

template<>
struct is_service<communication_interface::srv::Action>
  : std::true_type
{
};

template<>
struct is_service_request<communication_interface::srv::Action_Request>
  : std::true_type
{
};

template<>
struct is_service_response<communication_interface::srv::Action_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__TRAITS_HPP_
