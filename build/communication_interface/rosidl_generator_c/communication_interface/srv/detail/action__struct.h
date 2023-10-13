// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_interface:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__STRUCT_H_
#define COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cmd_code'
// Member 'cmd_value'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Action in the package communication_interface.
typedef struct communication_interface__srv__Action_Request
{
  rosidl_runtime_c__String cmd_code;
  rosidl_runtime_c__String cmd_value;
} communication_interface__srv__Action_Request;

// Struct for a sequence of communication_interface__srv__Action_Request.
typedef struct communication_interface__srv__Action_Request__Sequence
{
  communication_interface__srv__Action_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_interface__srv__Action_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Action in the package communication_interface.
typedef struct communication_interface__srv__Action_Response
{
  rosidl_runtime_c__String message;
} communication_interface__srv__Action_Response;

// Struct for a sequence of communication_interface__srv__Action_Response.
typedef struct communication_interface__srv__Action_Response__Sequence
{
  communication_interface__srv__Action_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_interface__srv__Action_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_INTERFACE__SRV__DETAIL__ACTION__STRUCT_H_
