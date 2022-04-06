import numpy as np
from matplotlib import pyplot as plt
import cv2
#碌梅脫脙卤脢录脟卤戮脛脷脰脙脡茫脧帽脥路拢卢脣霉脪脭虏脦脢媒脦陋0拢卢脠莽鹿没脫脨脝盲脣没碌脛脡茫脧帽脥路驴脡脪脭碌梅脮没虏脦脢媒脦陋1拢卢2
cap=cv2.VideoCapture(0)
# cap.set(3, 256)  #640
# cap.set(4, 192)  #480
# DefaultWidth=640
# DefaultHeight=480
DefaultWidth=256
DefaultHeight=192
while True:
 #麓脫脡茫脧帽脥路露脕脠隆脥录脝卢
 sucess,img=cap.read()
 img=cv2.resize(img,(DefaultWidth,DefaultHeight))
 #脳陋脦陋禄脪露脠脥录脝卢
 color=cv2.cvtColor(img,cv2.IMREAD_COLOR)
 #脧脭脢戮脡茫脧帽脥路拢卢卤鲁戮掳脢脟虏脢脡芦隆拢
 cv2.imshow("img",color)
 #卤拢鲁脰禄颅脙忙碌脛鲁脰脨酶隆拢
 k=cv2.waitKey(1)
 if k == 27:
  #脥篓鹿媒esc录眉脥脣鲁枚脡茫脧帽
  cv2.destroyAllWindows()
  break

#鹿脴卤脮脡茫脧帽脥路
cap.release()
