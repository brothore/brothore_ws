;; Auto-generated. Do not edit!


(when (boundp 'lino_msgs::car_param)
  (if (not (find-package "LINO_MSGS"))
    (make-package "LINO_MSGS"))
  (shadow 'car_param (find-package "LINO_MSGS")))
(unless (find-package "LINO_MSGS::CAR_PARAM")
  (make-package "LINO_MSGS::CAR_PARAM"))

(in-package "ROS")
;;//! \htmlinclude car_param.msg.html


(defclass lino_msgs::car_param
  :super ros::object
  :slots (_R_wheel _W_car _L_car _Reset_car _out_time ))

(defmethod lino_msgs::car_param
  (:init
   (&key
    ((:R_wheel __R_wheel) 0.0)
    ((:W_car __W_car) 0.0)
    ((:L_car __L_car) 0.0)
    ((:Reset_car __Reset_car) 0.0)
    ((:out_time __out_time) 0)
    )
   (send-super :init)
   (setq _R_wheel (float __R_wheel))
   (setq _W_car (float __W_car))
   (setq _L_car (float __L_car))
   (setq _Reset_car (float __Reset_car))
   (setq _out_time (round __out_time))
   self)
  (:R_wheel
   (&optional __R_wheel)
   (if __R_wheel (setq _R_wheel __R_wheel)) _R_wheel)
  (:W_car
   (&optional __W_car)
   (if __W_car (setq _W_car __W_car)) _W_car)
  (:L_car
   (&optional __L_car)
   (if __L_car (setq _L_car __L_car)) _L_car)
  (:Reset_car
   (&optional __Reset_car)
   (if __Reset_car (setq _Reset_car __Reset_car)) _Reset_car)
  (:out_time
   (&optional __out_time)
   (if __out_time (setq _out_time __out_time)) _out_time)
  (:serialization-length
   ()
   (+
    ;; float32 _R_wheel
    4
    ;; float32 _W_car
    4
    ;; float32 _L_car
    4
    ;; float32 _Reset_car
    4
    ;; int32 _out_time
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _R_wheel
       (sys::poke _R_wheel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _W_car
       (sys::poke _W_car (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L_car
       (sys::poke _L_car (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Reset_car
       (sys::poke _Reset_car (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _out_time
       (write-long _out_time s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _R_wheel
     (setq _R_wheel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _W_car
     (setq _W_car (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L_car
     (setq _L_car (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Reset_car
     (setq _Reset_car (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _out_time
     (setq _out_time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lino_msgs::car_param :md5sum-) "3ea72a41c2a9f150b8f2e47b164a570d")
(setf (get lino_msgs::car_param :datatype-) "lino_msgs/car_param")
(setf (get lino_msgs::car_param :definition-)
      "float32 R_wheel
float32 W_car
float32 L_car
float32 Reset_car
int32 out_time

")



(provide :lino_msgs/car_param "3ea72a41c2a9f150b8f2e47b164a570d")


