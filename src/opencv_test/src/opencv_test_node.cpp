#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/highgui/highgui.hpp>
#include<lino_msgs/running_time.h>
int main( int argc, char **argv )
{
  ros::init( argc, argv, "pub_cam_node" );
  ros::NodeHandle n;
 
  // Open camera with CAMERA_INDEX (webcam is typically #0).
  const int CAMERA_INDEX = 0;
  cv::VideoCapture capture( CAMERA_INDEX ); //摄像头视频的读操作
  if( not capture.isOpened() )
  {
    ROS_ERROR_STREAM(
      "Failed to open camera with index " << CAMERA_INDEX << "!"
    );
    ros::shutdown();
  }
  //1 捕获视频
 
  //2 创建ROS中图像的发布者
  // ros::NodeHandle nh;
  image_transport::ImageTransport it( n ); 
  image_transport::Publisher pub_image = it.advertise( "camera", 1 );
  ros::Publisher  time_pub =n.advertise<lino_msgs::running_time>("running_time",10);
  ros::Time right_now = ros::Time::now();
  //cv_bridge功能包提供了ROS图像和OpenCV图像转换的接口，建立了一座桥梁
  cv_bridge::CvImagePtr frame = boost::make_shared< cv_bridge::CvImage >();
  frame->encoding = sensor_msgs::image_encodings::BGR8;
 lino_msgs::running_time tt;
  while( ros::ok() ) {
    capture >> frame->image; //流的转换
    
    if( frame->image.empty() )
    {
      ROS_ERROR_STREAM( "Failed to capture frame!" );
      ros::shutdown();
    }
    //打成ROS数据包
    frame->header.stamp = ros::Time::now();
    pub_image.publish( frame->toImageMsg() );
    time_pub.publish(tt);
    cv::waitKey( 1 );//opencv刷新图像 3ms
    ros::spinOnce();
  }
 
  capture.release();  //释放流
  return EXIT_SUCCESS;
}