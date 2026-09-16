// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice
#include "pennair_vision_msgs/msg/detail/shape__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `center_px`
// Member `center_camera`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `outline`
#include "geometry_msgs/msg/detail/polygon__functions.h"

bool
pennair_vision_msgs__msg__Shape__init(pennair_vision_msgs__msg__Shape * msg)
{
  if (!msg) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    pennair_vision_msgs__msg__Shape__fini(msg);
    return false;
  }
  // area_px
  // clipped
  // center_px
  if (!geometry_msgs__msg__Point__init(&msg->center_px)) {
    pennair_vision_msgs__msg__Shape__fini(msg);
    return false;
  }
  // center_camera
  if (!geometry_msgs__msg__Point__init(&msg->center_camera)) {
    pennair_vision_msgs__msg__Shape__fini(msg);
    return false;
  }
  // has_3d
  // outline
  if (!geometry_msgs__msg__Polygon__init(&msg->outline)) {
    pennair_vision_msgs__msg__Shape__fini(msg);
    return false;
  }
  return true;
}

void
pennair_vision_msgs__msg__Shape__fini(pennair_vision_msgs__msg__Shape * msg)
{
  if (!msg) {
    return;
  }
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // area_px
  // clipped
  // center_px
  geometry_msgs__msg__Point__fini(&msg->center_px);
  // center_camera
  geometry_msgs__msg__Point__fini(&msg->center_camera);
  // has_3d
  // outline
  geometry_msgs__msg__Polygon__fini(&msg->outline);
}

bool
pennair_vision_msgs__msg__Shape__are_equal(const pennair_vision_msgs__msg__Shape * lhs, const pennair_vision_msgs__msg__Shape * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  // area_px
  if (lhs->area_px != rhs->area_px) {
    return false;
  }
  // clipped
  if (lhs->clipped != rhs->clipped) {
    return false;
  }
  // center_px
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center_px), &(rhs->center_px)))
  {
    return false;
  }
  // center_camera
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center_camera), &(rhs->center_camera)))
  {
    return false;
  }
  // has_3d
  if (lhs->has_3d != rhs->has_3d) {
    return false;
  }
  // outline
  if (!geometry_msgs__msg__Polygon__are_equal(
      &(lhs->outline), &(rhs->outline)))
  {
    return false;
  }
  return true;
}

bool
pennair_vision_msgs__msg__Shape__copy(
  const pennair_vision_msgs__msg__Shape * input,
  pennair_vision_msgs__msg__Shape * output)
{
  if (!input || !output) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  // area_px
  output->area_px = input->area_px;
  // clipped
  output->clipped = input->clipped;
  // center_px
  if (!geometry_msgs__msg__Point__copy(
      &(input->center_px), &(output->center_px)))
  {
    return false;
  }
  // center_camera
  if (!geometry_msgs__msg__Point__copy(
      &(input->center_camera), &(output->center_camera)))
  {
    return false;
  }
  // has_3d
  output->has_3d = input->has_3d;
  // outline
  if (!geometry_msgs__msg__Polygon__copy(
      &(input->outline), &(output->outline)))
  {
    return false;
  }
  return true;
}

pennair_vision_msgs__msg__Shape *
pennair_vision_msgs__msg__Shape__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pennair_vision_msgs__msg__Shape * msg = (pennair_vision_msgs__msg__Shape *)allocator.allocate(sizeof(pennair_vision_msgs__msg__Shape), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pennair_vision_msgs__msg__Shape));
  bool success = pennair_vision_msgs__msg__Shape__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pennair_vision_msgs__msg__Shape__destroy(pennair_vision_msgs__msg__Shape * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pennair_vision_msgs__msg__Shape__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pennair_vision_msgs__msg__Shape__Sequence__init(pennair_vision_msgs__msg__Shape__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pennair_vision_msgs__msg__Shape * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(pennair_vision_msgs__msg__Shape)) {
      return false;
    }
    data = (pennair_vision_msgs__msg__Shape *)allocator.zero_allocate(size, sizeof(pennair_vision_msgs__msg__Shape), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pennair_vision_msgs__msg__Shape__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pennair_vision_msgs__msg__Shape__fini(&data[i - 1]);
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
pennair_vision_msgs__msg__Shape__Sequence__fini(pennair_vision_msgs__msg__Shape__Sequence * array)
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
      pennair_vision_msgs__msg__Shape__fini(&array->data[i]);
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

pennair_vision_msgs__msg__Shape__Sequence *
pennair_vision_msgs__msg__Shape__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pennair_vision_msgs__msg__Shape__Sequence * array = (pennair_vision_msgs__msg__Shape__Sequence *)allocator.allocate(sizeof(pennair_vision_msgs__msg__Shape__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pennair_vision_msgs__msg__Shape__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pennair_vision_msgs__msg__Shape__Sequence__destroy(pennair_vision_msgs__msg__Shape__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pennair_vision_msgs__msg__Shape__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pennair_vision_msgs__msg__Shape__Sequence__are_equal(const pennair_vision_msgs__msg__Shape__Sequence * lhs, const pennair_vision_msgs__msg__Shape__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pennair_vision_msgs__msg__Shape__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pennair_vision_msgs__msg__Shape__Sequence__copy(
  const pennair_vision_msgs__msg__Shape__Sequence * input,
  pennair_vision_msgs__msg__Shape__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(pennair_vision_msgs__msg__Shape)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(pennair_vision_msgs__msg__Shape);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pennair_vision_msgs__msg__Shape * data =
      (pennair_vision_msgs__msg__Shape *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pennair_vision_msgs__msg__Shape__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pennair_vision_msgs__msg__Shape__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pennair_vision_msgs__msg__Shape__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
