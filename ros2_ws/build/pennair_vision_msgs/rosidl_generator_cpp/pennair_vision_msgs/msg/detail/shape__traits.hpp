// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape.hpp"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__TRAITS_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pennair_vision_msgs/msg/detail/shape__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'center_px'
// Member 'center_camera'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'outline'
#include "geometry_msgs/msg/detail/polygon__traits.hpp"

namespace pennair_vision_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Shape & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: area_px
  {
    out << "area_px: ";
    rosidl_generator_traits::value_to_yaml(msg.area_px, out);
    out << ", ";
  }

  // member: clipped
  {
    out << "clipped: ";
    rosidl_generator_traits::value_to_yaml(msg.clipped, out);
    out << ", ";
  }

  // member: center_px
  {
    out << "center_px: ";
    to_flow_style_yaml(msg.center_px, out);
    out << ", ";
  }

  // member: center_camera
  {
    out << "center_camera: ";
    to_flow_style_yaml(msg.center_camera, out);
    out << ", ";
  }

  // member: has_3d
  {
    out << "has_3d: ";
    rosidl_generator_traits::value_to_yaml(msg.has_3d, out);
    out << ", ";
  }

  // member: outline
  {
    out << "outline: ";
    to_flow_style_yaml(msg.outline, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Shape & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
  }

  // member: area_px
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "area_px: ";
    rosidl_generator_traits::value_to_yaml(msg.area_px, out);
    out << "\n";
  }

  // member: clipped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "clipped: ";
    rosidl_generator_traits::value_to_yaml(msg.clipped, out);
    out << "\n";
  }

  // member: center_px
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_px:\n";
    to_block_style_yaml(msg.center_px, out, indentation + 2);
  }

  // member: center_camera
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_camera:\n";
    to_block_style_yaml(msg.center_camera, out, indentation + 2);
  }

  // member: has_3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_3d: ";
    rosidl_generator_traits::value_to_yaml(msg.has_3d, out);
    out << "\n";
  }

  // member: outline
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "outline:\n";
    to_block_style_yaml(msg.outline, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Shape & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pennair_vision_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pennair_vision_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pennair_vision_msgs::msg::Shape & msg,
  std::ostream & out, size_t indentation = 0)
{
  pennair_vision_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pennair_vision_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pennair_vision_msgs::msg::Shape & msg)
{
  return pennair_vision_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pennair_vision_msgs::msg::Shape>()
{
  return "pennair_vision_msgs::msg::Shape";
}

template<>
inline const char * name<pennair_vision_msgs::msg::Shape>()
{
  return "pennair_vision_msgs/msg/Shape";
}

template<>
struct has_fixed_size<pennair_vision_msgs::msg::Shape>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pennair_vision_msgs::msg::Shape>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pennair_vision_msgs::msg::Shape>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__TRAITS_HPP_
