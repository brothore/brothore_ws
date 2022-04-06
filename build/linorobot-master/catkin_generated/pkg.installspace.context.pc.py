# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;rospy;tf2;tf2_ros;nav_msgs;lino_msgs;geometry_msgs;sensor_msgs;std_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-llinorobot".split(';') if "-llinorobot" != "" else []
PROJECT_NAME = "linorobot"
PROJECT_SPACE_DIR = "/home/ubuntu/linorobot_ws/install"
PROJECT_VERSION = "1.4.1"
