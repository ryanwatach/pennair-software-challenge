#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to pennair_vision_msgs__msg__Shape
/// One detected shape.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Shape {
    /// "triangle", "circle", "shape (clipped)", ...
    pub label: std::string::String,

    /// traced area in pixels
    pub area_px: f64,

    /// touches the frame border, so only partly visible
    pub clipped: bool,

    /// centroid in pixels (z unused)
    pub center_px: geometry_msgs::msg::Point,

    /// centroid as X,Y,Z inches in the camera frame
    pub center_camera: geometry_msgs::msg::Point,

    /// false when no depth was available
    pub has_3d: bool,

    /// traced contour, pixel coords (z unused)
    pub outline: geometry_msgs::msg::Polygon,

}



impl Default for Shape {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Shape::default())
  }
}

impl rosidl_runtime_rs::Message for Shape {
  type RmwMsg = super::msg::rmw::Shape;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        label: msg.label.as_str().into(),
        area_px: msg.area_px,
        clipped: msg.clipped,
        center_px: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.center_px)).into_owned(),
        center_camera: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.center_camera)).into_owned(),
        has_3d: msg.has_3d,
        outline: geometry_msgs::msg::Polygon::into_rmw_message(std::borrow::Cow::Owned(msg.outline)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        label: msg.label.as_str().into(),
      area_px: msg.area_px,
      clipped: msg.clipped,
        center_px: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.center_px)).into_owned(),
        center_camera: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.center_camera)).into_owned(),
      has_3d: msg.has_3d,
        outline: geometry_msgs::msg::Polygon::into_rmw_message(std::borrow::Cow::Borrowed(&msg.outline)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      label: msg.label.to_string(),
      area_px: msg.area_px,
      clipped: msg.clipped,
      center_px: geometry_msgs::msg::Point::from_rmw_message(msg.center_px),
      center_camera: geometry_msgs::msg::Point::from_rmw_message(msg.center_camera),
      has_3d: msg.has_3d,
      outline: geometry_msgs::msg::Polygon::from_rmw_message(msg.outline),
    }
  }
}


// Corresponds to pennair_vision_msgs__msg__ShapeArray
/// All shapes found in one frame.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShapeArray {
    /// stamp/frame_id copied from the source image
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub shapes: Vec<super::msg::Shape>,

    /// scene depth used for the 3D centers
    pub depth_inches: f64,

    /// false before the circle has ever been seen
    pub depth_valid: bool,

}



impl Default for ShapeArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ShapeArray::default())
  }
}

impl rosidl_runtime_rs::Message for ShapeArray {
  type RmwMsg = super::msg::rmw::ShapeArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        shapes: msg.shapes
          .into_iter()
          .map(|elem| super::msg::Shape::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        depth_inches: msg.depth_inches,
        depth_valid: msg.depth_valid,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        shapes: msg.shapes
          .iter()
          .map(|elem| super::msg::Shape::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      depth_inches: msg.depth_inches,
      depth_valid: msg.depth_valid,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      shapes: msg.shapes
          .into_iter()
          .map(super::msg::Shape::from_rmw_message)
          .collect(),
      depth_inches: msg.depth_inches,
      depth_valid: msg.depth_valid,
    }
  }
}


