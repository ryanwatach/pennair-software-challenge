// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape_array.hpp"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__BUILDER_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pennair_vision_msgs/msg/detail/shape_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pennair_vision_msgs
{

namespace msg
{

namespace builder
{

class Init_ShapeArray_depth_valid
{
public:
  explicit Init_ShapeArray_depth_valid(::pennair_vision_msgs::msg::ShapeArray & msg)
  : msg_(msg)
  {}
  ::pennair_vision_msgs::msg::ShapeArray depth_valid(::pennair_vision_msgs::msg::ShapeArray::_depth_valid_type arg)
  {
    msg_.depth_valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pennair_vision_msgs::msg::ShapeArray msg_;
};

class Init_ShapeArray_depth_inches
{
public:
  explicit Init_ShapeArray_depth_inches(::pennair_vision_msgs::msg::ShapeArray & msg)
  : msg_(msg)
  {}
  Init_ShapeArray_depth_valid depth_inches(::pennair_vision_msgs::msg::ShapeArray::_depth_inches_type arg)
  {
    msg_.depth_inches = std::move(arg);
    return Init_ShapeArray_depth_valid(msg_);
  }

private:
  ::pennair_vision_msgs::msg::ShapeArray msg_;
};

class Init_ShapeArray_shapes
{
public:
  explicit Init_ShapeArray_shapes(::pennair_vision_msgs::msg::ShapeArray & msg)
  : msg_(msg)
  {}
  Init_ShapeArray_depth_inches shapes(::pennair_vision_msgs::msg::ShapeArray::_shapes_type arg)
  {
    msg_.shapes = std::move(arg);
    return Init_ShapeArray_depth_inches(msg_);
  }

private:
  ::pennair_vision_msgs::msg::ShapeArray msg_;
};

class Init_ShapeArray_header
{
public:
  Init_ShapeArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ShapeArray_shapes header(::pennair_vision_msgs::msg::ShapeArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ShapeArray_shapes(msg_);
  }

private:
  ::pennair_vision_msgs::msg::ShapeArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pennair_vision_msgs::msg::ShapeArray>()
{
  return pennair_vision_msgs::msg::builder::Init_ShapeArray_header();
}

}  // namespace pennair_vision_msgs

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__BUILDER_HPP_
