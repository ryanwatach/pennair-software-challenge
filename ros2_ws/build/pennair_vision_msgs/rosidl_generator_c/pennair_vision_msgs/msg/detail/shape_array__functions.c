// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice
#include "pennair_vision_msgs/msg/detail/shape_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `shapes`
#include "pennair_vision_msgs/msg/detail/shape__functions.h"

bool
pennair_vision_msgs__msg__ShapeArray__init(pennair_vision_msgs__msg__ShapeArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pennair_vision_msgs__msg__ShapeArray__fini(msg);
    return false;
  }
  // shapes
  if (!pennair_vision_msgs__msg__Shape__Sequence__init(&msg->shapes, 0)) {
    pennair_vision_msgs__msg__ShapeArray__fini(msg);
    return false;
  }
  // depth_inches
  // depth_valid
  return true;
}

void
pennair_vision_msgs__msg__ShapeArray__fini(pennair_vision_msgs__msg__ShapeArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // shapes
  pennair_vision_msgs__msg__Shape__Sequence__fini(&msg->shapes);
  // depth_inches
  // depth_valid
}

bool
pennair_vision_msgs__msg__ShapeArray__are_equal(const pennair_vision_msgs__msg__ShapeArray * lhs, const pennair_vision_msgs__msg__ShapeArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // shapes
  if (!pennair_vision_msgs__msg__Shape__Sequence__are_equal(
      &(lhs->shapes), &(rhs->shapes)))
  {
    return false;
  }
  // depth_inches
  if (lhs->depth_inches != rhs->depth_inches) {
    return false;
  }
  // depth_valid
  if (lhs->depth_valid != rhs->depth_valid) {
    return false;
  }
  return true;
}

bool
pennair_vision_msgs__msg__ShapeArray__copy(
  const pennair_vision_msgs__msg__ShapeArray * input,
  pennair_vision_msgs__msg__ShapeArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // shapes
  if (!pennair_vision_msgs__msg__Shape__Sequence__copy(
      &(input->shapes), &(output->shapes)))
  {
    return false;
  }
  // depth_inches
  output->depth_inches = input->depth_inches;
  // depth_valid
  output->depth_valid = input->depth_valid;
  return true;
}

pennair_vision_msgs__msg__ShapeArray *
pennair_vision_msgs__msg__ShapeArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pennair_vision_msgs__msg__ShapeArray * msg = (pennair_vision_msgs__msg__ShapeArray *)allocator.allocate(sizeof(pennair_vision_msgs__msg__ShapeArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pennair_vision_msgs__msg__ShapeArray));
  bool success = pennair_vision_msgs__msg__ShapeArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pennair_vision_msgs__msg__ShapeArray__destroy(pennair_vision_msgs__msg__ShapeArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pennair_vision_msgs__msg__ShapeArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pennair_vision_msgs__msg__ShapeArray__Sequence__init(pennair_vision_msgs__msg__ShapeArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pennair_vision_msgs__msg__ShapeArray * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(pennair_vision_msgs__msg__ShapeArray)) {
      return false;
    }
    data = (pennair_vision_msgs__msg__ShapeArray *)allocator.zero_allocate(size, sizeof(pennair_vision_msgs__msg__ShapeArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pennair_vision_msgs__msg__ShapeArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pennair_vision_msgs__msg__ShapeArray__fini(&data[i - 1]);
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
pennair_vision_msgs__msg__ShapeArray__Sequence__fini(pennair_vision_msgs__msg__ShapeArray__Sequence * array)
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
      pennair_vision_msgs__msg__ShapeArray__fini(&array->data[i]);
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

pennair_vision_msgs__msg__ShapeArray__Sequence *
pennair_vision_msgs__msg__ShapeArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pennair_vision_msgs__msg__ShapeArray__Sequence * array = (pennair_vision_msgs__msg__ShapeArray__Sequence *)allocator.allocate(sizeof(pennair_vision_msgs__msg__ShapeArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pennair_vision_msgs__msg__ShapeArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pennair_vision_msgs__msg__ShapeArray__Sequence__destroy(pennair_vision_msgs__msg__ShapeArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pennair_vision_msgs__msg__ShapeArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pennair_vision_msgs__msg__ShapeArray__Sequence__are_equal(const pennair_vision_msgs__msg__ShapeArray__Sequence * lhs, const pennair_vision_msgs__msg__ShapeArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pennair_vision_msgs__msg__ShapeArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pennair_vision_msgs__msg__ShapeArray__Sequence__copy(
  const pennair_vision_msgs__msg__ShapeArray__Sequence * input,
  pennair_vision_msgs__msg__ShapeArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(pennair_vision_msgs__msg__ShapeArray)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(pennair_vision_msgs__msg__ShapeArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pennair_vision_msgs__msg__ShapeArray * data =
      (pennair_vision_msgs__msg__ShapeArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pennair_vision_msgs__msg__ShapeArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pennair_vision_msgs__msg__ShapeArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pennair_vision_msgs__msg__ShapeArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
