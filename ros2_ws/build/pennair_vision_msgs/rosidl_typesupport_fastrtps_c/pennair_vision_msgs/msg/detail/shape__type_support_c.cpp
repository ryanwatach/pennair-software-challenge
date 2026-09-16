// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pennair_vision_msgs:msg/Shape.idl
// generated code does not contain a copyright notice
#include "pennair_vision_msgs/msg/detail/shape__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pennair_vision_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pennair_vision_msgs/msg/detail/shape__struct.h"
#include "pennair_vision_msgs/msg/detail/shape__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point__functions.h"  // center_camera, center_px
#include "geometry_msgs/msg/detail/polygon__functions.h"  // outline
#include "rosidl_runtime_c/string.h"  // label
#include "rosidl_runtime_c/string_functions.h"  // label

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
bool cdr_serialize_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
bool cdr_deserialize_geometry_msgs__msg__Point(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Point * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
bool cdr_serialize_key_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
bool cdr_serialize_geometry_msgs__msg__Polygon(
  const geometry_msgs__msg__Polygon * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
bool cdr_deserialize_geometry_msgs__msg__Polygon(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Polygon * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t get_serialized_size_geometry_msgs__msg__Polygon(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t max_serialized_size_geometry_msgs__msg__Polygon(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
bool cdr_serialize_key_geometry_msgs__msg__Polygon(
  const geometry_msgs__msg__Polygon * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Polygon(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Polygon(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pennair_vision_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Polygon)();


using _Shape__ros_msg_type = pennair_vision_msgs__msg__Shape;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
bool cdr_serialize_pennair_vision_msgs__msg__Shape(
  const pennair_vision_msgs__msg__Shape * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: label
  {
    const rosidl_runtime_c__String * str = &ros_message->label;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: area_px
  {
    cdr << ros_message->area_px;
  }

  // Field name: clipped
  {
    cdr << (ros_message->clipped ? true : false);
  }

  // Field name: center_px
  {
    cdr_serialize_geometry_msgs__msg__Point(
      &ros_message->center_px, cdr);
  }

  // Field name: center_camera
  {
    cdr_serialize_geometry_msgs__msg__Point(
      &ros_message->center_camera, cdr);
  }

  // Field name: has_3d
  {
    cdr << (ros_message->has_3d ? true : false);
  }

  // Field name: outline
  {
    cdr_serialize_geometry_msgs__msg__Polygon(
      &ros_message->outline, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
bool cdr_deserialize_pennair_vision_msgs__msg__Shape(
  eprosima::fastcdr::Cdr & cdr,
  pennair_vision_msgs__msg__Shape * ros_message)
{
  // Field name: label
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->label.data) {
      rosidl_runtime_c__String__init(&ros_message->label);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->label,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'label'\n");
      return false;
    }
  }

  // Field name: area_px
  {
    cdr >> ros_message->area_px;
  }

  // Field name: clipped
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipped = tmp ? true : false;
  }

  // Field name: center_px
  {
    cdr_deserialize_geometry_msgs__msg__Point(cdr, &ros_message->center_px);
  }

  // Field name: center_camera
  {
    cdr_deserialize_geometry_msgs__msg__Point(cdr, &ros_message->center_camera);
  }

  // Field name: has_3d
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->has_3d = tmp ? true : false;
  }

  // Field name: outline
  {
    cdr_deserialize_geometry_msgs__msg__Polygon(cdr, &ros_message->outline);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t get_serialized_size_pennair_vision_msgs__msg__Shape(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Shape__ros_msg_type * ros_message = static_cast<const _Shape__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: label
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->label.size + 1);

  // Field name: area_px
  {
    size_t item_size = sizeof(ros_message->area_px);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipped
  {
    size_t item_size = sizeof(ros_message->clipped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: center_px
  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->center_px), current_alignment);

  // Field name: center_camera
  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->center_camera), current_alignment);

  // Field name: has_3d
  {
    size_t item_size = sizeof(ros_message->has_3d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: outline
  current_alignment += get_serialized_size_geometry_msgs__msg__Polygon(
    &(ros_message->outline), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t max_serialized_size_pennair_vision_msgs__msg__Shape(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: label
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: area_px
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: clipped
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: center_px
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: center_camera
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: has_3d
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: outline
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Polygon(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pennair_vision_msgs__msg__Shape;
    is_plain =
      (
      offsetof(DataType, outline) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
bool cdr_serialize_key_pennair_vision_msgs__msg__Shape(
  const pennair_vision_msgs__msg__Shape * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: label
  {
    const rosidl_runtime_c__String * str = &ros_message->label;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: area_px
  {
    cdr << ros_message->area_px;
  }

  // Field name: clipped
  {
    cdr << (ros_message->clipped ? true : false);
  }

  // Field name: center_px
  {
    cdr_serialize_key_geometry_msgs__msg__Point(
      &ros_message->center_px, cdr);
  }

  // Field name: center_camera
  {
    cdr_serialize_key_geometry_msgs__msg__Point(
      &ros_message->center_camera, cdr);
  }

  // Field name: has_3d
  {
    cdr << (ros_message->has_3d ? true : false);
  }

  // Field name: outline
  {
    cdr_serialize_key_geometry_msgs__msg__Polygon(
      &ros_message->outline, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t get_serialized_size_key_pennair_vision_msgs__msg__Shape(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Shape__ros_msg_type * ros_message = static_cast<const _Shape__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: label
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->label.size + 1);

  // Field name: area_px
  {
    size_t item_size = sizeof(ros_message->area_px);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipped
  {
    size_t item_size = sizeof(ros_message->clipped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: center_px
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point(
    &(ros_message->center_px), current_alignment);

  // Field name: center_camera
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point(
    &(ros_message->center_camera), current_alignment);

  // Field name: has_3d
  {
    size_t item_size = sizeof(ros_message->has_3d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: outline
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Polygon(
    &(ros_message->outline), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pennair_vision_msgs
size_t max_serialized_size_key_pennair_vision_msgs__msg__Shape(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: label
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: area_px
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: clipped
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: center_px
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: center_camera
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: has_3d
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: outline
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Polygon(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pennair_vision_msgs__msg__Shape;
    is_plain =
      (
      offsetof(DataType, outline) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Shape__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const pennair_vision_msgs__msg__Shape * ros_message = static_cast<const pennair_vision_msgs__msg__Shape *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_pennair_vision_msgs__msg__Shape(ros_message, cdr);
}

static bool _Shape__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  pennair_vision_msgs__msg__Shape * ros_message = static_cast<pennair_vision_msgs__msg__Shape *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_pennair_vision_msgs__msg__Shape(cdr, ros_message);
}

static uint32_t _Shape__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pennair_vision_msgs__msg__Shape(
      untyped_ros_message, 0));
}

static size_t _Shape__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pennair_vision_msgs__msg__Shape(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Shape = {
  "pennair_vision_msgs::msg",
  "Shape",
  _Shape__cdr_serialize,
  _Shape__cdr_deserialize,
  _Shape__get_serialized_size,
  _Shape__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Shape__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Shape,
  get_message_typesupport_handle_function,
  &pennair_vision_msgs__msg__Shape__get_type_hash,
  &pennair_vision_msgs__msg__Shape__get_type_description,
  &pennair_vision_msgs__msg__Shape__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pennair_vision_msgs, msg, Shape)() {
  return &_Shape__type_support;
}

#if defined(__cplusplus)
}
#endif
