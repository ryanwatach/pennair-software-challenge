// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape_array.h"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__STRUCT_H_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'shapes'
#include "pennair_vision_msgs/msg/detail/shape__struct.h"

/// Struct defined in msg/ShapeArray in the package pennair_vision_msgs.
/**
  * All shapes found in one frame.
 */
typedef struct pennair_vision_msgs__msg__ShapeArray
{
  /// stamp/frame_id copied from the source image
  std_msgs__msg__Header header;
  pennair_vision_msgs__msg__Shape__Sequence shapes;
  /// scene depth used for the 3D centers
  double depth_inches;
  /// false before the circle has ever been seen
  bool depth_valid;
} pennair_vision_msgs__msg__ShapeArray;

// Struct for a sequence of pennair_vision_msgs__msg__ShapeArray.
typedef struct pennair_vision_msgs__msg__ShapeArray__Sequence
{
  pennair_vision_msgs__msg__ShapeArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pennair_vision_msgs__msg__ShapeArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__STRUCT_H_
