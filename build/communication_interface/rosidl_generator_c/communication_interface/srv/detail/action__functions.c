// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from communication_interface:srv/Action.idl
// generated code does not contain a copyright notice
#include "communication_interface/srv/detail/action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `cmd_code`
// Member `cmd_value`
#include "rosidl_runtime_c/string_functions.h"

bool
communication_interface__srv__Action_Request__init(communication_interface__srv__Action_Request * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_code
  if (!rosidl_runtime_c__String__init(&msg->cmd_code)) {
    communication_interface__srv__Action_Request__fini(msg);
    return false;
  }
  // cmd_value
  if (!rosidl_runtime_c__String__init(&msg->cmd_value)) {
    communication_interface__srv__Action_Request__fini(msg);
    return false;
  }
  return true;
}

void
communication_interface__srv__Action_Request__fini(communication_interface__srv__Action_Request * msg)
{
  if (!msg) {
    return;
  }
  // cmd_code
  rosidl_runtime_c__String__fini(&msg->cmd_code);
  // cmd_value
  rosidl_runtime_c__String__fini(&msg->cmd_value);
}

bool
communication_interface__srv__Action_Request__are_equal(const communication_interface__srv__Action_Request * lhs, const communication_interface__srv__Action_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_code
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cmd_code), &(rhs->cmd_code)))
  {
    return false;
  }
  // cmd_value
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cmd_value), &(rhs->cmd_value)))
  {
    return false;
  }
  return true;
}

bool
communication_interface__srv__Action_Request__copy(
  const communication_interface__srv__Action_Request * input,
  communication_interface__srv__Action_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_code
  if (!rosidl_runtime_c__String__copy(
      &(input->cmd_code), &(output->cmd_code)))
  {
    return false;
  }
  // cmd_value
  if (!rosidl_runtime_c__String__copy(
      &(input->cmd_value), &(output->cmd_value)))
  {
    return false;
  }
  return true;
}

communication_interface__srv__Action_Request *
communication_interface__srv__Action_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_interface__srv__Action_Request * msg = (communication_interface__srv__Action_Request *)allocator.allocate(sizeof(communication_interface__srv__Action_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_interface__srv__Action_Request));
  bool success = communication_interface__srv__Action_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_interface__srv__Action_Request__destroy(communication_interface__srv__Action_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_interface__srv__Action_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_interface__srv__Action_Request__Sequence__init(communication_interface__srv__Action_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_interface__srv__Action_Request * data = NULL;

  if (size) {
    data = (communication_interface__srv__Action_Request *)allocator.zero_allocate(size, sizeof(communication_interface__srv__Action_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_interface__srv__Action_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_interface__srv__Action_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_interface__srv__Action_Request__Sequence__fini(communication_interface__srv__Action_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_interface__srv__Action_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_interface__srv__Action_Request__Sequence *
communication_interface__srv__Action_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_interface__srv__Action_Request__Sequence * array = (communication_interface__srv__Action_Request__Sequence *)allocator.allocate(sizeof(communication_interface__srv__Action_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_interface__srv__Action_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_interface__srv__Action_Request__Sequence__destroy(communication_interface__srv__Action_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_interface__srv__Action_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_interface__srv__Action_Request__Sequence__are_equal(const communication_interface__srv__Action_Request__Sequence * lhs, const communication_interface__srv__Action_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_interface__srv__Action_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_interface__srv__Action_Request__Sequence__copy(
  const communication_interface__srv__Action_Request__Sequence * input,
  communication_interface__srv__Action_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(communication_interface__srv__Action_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_interface__srv__Action_Request * data =
      (communication_interface__srv__Action_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_interface__srv__Action_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_interface__srv__Action_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_interface__srv__Action_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
communication_interface__srv__Action_Response__init(communication_interface__srv__Action_Response * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    communication_interface__srv__Action_Response__fini(msg);
    return false;
  }
  return true;
}

void
communication_interface__srv__Action_Response__fini(communication_interface__srv__Action_Response * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
communication_interface__srv__Action_Response__are_equal(const communication_interface__srv__Action_Response * lhs, const communication_interface__srv__Action_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
communication_interface__srv__Action_Response__copy(
  const communication_interface__srv__Action_Response * input,
  communication_interface__srv__Action_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

communication_interface__srv__Action_Response *
communication_interface__srv__Action_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_interface__srv__Action_Response * msg = (communication_interface__srv__Action_Response *)allocator.allocate(sizeof(communication_interface__srv__Action_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_interface__srv__Action_Response));
  bool success = communication_interface__srv__Action_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_interface__srv__Action_Response__destroy(communication_interface__srv__Action_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_interface__srv__Action_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_interface__srv__Action_Response__Sequence__init(communication_interface__srv__Action_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_interface__srv__Action_Response * data = NULL;

  if (size) {
    data = (communication_interface__srv__Action_Response *)allocator.zero_allocate(size, sizeof(communication_interface__srv__Action_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_interface__srv__Action_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_interface__srv__Action_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_interface__srv__Action_Response__Sequence__fini(communication_interface__srv__Action_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_interface__srv__Action_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_interface__srv__Action_Response__Sequence *
communication_interface__srv__Action_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_interface__srv__Action_Response__Sequence * array = (communication_interface__srv__Action_Response__Sequence *)allocator.allocate(sizeof(communication_interface__srv__Action_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_interface__srv__Action_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_interface__srv__Action_Response__Sequence__destroy(communication_interface__srv__Action_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_interface__srv__Action_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_interface__srv__Action_Response__Sequence__are_equal(const communication_interface__srv__Action_Response__Sequence * lhs, const communication_interface__srv__Action_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_interface__srv__Action_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_interface__srv__Action_Response__Sequence__copy(
  const communication_interface__srv__Action_Response__Sequence * input,
  communication_interface__srv__Action_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(communication_interface__srv__Action_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_interface__srv__Action_Response * data =
      (communication_interface__srv__Action_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_interface__srv__Action_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_interface__srv__Action_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_interface__srv__Action_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
