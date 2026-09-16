// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape.hpp"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__STRUCT_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'center_px'
// Member 'center_camera'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'outline'
#include "geometry_msgs/msg/detail/polygon__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pennair_vision_msgs__msg__Shape __attribute__((deprecated))
#else
# define DEPRECATED__pennair_vision_msgs__msg__Shape __declspec(deprecated)
#endif

namespace pennair_vision_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Shape_
{
  using Type = Shape_<ContainerAllocator>;

  explicit Shape_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center_px(_init),
    center_camera(_init),
    outline(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->area_px = 0.0;
      this->clipped = false;
      this->has_3d = false;
    }
  }

  explicit Shape_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc),
    center_px(_alloc, _init),
    center_camera(_alloc, _init),
    outline(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->area_px = 0.0;
      this->clipped = false;
      this->has_3d = false;
    }
  }

  // field types and members
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _area_px_type =
    double;
  _area_px_type area_px;
  using _clipped_type =
    bool;
  _clipped_type clipped;
  using _center_px_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_px_type center_px;
  using _center_camera_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_camera_type center_camera;
  using _has_3d_type =
    bool;
  _has_3d_type has_3d;
  using _outline_type =
    geometry_msgs::msg::Polygon_<ContainerAllocator>;
  _outline_type outline;

  // setters for named parameter idiom
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__area_px(
    const double & _arg)
  {
    this->area_px = _arg;
    return *this;
  }
  Type & set__clipped(
    const bool & _arg)
  {
    this->clipped = _arg;
    return *this;
  }
  Type & set__center_px(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center_px = _arg;
    return *this;
  }
  Type & set__center_camera(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center_camera = _arg;
    return *this;
  }
  Type & set__has_3d(
    const bool & _arg)
  {
    this->has_3d = _arg;
    return *this;
  }
  Type & set__outline(
    const geometry_msgs::msg::Polygon_<ContainerAllocator> & _arg)
  {
    this->outline = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pennair_vision_msgs::msg::Shape_<ContainerAllocator> *;
  using ConstRawPtr =
    const pennair_vision_msgs::msg::Shape_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pennair_vision_msgs::msg::Shape_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pennair_vision_msgs::msg::Shape_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pennair_vision_msgs__msg__Shape
    std::shared_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pennair_vision_msgs__msg__Shape
    std::shared_ptr<pennair_vision_msgs::msg::Shape_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Shape_ & other) const
  {
    if (this->label != other.label) {
      return false;
    }
    if (this->area_px != other.area_px) {
      return false;
    }
    if (this->clipped != other.clipped) {
      return false;
    }
    if (this->center_px != other.center_px) {
      return false;
    }
    if (this->center_camera != other.center_camera) {
      return false;
    }
    if (this->has_3d != other.has_3d) {
      return false;
    }
    if (this->outline != other.outline) {
      return false;
    }
    return true;
  }
  bool operator!=(const Shape_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Shape_

// alias to use template instance with default allocator
using Shape =
  pennair_vision_msgs::msg::Shape_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pennair_vision_msgs

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE__STRUCT_HPP_
