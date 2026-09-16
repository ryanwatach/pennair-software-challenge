// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice

#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pennair_vision_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pennair_vision_msgs/msg/detail/shape__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace pennair_vision_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
cdr_serialize(
  const pennair_vision_msgs::msg::Shape & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pennair_vision_msgs::msg::Shape & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
get_serialized_size(
  const pennair_vision_msgs::msg::Shape & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
max_serialized_size_Shape(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
cdr_serialize_key(
  const pennair_vision_msgs::msg::Shape & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
get_serialized_size_key(
  const pennair_vision_msgs::msg::Shape & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
max_serialized_size_key_Shape(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pennair_vision_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pennair_vision_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pennair_vision_msgs, msg, Shape)();

#ifdef __cplusplus
}
#endif

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
