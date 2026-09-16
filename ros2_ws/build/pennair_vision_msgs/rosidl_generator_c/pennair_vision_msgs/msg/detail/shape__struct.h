// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape.h"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__STRUCT_H_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'label'
#include "rosidl_runtime_c/string.h"
// Member 'center_px'
// Member 'center_camera'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'outline'
#include "geometry_msgs/msg/detail/polygon__struct.h"

/// Struct defined in msg/Shape in the package pennair_vision_msgs.
/**
  * One detected shape.
 */
typedef struct pennair_vision_msgs__msg__Shape
{
  /// "triangle", "circle", "shape (clipped)", ...
  rosidl_runtime_c__String label;
  /// traced area in pixels
  double area_px;
  /// touches the frame border, so only partly visible
  bool clipped;
  /// centroid in pixels (z unused)
  geometry_msgs__msg__Point center_px;
  /// centroid as X,Y,Z inches in the camera frame
  geometry_msgs__msg__Point center_camera;
  /// false when no depth was available
  bool has_3d;
  /// traced contour, pixel coords (z unused)
  geometry_msgs__msg__Polygon outline;
} pennair_vision_msgs__msg__Shape;

// Struct for a sequence of pennair_vision_msgs__msg__Shape.
typedef struct pennair_vision_msgs__msg__Shape__Sequence
{
  pennair_vision_msgs__msg__Shape * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pennair_vision_msgs__msg__Shape__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__STRUCT_H_
