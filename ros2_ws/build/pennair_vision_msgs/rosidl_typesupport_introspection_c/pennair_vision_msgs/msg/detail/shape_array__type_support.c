// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pennair_vision_msgs:msg/ShapeArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pennair_vision_msgs/msg/detail/shape_array__rosidl_typesupport_introspection_c.h"
#include "pennair_vision_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pennair_vision_msgs/msg/detail/shape_array__functions.h"
#include "pennair_vision_msgs/msg/detail/shape_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `shapes`
#include "pennair_vision_msgs/msg/shape.h"
// Member `shapes`
#include "pennair_vision_msgs/msg/detail/shape__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pennair_vision_msgs__msg__ShapeArray__init(message_memory);
}

void pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_fini_function(void * message_memory)
{
  pennair_vision_msgs__msg__ShapeArray__fini(message_memory);
}

size_t pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__size_function__ShapeArray__shapes(
  const void * untyped_member)
{
  const pennair_vision_msgs__msg__Shape__Sequence * member =
    (const pennair_vision_msgs__msg__Shape__Sequence *)(untyped_member);
  return member->size;
}

const void * pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__get_const_function__ShapeArray__shapes(
  const void * untyped_member, size_t index)
{
  const pennair_vision_msgs__msg__Shape__Sequence * member =
    (const pennair_vision_msgs__msg__Shape__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__get_function__ShapeArray__shapes(
  void * untyped_member, size_t index)
{
  pennair_vision_msgs__msg__Shape__Sequence * member =
    (pennair_vision_msgs__msg__Shape__Sequence *)(untyped_member);
  return &member->data[index];
}

void pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__fetch_function__ShapeArray__shapes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const pennair_vision_msgs__msg__Shape * item =
    ((const pennair_vision_msgs__msg__Shape *)
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__get_const_function__ShapeArray__shapes(untyped_member, index));
  pennair_vision_msgs__msg__Shape * value =
    (pennair_vision_msgs__msg__Shape *)(untyped_value);
  *value = *item;
}

void pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__assign_function__ShapeArray__shapes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  pennair_vision_msgs__msg__Shape * item =
    ((pennair_vision_msgs__msg__Shape *)
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__get_function__ShapeArray__shapes(untyped_member, index));
  const pennair_vision_msgs__msg__Shape * value =
    (const pennair_vision_msgs__msg__Shape *)(untyped_value);
  *item = *value;
}

bool pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__resize_function__ShapeArray__shapes(
  void * untyped_member, size_t size)
{
  pennair_vision_msgs__msg__Shape__Sequence * member =
    (pennair_vision_msgs__msg__Shape__Sequence *)(untyped_member);
  pennair_vision_msgs__msg__Shape__Sequence__fini(member);
  return pennair_vision_msgs__msg__Shape__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__ShapeArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shapes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__ShapeArray, shapes),  // bytes offset in struct
    NULL,  // default value
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__size_function__ShapeArray__shapes,  // size() function pointer
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__get_const_function__ShapeArray__shapes,  // get_const(index) function pointer
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__get_function__ShapeArray__shapes,  // get(index) function pointer
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__fetch_function__ShapeArray__shapes,  // fetch(index, &value) function pointer
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__assign_function__ShapeArray__shapes,  // assign(index, value) function pointer
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__resize_function__ShapeArray__shapes  // resize(index) function pointer
  },
  {
    "depth_inches",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__ShapeArray, depth_inches),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "depth_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__ShapeArray, depth_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_members = {
  "pennair_vision_msgs__msg",  // message namespace
  "ShapeArray",  // message name
  4,  // number of fields
  sizeof(pennair_vision_msgs__msg__ShapeArray),
  false,  // has_any_key_member_
  pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_member_array,  // message members
  pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_init_function,  // function to initialize message memory (memory has to be allocated)
  pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_type_support_handle = {
  0,
  &pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_members,
  get_message_typesupport_handle_function,
  &pennair_vision_msgs__msg__ShapeArray__get_type_hash,
  &pennair_vision_msgs__msg__ShapeArray__get_type_description,
  &pennair_vision_msgs__msg__ShapeArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pennair_vision_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pennair_vision_msgs, msg, ShapeArray)() {
  pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pennair_vision_msgs, msg, Shape)();
  if (!pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_type_support_handle.typesupport_identifier) {
    pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pennair_vision_msgs__msg__ShapeArray__rosidl_typesupport_introspection_c__ShapeArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
