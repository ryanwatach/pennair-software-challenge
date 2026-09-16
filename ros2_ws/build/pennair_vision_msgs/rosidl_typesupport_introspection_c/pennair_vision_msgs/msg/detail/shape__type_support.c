// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pennair_vision_msgs/msg/detail/shape__rosidl_typesupport_introspection_c.h"
#include "pennair_vision_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pennair_vision_msgs/msg/detail/shape__functions.h"
#include "pennair_vision_msgs/msg/detail/shape__struct.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `center_px`
// Member `center_camera`
#include "geometry_msgs/msg/point.h"
// Member `center_px`
// Member `center_camera`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `outline`
#include "geometry_msgs/msg/polygon.h"
// Member `outline`
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pennair_vision_msgs__msg__Shape__init(message_memory);
}

void pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_fini_function(void * message_memory)
{
  pennair_vision_msgs__msg__Shape__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_member_array[7] = {
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "area_px",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, area_px),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "clipped",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, clipped),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center_px",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, center_px),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center_camera",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, center_camera),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "has_3d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, has_3d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "outline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pennair_vision_msgs__msg__Shape, outline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_members = {
  "pennair_vision_msgs__msg",  // message namespace
  "Shape",  // message name
  7,  // number of fields
  sizeof(pennair_vision_msgs__msg__Shape),
  false,  // has_any_key_member_
  pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_member_array,  // message members
  pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_init_function,  // function to initialize message memory (memory has to be allocated)
  pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_type_support_handle = {
  0,
  &pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_members,
  get_message_typesupport_handle_function,
  &pennair_vision_msgs__msg__Shape__get_type_hash,
  &pennair_vision_msgs__msg__Shape__get_type_description,
  &pennair_vision_msgs__msg__Shape__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pennair_vision_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pennair_vision_msgs, msg, Shape)() {
  pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  if (!pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_type_support_handle.typesupport_identifier) {
    pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pennair_vision_msgs__msg__Shape__rosidl_typesupport_introspection_c__Shape_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
