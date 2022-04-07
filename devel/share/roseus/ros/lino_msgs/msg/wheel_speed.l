;; Auto-generated. Do not edit!


(when (boundp 'lino_msgs::wheel_speed)
  (if (not (find-package "LINO_MSGS"))
    (make-package "LINO_MSGS"))
  (shadow 'wheel_speed (find-package "LINO_MSGS")))
(unless (find-package "LINO_MSGS::WHEEL_SPEED")
  (make-package "LINO_MSGS::WHEEL_SPEED"))

(in-package "ROS")
;;//! \htmlinclude wheel_speed.msg.html


(defclass lino_msgs::wheel_speed
  :super ros::object
  :slots (_L1 _L2 _L3 _R1 _R2 _R3 _L_SPEED _R_SPEED _L1_PID _L2_PID _L3_PID _R1_PID _R2_PID _R3_PID ))

(defmethod lino_msgs::wheel_speed
  (:init
   (&key
    ((:L1 __L1) 0.0)
    ((:L2 __L2) 0.0)
    ((:L3 __L3) 0.0)
    ((:R1 __R1) 0.0)
    ((:R2 __R2) 0.0)
    ((:R3 __R3) 0.0)
    ((:L_SPEED __L_SPEED) 0.0)
    ((:R_SPEED __R_SPEED) 0.0)
    ((:L1_PID __L1_PID) 0.0)
    ((:L2_PID __L2_PID) 0.0)
    ((:L3_PID __L3_PID) 0.0)
    ((:R1_PID __R1_PID) 0.0)
    ((:R2_PID __R2_PID) 0.0)
    ((:R3_PID __R3_PID) 0.0)
    )
   (send-super :init)
   (setq _L1 (float __L1))
   (setq _L2 (float __L2))
   (setq _L3 (float __L3))
   (setq _R1 (float __R1))
   (setq _R2 (float __R2))
   (setq _R3 (float __R3))
   (setq _L_SPEED (float __L_SPEED))
   (setq _R_SPEED (float __R_SPEED))
   (setq _L1_PID (float __L1_PID))
   (setq _L2_PID (float __L2_PID))
   (setq _L3_PID (float __L3_PID))
   (setq _R1_PID (float __R1_PID))
   (setq _R2_PID (float __R2_PID))
   (setq _R3_PID (float __R3_PID))
   self)
  (:L1
   (&optional __L1)
   (if __L1 (setq _L1 __L1)) _L1)
  (:L2
   (&optional __L2)
   (if __L2 (setq _L2 __L2)) _L2)
  (:L3
   (&optional __L3)
   (if __L3 (setq _L3 __L3)) _L3)
  (:R1
   (&optional __R1)
   (if __R1 (setq _R1 __R1)) _R1)
  (:R2
   (&optional __R2)
   (if __R2 (setq _R2 __R2)) _R2)
  (:R3
   (&optional __R3)
   (if __R3 (setq _R3 __R3)) _R3)
  (:L_SPEED
   (&optional __L_SPEED)
   (if __L_SPEED (setq _L_SPEED __L_SPEED)) _L_SPEED)
  (:R_SPEED
   (&optional __R_SPEED)
   (if __R_SPEED (setq _R_SPEED __R_SPEED)) _R_SPEED)
  (:L1_PID
   (&optional __L1_PID)
   (if __L1_PID (setq _L1_PID __L1_PID)) _L1_PID)
  (:L2_PID
   (&optional __L2_PID)
   (if __L2_PID (setq _L2_PID __L2_PID)) _L2_PID)
  (:L3_PID
   (&optional __L3_PID)
   (if __L3_PID (setq _L3_PID __L3_PID)) _L3_PID)
  (:R1_PID
   (&optional __R1_PID)
   (if __R1_PID (setq _R1_PID __R1_PID)) _R1_PID)
  (:R2_PID
   (&optional __R2_PID)
   (if __R2_PID (setq _R2_PID __R2_PID)) _R2_PID)
  (:R3_PID
   (&optional __R3_PID)
   (if __R3_PID (setq _R3_PID __R3_PID)) _R3_PID)
  (:serialization-length
   ()
   (+
    ;; float32 _L1
    4
    ;; float32 _L2
    4
    ;; float32 _L3
    4
    ;; float32 _R1
    4
    ;; float32 _R2
    4
    ;; float32 _R3
    4
    ;; float32 _L_SPEED
    4
    ;; float32 _R_SPEED
    4
    ;; float32 _L1_PID
    4
    ;; float32 _L2_PID
    4
    ;; float32 _L3_PID
    4
    ;; float32 _R1_PID
    4
    ;; float32 _R2_PID
    4
    ;; float32 _R3_PID
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _L1
       (sys::poke _L1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L2
       (sys::poke _L2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L3
       (sys::poke _L3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R1
       (sys::poke _R1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R2
       (sys::poke _R2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R3
       (sys::poke _R3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L_SPEED
       (sys::poke _L_SPEED (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R_SPEED
       (sys::poke _R_SPEED (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L1_PID
       (sys::poke _L1_PID (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L2_PID
       (sys::poke _L2_PID (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _L3_PID
       (sys::poke _L3_PID (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R1_PID
       (sys::poke _R1_PID (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R2_PID
       (sys::poke _R2_PID (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R3_PID
       (sys::poke _R3_PID (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _L1
     (setq _L1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L2
     (setq _L2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L3
     (setq _L3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R1
     (setq _R1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R2
     (setq _R2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R3
     (setq _R3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L_SPEED
     (setq _L_SPEED (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R_SPEED
     (setq _R_SPEED (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L1_PID
     (setq _L1_PID (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L2_PID
     (setq _L2_PID (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _L3_PID
     (setq _L3_PID (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R1_PID
     (setq _R1_PID (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R2_PID
     (setq _R2_PID (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R3_PID
     (setq _R3_PID (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lino_msgs::wheel_speed :md5sum-) "dcc44326156228f397c3cb547e1a862c")
(setf (get lino_msgs::wheel_speed :datatype-) "lino_msgs/wheel_speed")
(setf (get lino_msgs::wheel_speed :definition-)
      "float32 L1
float32 L2
float32 L3
float32 R1
float32 R2
float32 R3
float32 L_SPEED
float32 R_SPEED
float32 L1_PID
float32 L2_PID
float32 L3_PID
float32 R1_PID
float32 R2_PID
float32 R3_PID

")



(provide :lino_msgs/wheel_speed "dcc44326156228f397c3cb547e1a862c")


