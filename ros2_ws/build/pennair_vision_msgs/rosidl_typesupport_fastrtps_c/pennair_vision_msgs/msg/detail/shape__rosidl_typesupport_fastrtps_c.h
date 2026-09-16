// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice
#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pennair_vision_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pennair_vision_msgs/msg/detail/shape__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
bool cdr_serialize_pennair_vision_msgs__msg__Shape(
  const pennair_vision_msgs__msg__Shape * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
bool cdr_deserialize_pennair_vision_msgs__msg__Shape(
  eprosima::fastcdr::Cdr &,
  pennair_vision_msgs__msg__Shape * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t get_serialized_size_pennair_vision_msgs__msg__Shape(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t max_serialized_size_pennair_vision_msgs__msg__Shape(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
bool cdr_serialize_key_pennair_vision_msgs__msg__Shape(
  const pennair_vision_msgs__msg__Shape * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t get_serialized_size_key_pennair_vision_msgs__msg__Shape(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t max_serialized_size_key_pennair_vision_msgs__msg__Shape(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pennair_vision_msgs, msg, Shape)();

#ifdef __cplusplus
}
#endif

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
