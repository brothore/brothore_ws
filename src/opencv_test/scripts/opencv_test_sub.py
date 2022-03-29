#!/usr/bin/env python
from __future__ import print_function

import roslib
# roslib.load_manifest('my_package')
import sys
import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import threading

# cv_showup = CvBridge()
def thread_job():
    rospy.spin()
class image_converter:

  def __init__(self):
    # self.image_pub = rospy.Publisher("image_topic_2",Image)

    self.bridge = CvBridge()
    self.image_sub = rospy.Subscriber("/detections_objects_topic",Image,self.callback)
    # self.image_sub = rospy.Subscriber("camera",Image,self.callback)

  def callback(self,data):
    try:
      cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    except CvBridgeError as e:
      print(e)

    (rows,cols,channels) = cv_image.shape
    if cols > 60 and rows > 60 :
      cv2.circle(cv_image, (50,50), 10, 255)
    global cv_showup 
    cv_showup = cv_image
    # cv2.imshow("Image window", cv_showup)
    # cv2.waitKey(3)
    # return cv_image

    # try:
    #   self.image_pub.publish(self.bridge.cv2_to_imgmsg(cv_image, "bgr8"))
    # except CvBridgeError as e:
    #   print(e)

def main(args):
  ic = image_converter()
  rospy.init_node('image_converter', anonymous=True)
#   cv_show = ic.callback
#   print(cv_show)
  
  try:
    add_thread = threading.Thread(target = thread_job)
    add_thread.start()
    # cv2.imshow("Image window", cv_showup)
    # cv2.waitKey(3)
  except KeyboardInterrupt:
    print("Shutting down")
  print(1)
#   cv2.destroyAllWindows()

if __name__ == '__main__':
    main(sys.argv)