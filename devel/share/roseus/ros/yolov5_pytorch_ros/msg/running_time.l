;; Auto-generated. Do not edit!


(when (boundp 'yolov5_pytorch_ros::running_time)
  (if (not (find-package "YOLOV5_PYTORCH_ROS"))
    (make-package "YOLOV5_PYTORCH_ROS"))
  (shadow 'running_time (find-package "YOLOV5_PYTORCH_ROS")))
(unless (find-package "YOLOV5_PYTORCH_ROS::RUNNING_TIME")
  (make-package "YOLOV5_PYTORCH_ROS::RUNNING_TIME"))

(in-package "ROS")
;;//! \htmlinclude running_time.msg.html


(defclass yolov5_pytorch_ros::running_time
  :super ros::object
  :slots (_time0_pub _time0_sub _time1_pub _time1_sub _time2_pub _time2_sub ))

(defmethod yolov5_pytorch_ros::running_time
  (:init
   (&key
    ((:time0_pub __time0_pub) 0.0)
    ((:time0_sub __time0_sub) 0.0)
    ((:time1_pub __time1_pub) 0.0)
    ((:time1_sub __time1_sub) 0.0)
    ((:time2_pub __time2_pub) 0.0)
    ((:time2_sub __time2_sub) 0.0)
    )
   (send-super :init)
   (setq _time0_pub (float __time0_pub))
   (setq _time0_sub (float __time0_sub))
   (setq _time1_pub (float __time1_pub))
   (setq _time1_sub (float __time1_sub))
   (setq _time2_pub (float __time2_pub))
   (setq _time2_sub (float __time2_sub))
   self)
  (:time0_pub
   (&optional __time0_pub)
   (if __time0_pub (setq _time0_pub __time0_pub)) _time0_pub)
  (:time0_sub
   (&optional __time0_sub)
   (if __time0_sub (setq _time0_sub __time0_sub)) _time0_sub)
  (:time1_pub
   (&optional __time1_pub)
   (if __time1_pub (setq _time1_pub __time1_pub)) _time1_pub)
  (:time1_sub
   (&optional __time1_sub)
   (if __time1_sub (setq _time1_sub __time1_sub)) _time1_sub)
  (:time2_pub
   (&optional __time2_pub)
   (if __time2_pub (setq _time2_pub __time2_pub)) _time2_pub)
  (:time2_sub
   (&optional __time2_sub)
   (if __time2_sub (setq _time2_sub __time2_sub)) _time2_sub)
  (:serialization-length
   ()
   (+
    ;; float64 _time0_pub
    8
    ;; float64 _time0_sub
    8
    ;; float64 _time1_pub
    8
    ;; float64 _time1_sub
    8
    ;; float64 _time2_pub
    8
    ;; float64 _time2_sub
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time0_pub
       (sys::poke _time0_pub (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time0_sub
       (sys::poke _time0_sub (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time1_pub
       (sys::poke _time1_pub (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time1_sub
       (sys::poke _time1_sub (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time2_pub
       (sys::poke _time2_pub (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time2_sub
       (sys::poke _time2_sub (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time0_pub
     (setq _time0_pub (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time0_sub
     (setq _time0_sub (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time1_pub
     (setq _time1_pub (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time1_sub
     (setq _time1_sub (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time2_pub
     (setq _time2_pub (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time2_sub
     (setq _time2_sub (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get yolov5_pytorch_ros::running_time :md5sum-) "fba7101da493706fc2932a90aa6f2991")
(setf (get yolov5_pytorch_ros::running_time :datatype-) "yolov5_pytorch_ros/running_time")
(setf (get yolov5_pytorch_ros::running_time :definition-)
      "float64 time0_pub
float64 time0_sub
float64 time1_pub
float64 time1_sub
float64 time2_pub
float64 time2_sub


")



(provide :yolov5_pytorch_ros/running_time "fba7101da493706fc2932a90aa6f2991")


