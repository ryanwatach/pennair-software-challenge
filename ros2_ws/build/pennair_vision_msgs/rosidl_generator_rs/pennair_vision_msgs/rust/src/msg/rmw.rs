#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "pennair_vision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pennair_vision_msgs__msg__Shape() -> *const std::ffi::c_void;
}

#[link(name = "pennair_vision_msgs__rosidl_generator_c")]
extern "C" {
    fn pennair_vision_msgs__msg__Shape__init(msg: *mut Shape) -> bool;
    fn pennair_vision_msgs__msg__Shape__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Shape>, size: usize) -> bool;
    fn pennair_vision_msgs__msg__Shape__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Shape>);
    fn pennair_vision_msgs__msg__Shape__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Shape>, out_seq: *mut rosidl_runtime_rs::Sequence<Shape>) -> bool;
}

// Corresponds to pennair_vision_msgs__msg__Shape
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// One detected shape.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Shape {
    /// "triangle", "circle", "shape (clipped)", ...
    pub label: rosidl_runtime_rs::String,

    /// traced area in pixels
    pub area_px: f64,

    /// touches the frame border, so only partly visible
    pub clipped: bool,

    /// centroid in pixels (z unused)
    pub center_px: geometry_msgs::msg::rmw::Point,

    /// centroid as X,Y,Z inches in the camera frame
    pub center_camera: geometry_msgs::msg::rmw::Point,

    /// false when no depth was available
    pub has_3d: bool,

    /// traced contour, pixel coords (z unused)
    pub outline: geometry_msgs::msg::rmw::Polygon,

}



impl Default for Shape {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pennair_vision_msgs__msg__Shape__init(&mut msg as *mut _) {
        panic!("Call to pennair_vision_msgs__msg__Shape__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Shape {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pennair_vision_msgs__msg__Shape__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pennair_vision_msgs__msg__Shape__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pennair_vision_msgs__msg__Shape__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Shape {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Shape where Self: Sized {
  const TYPE_NAME: &'static str = "pennair_vision_msgs/msg/Shape";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pennair_vision_msgs__msg__Shape() }
  }
}


#[link(name = "pennair_vision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pennair_vision_msgs__msg__ShapeArray() -> *const std::ffi::c_void;
}

#[link(name = "pennair_vision_msgs__rosidl_generator_c")]
extern "C" {
    fn pennair_vision_msgs__msg__ShapeArray__init(msg: *mut ShapeArray) -> bool;
    fn pennair_vision_msgs__msg__ShapeArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShapeArray>, size: usize) -> bool;
    fn pennair_vision_msgs__msg__ShapeArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShapeArray>);
    fn pennair_vision_msgs__msg__ShapeArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShapeArray>, out_seq: *mut rosidl_runtime_rs::Sequence<ShapeArray>) -> bool;
}

// Corresponds to pennair_vision_msgs__msg__ShapeArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// All shapes found in one frame.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShapeArray {
    /// stamp/frame_id copied from the source image
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub shapes: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Shape>,

    /// scene depth used for the 3D centers
    pub depth_inches: f64,

    /// false before the circle has ever been seen
    pub depth_valid: bool,

}



impl Default for ShapeArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pennair_vision_msgs__msg__ShapeArray__init(&mut msg as *mut _) {
        panic!("Call to pennair_vision_msgs__msg__ShapeArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShapeArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pennair_vision_msgs__msg__ShapeArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pennair_vision_msgs__msg__ShapeArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pennair_vision_msgs__msg__ShapeArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShapeArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShapeArray where Self: Sized {
  const TYPE_NAME: &'static str = "pennair_vision_msgs/msg/ShapeArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pennair_vision_msgs__msg__ShapeArray() }
  }
}


