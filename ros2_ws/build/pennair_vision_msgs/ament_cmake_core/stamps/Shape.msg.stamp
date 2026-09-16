# One detected shape.
string    label             # "triangle", "circle", "shape (clipped)", ...
float64   area_px           # traced area in pixels
bool      clipped           # touches the frame border, so only partly visible

geometry_msgs/Point center_px      # centroid in pixels (z unused)
geometry_msgs/Point center_camera  # centroid as X,Y,Z inches in the camera frame
bool                has_3d         # false when no depth was available

geometry_msgs/Polygon outline      # traced contour, pixel coords (z unused)
