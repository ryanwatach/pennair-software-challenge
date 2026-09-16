// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pennair_vision_msgs/msg/detail/shape_array__functions.h"
#include "pennair_vision_msgs/msg/detail/shape_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pennair_vision_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ShapeArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pennair_vision_msgs::msg::ShapeArray(_init);
}

void ShapeArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pennair_vision_msgs::msg::ShapeArray *>(message_memory);
  typed_message->~ShapeArray();
}

size_t size_function__ShapeArray__shapes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<pennair_vision_msgs::msg::Shape> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ShapeArray__shapes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<pennair_vision_msgs::msg::Shape> *>(untyped_member);
  return &member[index];
}

void * get_function__ShapeArray__shapes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<pennair_vision_msgs::msg::Shape> *>(untyped_member);
  return &member[index];
}

void fetch_function__ShapeArray__shapes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const pennair_vision_msgs::msg::Shape *>(
    get_const_function__ShapeArray__shapes(untyped_member, index));
  auto & value = *reinterpret_cast<pennair_vision_msgs::msg::Shape *>(untyped_value);
  value = item;
}

void assign_function__ShapeArray__shapes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<pennair_vision_msgs::msg::Shape *>(
    get_function__ShapeArray__shapes(untyped_member, index));
  const auto & value = *reinterpret_cast<const pennair_vision_msgs::msg::Shape *>(untyped_value);
  item = value;
}

void resize_function__ShapeArray__shapes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<pennair_vision_msgs::msg::Shape> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ShapeArray_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs::msg::ShapeArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "shapes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<pennair_vision_msgs::msg::Shape>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs::msg::ShapeArray, shapes),  // bytes offset in struct
    nullptr,  // default value
    size_function__ShapeArray__shapes,  // size() function pointer
    get_const_function__ShapeArray__shapes,  // get_const(index) function pointer
    get_function__ShapeArray__shapes,  // get(index) function pointer
    fetch_function__ShapeArray__shapes,  // fetch(index, &value) function pointer
    assign_function__ShapeArray__shapes,  // assign(index, value) function pointer
    resize_function__ShapeArray__shapes  // resize(index) function pointer
  },
  {
    "depth_inches",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs::msg::ShapeArray, depth_inches),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "depth_valid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs::msg::ShapeArray, depth_valid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ShapeArray_message_members = {
  "pennair_vision_msgs::msg",  // message namespace
  "ShapeArray",  // message name
  4,  // number of fields
  sizeof(pennair_vision_msgs::msg::ShapeArray),
  false,  // has_any_key_member_
  ShapeArray_message_member_array,  // message members
  ShapeArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ShapeArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ShapeArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ShapeArray_message_members,
  get_message_typesupport_handle_function,
  &pennair_vision_msgs__msg__ShapeArray__get_type_hash,
  &pennair_vision_msgs__msg__ShapeArray__get_type_description,
  &pennair_vision_msgs__msg__ShapeArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace pennair_vision_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pennair_vision_msgs::msg::ShapeArray>()
{
  return &::pennair_vision_msgs::msg::rosidl_typesupport_introspection_cpp::ShapeArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pennair_vision_msgs, msg, ShapeArray)() {
  return &::pennair_vision_msgs::msg::rosidl_typesupport_introspection_cpp::ShapeArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
