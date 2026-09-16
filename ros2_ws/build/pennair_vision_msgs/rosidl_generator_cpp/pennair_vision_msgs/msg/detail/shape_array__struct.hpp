// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pennair_vision_msgs/msg/shape_array.hpp"


#ifndef PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__STRUCT_HPP_
#define PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'shapes'
#include "pennair_vision_msgs/msg/detail/shape__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pennair_vision_msgs__msg__ShapeArray __attribute__((deprecated))
#else
# define DEPRECATED__pennair_vision_msgs__msg__ShapeArray __declspec(deprecated)
#endif

namespace pennair_vision_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ShapeArray_
{
  using Type = ShapeArray_<ContainerAllocator>;

  explicit ShapeArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth_inches = 0.0;
      this->depth_valid = false;
    }
  }

  explicit ShapeArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth_inches = 0.0;
      this->depth_valid = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _shapes_type =
    std::vector<pennair_vision_msgs::msg::Shape_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pennair_vision_msgs::msg::Shape_<ContainerAllocator>>>;
  _shapes_type shapes;
  using _depth_inches_type =
    double;
  _depth_inches_type depth_inches;
  using _depth_valid_type =
    bool;
  _depth_valid_type depth_valid;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__shapes(
    const std::vector<pennair_vision_msgs::msg::Shape_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pennair_vision_msgs::msg::Shape_<ContainerAllocator>>> & _arg)
  {
    this->shapes = _arg;
    return *this;
  }
  Type & set__depth_inches(
    const double & _arg)
  {
    this->depth_inches = _arg;
    return *this;
  }
  Type & set__depth_valid(
    const bool & _arg)
  {
    this->depth_valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pennair_vision_msgs__msg__ShapeArray
    std::shared_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pennair_vision_msgs__msg__ShapeArray
    std::shared_ptr<pennair_vision_msgs::msg::ShapeArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ShapeArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->shapes != other.shapes) {
      return false;
    }
    if (this->depth_inches != other.depth_inches) {
      return false;
    }
    if (this->depth_valid != other.depth_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const ShapeArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ShapeArray_

// alias to use template instance with default allocator
using ShapeArray =
  pennair_vision_msgs::msg::ShapeArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pennair_vision_msgs

#endif  // PENNAIR_VISION_MSGS__MSG__DETAIL__SHAPE_ARRAY__STRUCT_HPP_
