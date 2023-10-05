// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ur_dashboard_msgs:srv/GetProgramState.idl
// generated code does not contain a copyright notice
#include "ur_dashboard_msgs/srv/detail/get_program_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
ur_dashboard_msgs__srv__GetProgramState_Request__init(ur_dashboard_msgs__srv__GetProgramState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
ur_dashboard_msgs__srv__GetProgramState_Request__fini(ur_dashboard_msgs__srv__GetProgramState_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
ur_dashboard_msgs__srv__GetProgramState_Request__are_equal(const ur_dashboard_msgs__srv__GetProgramState_Request * lhs, const ur_dashboard_msgs__srv__GetProgramState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
ur_dashboard_msgs__srv__GetProgramState_Request__copy(
  const ur_dashboard_msgs__srv__GetProgramState_Request * input,
  ur_dashboard_msgs__srv__GetProgramState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

ur_dashboard_msgs__srv__GetProgramState_Request *
ur_dashboard_msgs__srv__GetProgramState_Request__create()
{
  ur_dashboard_msgs__srv__GetProgramState_Request * msg = (ur_dashboard_msgs__srv__GetProgramState_Request *)malloc(sizeof(ur_dashboard_msgs__srv__GetProgramState_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_dashboard_msgs__srv__GetProgramState_Request));
  bool success = ur_dashboard_msgs__srv__GetProgramState_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ur_dashboard_msgs__srv__GetProgramState_Request__destroy(ur_dashboard_msgs__srv__GetProgramState_Request * msg)
{
  if (msg) {
    ur_dashboard_msgs__srv__GetProgramState_Request__fini(msg);
  }
  free(msg);
}


bool
ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__init(ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ur_dashboard_msgs__srv__GetProgramState_Request * data = NULL;
  if (size) {
    data = (ur_dashboard_msgs__srv__GetProgramState_Request *)calloc(size, sizeof(ur_dashboard_msgs__srv__GetProgramState_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_dashboard_msgs__srv__GetProgramState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_dashboard_msgs__srv__GetProgramState_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__fini(ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ur_dashboard_msgs__srv__GetProgramState_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ur_dashboard_msgs__srv__GetProgramState_Request__Sequence *
ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__create(size_t size)
{
  ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * array = (ur_dashboard_msgs__srv__GetProgramState_Request__Sequence *)malloc(sizeof(ur_dashboard_msgs__srv__GetProgramState_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__destroy(ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * array)
{
  if (array) {
    ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__fini(array);
  }
  free(array);
}

bool
ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__are_equal(const ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * lhs, const ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_dashboard_msgs__srv__GetProgramState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_dashboard_msgs__srv__GetProgramState_Request__Sequence__copy(
  const ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * input,
  ur_dashboard_msgs__srv__GetProgramState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_dashboard_msgs__srv__GetProgramState_Request);
    ur_dashboard_msgs__srv__GetProgramState_Request * data =
      (ur_dashboard_msgs__srv__GetProgramState_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_dashboard_msgs__srv__GetProgramState_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ur_dashboard_msgs__srv__GetProgramState_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_dashboard_msgs__srv__GetProgramState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
#include "ur_dashboard_msgs/msg/detail/program_state__functions.h"
// Member `program_name`
// Member `answer`
#include "rosidl_runtime_c/string_functions.h"

bool
ur_dashboard_msgs__srv__GetProgramState_Response__init(ur_dashboard_msgs__srv__GetProgramState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!ur_dashboard_msgs__msg__ProgramState__init(&msg->state)) {
    ur_dashboard_msgs__srv__GetProgramState_Response__fini(msg);
    return false;
  }
  // program_name
  if (!rosidl_runtime_c__String__init(&msg->program_name)) {
    ur_dashboard_msgs__srv__GetProgramState_Response__fini(msg);
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__init(&msg->answer)) {
    ur_dashboard_msgs__srv__GetProgramState_Response__fini(msg);
    return false;
  }
  // success
  return true;
}

void
ur_dashboard_msgs__srv__GetProgramState_Response__fini(ur_dashboard_msgs__srv__GetProgramState_Response * msg)
{
  if (!msg) {
    return;
  }
  // state
  ur_dashboard_msgs__msg__ProgramState__fini(&msg->state);
  // program_name
  rosidl_runtime_c__String__fini(&msg->program_name);
  // answer
  rosidl_runtime_c__String__fini(&msg->answer);
  // success
}

bool
ur_dashboard_msgs__srv__GetProgramState_Response__are_equal(const ur_dashboard_msgs__srv__GetProgramState_Response * lhs, const ur_dashboard_msgs__srv__GetProgramState_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!ur_dashboard_msgs__msg__ProgramState__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // program_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->program_name), &(rhs->program_name)))
  {
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->answer), &(rhs->answer)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
ur_dashboard_msgs__srv__GetProgramState_Response__copy(
  const ur_dashboard_msgs__srv__GetProgramState_Response * input,
  ur_dashboard_msgs__srv__GetProgramState_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!ur_dashboard_msgs__msg__ProgramState__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // program_name
  if (!rosidl_runtime_c__String__copy(
      &(input->program_name), &(output->program_name)))
  {
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__copy(
      &(input->answer), &(output->answer)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

ur_dashboard_msgs__srv__GetProgramState_Response *
ur_dashboard_msgs__srv__GetProgramState_Response__create()
{
  ur_dashboard_msgs__srv__GetProgramState_Response * msg = (ur_dashboard_msgs__srv__GetProgramState_Response *)malloc(sizeof(ur_dashboard_msgs__srv__GetProgramState_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_dashboard_msgs__srv__GetProgramState_Response));
  bool success = ur_dashboard_msgs__srv__GetProgramState_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ur_dashboard_msgs__srv__GetProgramState_Response__destroy(ur_dashboard_msgs__srv__GetProgramState_Response * msg)
{
  if (msg) {
    ur_dashboard_msgs__srv__GetProgramState_Response__fini(msg);
  }
  free(msg);
}


bool
ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__init(ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ur_dashboard_msgs__srv__GetProgramState_Response * data = NULL;
  if (size) {
    data = (ur_dashboard_msgs__srv__GetProgramState_Response *)calloc(size, sizeof(ur_dashboard_msgs__srv__GetProgramState_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_dashboard_msgs__srv__GetProgramState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_dashboard_msgs__srv__GetProgramState_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__fini(ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ur_dashboard_msgs__srv__GetProgramState_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ur_dashboard_msgs__srv__GetProgramState_Response__Sequence *
ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__create(size_t size)
{
  ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * array = (ur_dashboard_msgs__srv__GetProgramState_Response__Sequence *)malloc(sizeof(ur_dashboard_msgs__srv__GetProgramState_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__destroy(ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * array)
{
  if (array) {
    ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__fini(array);
  }
  free(array);
}

bool
ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__are_equal(const ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * lhs, const ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_dashboard_msgs__srv__GetProgramState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_dashboard_msgs__srv__GetProgramState_Response__Sequence__copy(
  const ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * input,
  ur_dashboard_msgs__srv__GetProgramState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_dashboard_msgs__srv__GetProgramState_Response);
    ur_dashboard_msgs__srv__GetProgramState_Response * data =
      (ur_dashboard_msgs__srv__GetProgramState_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_dashboard_msgs__srv__GetProgramState_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ur_dashboard_msgs__srv__GetProgramState_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_dashboard_msgs__srv__GetProgramState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
