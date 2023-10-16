// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ur_dashboard_msgs:srv/Popup.idl
// generated code does not contain a copyright notice

#ifndef UR_DASHBOARD_MSGS__SRV__DETAIL__POPUP__TRAITS_HPP_
#define UR_DASHBOARD_MSGS__SRV__DETAIL__POPUP__TRAITS_HPP_

#include "ur_dashboard_msgs/srv/detail/popup__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ur_dashboard_msgs::srv::Popup_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ur_dashboard_msgs::srv::Popup_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ur_dashboard_msgs::srv::Popup_Request>()
{
  return "ur_dashboard_msgs::srv::Popup_Request";
}

template<>
inline const char * name<ur_dashboard_msgs::srv::Popup_Request>()
{
  return "ur_dashboard_msgs/srv/Popup_Request";
}

template<>
struct has_fixed_size<ur_dashboard_msgs::srv::Popup_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ur_dashboard_msgs::srv::Popup_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ur_dashboard_msgs::srv::Popup_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ur_dashboard_msgs::srv::Popup_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: answer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "answer: ";
    value_to_yaml(msg.answer, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ur_dashboard_msgs::srv::Popup_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ur_dashboard_msgs::srv::Popup_Response>()
{
  return "ur_dashboard_msgs::srv::Popup_Response";
}

template<>
inline const char * name<ur_dashboard_msgs::srv::Popup_Response>()
{
  return "ur_dashboard_msgs/srv/Popup_Response";
}

template<>
struct has_fixed_size<ur_dashboard_msgs::srv::Popup_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ur_dashboard_msgs::srv::Popup_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ur_dashboard_msgs::srv::Popup_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ur_dashboard_msgs::srv::Popup>()
{
  return "ur_dashboard_msgs::srv::Popup";
}

template<>
inline const char * name<ur_dashboard_msgs::srv::Popup>()
{
  return "ur_dashboard_msgs/srv/Popup";
}

template<>
struct has_fixed_size<ur_dashboard_msgs::srv::Popup>
  : std::integral_constant<
    bool,
    has_fixed_size<ur_dashboard_msgs::srv::Popup_Request>::value &&
    has_fixed_size<ur_dashboard_msgs::srv::Popup_Response>::value
  >
{
};

template<>
struct has_bounded_size<ur_dashboard_msgs::srv::Popup>
  : std::integral_constant<
    bool,
    has_bounded_size<ur_dashboard_msgs::srv::Popup_Request>::value &&
    has_bounded_size<ur_dashboard_msgs::srv::Popup_Response>::value
  >
{
};

template<>
struct is_service<ur_dashboard_msgs::srv::Popup>
  : std::true_type
{
};

template<>
struct is_service_request<ur_dashboard_msgs::srv::Popup_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ur_dashboard_msgs::srv::Popup_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UR_DASHBOARD_MSGS__SRV__DETAIL__POPUP__TRAITS_HPP_
