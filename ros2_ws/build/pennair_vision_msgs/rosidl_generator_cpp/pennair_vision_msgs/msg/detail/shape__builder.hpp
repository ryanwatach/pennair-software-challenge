// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape.hpp"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__BUILDER_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pennair_vision_msgs/msg/detail/shape__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pennair_vision_msgs
{

namespace msg
{

namespace builder
{

class Init_Shape_outline
{
public:
  explicit Init_Shape_outline(::pennair_vision_msgs::msg::Shape & msg)
  : msg_(msg)
  {}
  ::pennair_vision_msgs::msg::Shape outline(::pennair_vision_msgs::msg::Shape::_outline_type arg)
  {
    msg_.outline = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

class Init_Shape_has_3d
{
public:
  explicit Init_Shape_has_3d(::pennair_vision_msgs::msg::Shape & msg)
  : msg_(msg)
  {}
  Init_Shape_outline has_3d(::pennair_vision_msgs::msg::Shape::_has_3d_type arg)
  {
    msg_.has_3d = std::move(arg);
    return Init_Shape_outline(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

class Init_Shape_center_camera
{
public:
  explicit Init_Shape_center_camera(::pennair_vision_msgs::msg::Shape & msg)
  : msg_(msg)
  {}
  Init_Shape_has_3d center_camera(::pennair_vision_msgs::msg::Shape::_center_camera_type arg)
  {
    msg_.center_camera = std::move(arg);
    return Init_Shape_has_3d(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

class Init_Shape_center_px
{
public:
  explicit Init_Shape_center_px(::pennair_vision_msgs::msg::Shape & msg)
  : msg_(msg)
  {}
  Init_Shape_center_camera center_px(::pennair_vision_msgs::msg::Shape::_center_px_type arg)
  {
    msg_.center_px = std::move(arg);
    return Init_Shape_center_camera(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

class Init_Shape_clipped
{
public:
  explicit Init_Shape_clipped(::pennair_vision_msgs::msg::Shape & msg)
  : msg_(msg)
  {}
  Init_Shape_center_px clipped(::pennair_vision_msgs::msg::Shape::_clipped_type arg)
  {
    msg_.clipped = std::move(arg);
    return Init_Shape_center_px(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

class Init_Shape_area_px
{
public:
  explicit Init_Shape_area_px(::pennair_vision_msgs::msg::Shape & msg)
  : msg_(msg)
  {}
  Init_Shape_clipped area_px(::pennair_vision_msgs::msg::Shape::_area_px_type arg)
  {
    msg_.area_px = std::move(arg);
    return Init_Shape_clipped(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

class Init_Shape_label
{
public:
  Init_Shape_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Shape_area_px label(::pennair_vision_msgs::msg::Shape::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Shape_area_px(msg_);
  }

private:
  ::pennair_vision_msgs::msg::Shape msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pennair_vision_msgs::msg::Shape>()
{
  return pennair_vision_msgs::msg::builder::Init_Shape_label();
}

}  // namespace pennair_vision_msgs

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__BUILDER_HPP_
