// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape_array.hpp"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__TRAITS_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pennair_vision_msgs/msg/detail/shape_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'shapes'
#include "pennair_vision_msgs/msg/detail/shape__traits.hpp"

namespace pennair_vision_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShapeArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: shapes
  {
    if (msg.shapes.size() == 0) {
      out << "shapes: []";
    } else {
      out << "shapes: [";
      size_t pending_items = msg.shapes.size();
      for (auto item : msg.shapes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: depth_inches
  {
    out << "depth_inches: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_inches, out);
    out << ", ";
  }

  // member: depth_valid
  {
    out << "depth_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShapeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: shapes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.shapes.size() == 0) {
      out << "shapes: []\n";
    } else {
      out << "shapes:\n";
      for (auto item : msg.shapes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: depth_inches
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_inches: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_inches, out);
    out << "\n";
  }

  // member: depth_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShapeArray & msg, bool use_flow_style = false)
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
  const pennair_vision_msgs::msg::ShapeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  pennair_vision_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pennair_vision_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pennair_vision_msgs::msg::ShapeArray & msg)
{
  return pennair_vision_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pennair_vision_msgs::msg::ShapeArray>()
{
  return "pennair_vision_msgs::msg::ShapeArray";
}

template<>
inline const char * name<pennair_vision_msgs::msg::ShapeArray>()
{
  return "pennair_vision_msgs/msg/ShapeArray";
}

template<>
struct has_fixed_size<pennair_vision_msgs::msg::ShapeArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pennair_vision_msgs::msg::ShapeArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pennair_vision_msgs::msg::ShapeArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__TRAITS_HPP_
