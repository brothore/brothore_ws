; Auto-generated. Do not edit!


(cl:in-package lino_msgs-msg)


;//! \htmlinclude wheel_speed.msg.html

(cl:defclass <wheel_speed> (roslisp-msg-protocol:ros-message)
  ((L1
    :reader L1
    :initarg :L1
    :type cl:float
    :initform 0.0)
   (L2
    :reader L2
    :initarg :L2
    :type cl:float
    :initform 0.0)
   (L3
    :reader L3
    :initarg :L3
    :type cl:float
    :initform 0.0)
   (R1
    :reader R1
    :initarg :R1
    :type cl:float
    :initform 0.0)
   (R2
    :reader R2
    :initarg :R2
    :type cl:float
    :initform 0.0)
   (R3
    :reader R3
    :initarg :R3
    :type cl:float
    :initform 0.0)
   (L_SPEED
    :reader L_SPEED
    :initarg :L_SPEED
    :type cl:float
    :initform 0.0)
   (R_SPEED
    :reader R_SPEED
    :initarg :R_SPEED
    :type cl:float
    :initform 0.0)
   (L1_PID
    :reader L1_PID
    :initarg :L1_PID
    :type cl:float
    :initform 0.0)
   (L2_PID
    :reader L2_PID
    :initarg :L2_PID
    :type cl:float
    :initform 0.0)
   (L3_PID
    :reader L3_PID
    :initarg :L3_PID
    :type cl:float
    :initform 0.0)
   (R1_PID
    :reader R1_PID
    :initarg :R1_PID
    :type cl:float
    :initform 0.0)
   (R2_PID
    :reader R2_PID
    :initarg :R2_PID
    :type cl:float
    :initform 0.0)
   (R3_PID
    :reader R3_PID
    :initarg :R3_PID
    :type cl:float
    :initform 0.0))
)

(cl:defclass wheel_speed (<wheel_speed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <wheel_speed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'wheel_speed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lino_msgs-msg:<wheel_speed> is deprecated: use lino_msgs-msg:wheel_speed instead.")))

(cl:ensure-generic-function 'L1-val :lambda-list '(m))
(cl:defmethod L1-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L1-val is deprecated.  Use lino_msgs-msg:L1 instead.")
  (L1 m))

(cl:ensure-generic-function 'L2-val :lambda-list '(m))
(cl:defmethod L2-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L2-val is deprecated.  Use lino_msgs-msg:L2 instead.")
  (L2 m))

(cl:ensure-generic-function 'L3-val :lambda-list '(m))
(cl:defmethod L3-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L3-val is deprecated.  Use lino_msgs-msg:L3 instead.")
  (L3 m))

(cl:ensure-generic-function 'R1-val :lambda-list '(m))
(cl:defmethod R1-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R1-val is deprecated.  Use lino_msgs-msg:R1 instead.")
  (R1 m))

(cl:ensure-generic-function 'R2-val :lambda-list '(m))
(cl:defmethod R2-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R2-val is deprecated.  Use lino_msgs-msg:R2 instead.")
  (R2 m))

(cl:ensure-generic-function 'R3-val :lambda-list '(m))
(cl:defmethod R3-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R3-val is deprecated.  Use lino_msgs-msg:R3 instead.")
  (R3 m))

(cl:ensure-generic-function 'L_SPEED-val :lambda-list '(m))
(cl:defmethod L_SPEED-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L_SPEED-val is deprecated.  Use lino_msgs-msg:L_SPEED instead.")
  (L_SPEED m))

(cl:ensure-generic-function 'R_SPEED-val :lambda-list '(m))
(cl:defmethod R_SPEED-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R_SPEED-val is deprecated.  Use lino_msgs-msg:R_SPEED instead.")
  (R_SPEED m))

(cl:ensure-generic-function 'L1_PID-val :lambda-list '(m))
(cl:defmethod L1_PID-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L1_PID-val is deprecated.  Use lino_msgs-msg:L1_PID instead.")
  (L1_PID m))

(cl:ensure-generic-function 'L2_PID-val :lambda-list '(m))
(cl:defmethod L2_PID-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L2_PID-val is deprecated.  Use lino_msgs-msg:L2_PID instead.")
  (L2_PID m))

(cl:ensure-generic-function 'L3_PID-val :lambda-list '(m))
(cl:defmethod L3_PID-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L3_PID-val is deprecated.  Use lino_msgs-msg:L3_PID instead.")
  (L3_PID m))

(cl:ensure-generic-function 'R1_PID-val :lambda-list '(m))
(cl:defmethod R1_PID-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R1_PID-val is deprecated.  Use lino_msgs-msg:R1_PID instead.")
  (R1_PID m))

(cl:ensure-generic-function 'R2_PID-val :lambda-list '(m))
(cl:defmethod R2_PID-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R2_PID-val is deprecated.  Use lino_msgs-msg:R2_PID instead.")
  (R2_PID m))

(cl:ensure-generic-function 'R3_PID-val :lambda-list '(m))
(cl:defmethod R3_PID-val ((m <wheel_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R3_PID-val is deprecated.  Use lino_msgs-msg:R3_PID instead.")
  (R3_PID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <wheel_speed>) ostream)
  "Serializes a message object of type '<wheel_speed>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L_SPEED))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R_SPEED))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L1_PID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L2_PID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L3_PID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R1_PID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R2_PID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R3_PID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <wheel_speed>) istream)
  "Deserializes a message object of type '<wheel_speed>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L3) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R3) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L_SPEED) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R_SPEED) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L1_PID) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L2_PID) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L3_PID) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R1_PID) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R2_PID) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R3_PID) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<wheel_speed>)))
  "Returns string type for a message object of type '<wheel_speed>"
  "lino_msgs/wheel_speed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'wheel_speed)))
  "Returns string type for a message object of type 'wheel_speed"
  "lino_msgs/wheel_speed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<wheel_speed>)))
  "Returns md5sum for a message object of type '<wheel_speed>"
  "dcc44326156228f397c3cb547e1a862c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'wheel_speed)))
  "Returns md5sum for a message object of type 'wheel_speed"
  "dcc44326156228f397c3cb547e1a862c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<wheel_speed>)))
  "Returns full string definition for message of type '<wheel_speed>"
  (cl:format cl:nil "float32 L1~%float32 L2~%float32 L3~%float32 R1~%float32 R2~%float32 R3~%float32 L_SPEED~%float32 R_SPEED~%float32 L1_PID~%float32 L2_PID~%float32 L3_PID~%float32 R1_PID~%float32 R2_PID~%float32 R3_PID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'wheel_speed)))
  "Returns full string definition for message of type 'wheel_speed"
  (cl:format cl:nil "float32 L1~%float32 L2~%float32 L3~%float32 R1~%float32 R2~%float32 R3~%float32 L_SPEED~%float32 R_SPEED~%float32 L1_PID~%float32 L2_PID~%float32 L3_PID~%float32 R1_PID~%float32 R2_PID~%float32 R3_PID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <wheel_speed>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <wheel_speed>))
  "Converts a ROS message object to a list"
  (cl:list 'wheel_speed
    (cl:cons ':L1 (L1 msg))
    (cl:cons ':L2 (L2 msg))
    (cl:cons ':L3 (L3 msg))
    (cl:cons ':R1 (R1 msg))
    (cl:cons ':R2 (R2 msg))
    (cl:cons ':R3 (R3 msg))
    (cl:cons ':L_SPEED (L_SPEED msg))
    (cl:cons ':R_SPEED (R_SPEED msg))
    (cl:cons ':L1_PID (L1_PID msg))
    (cl:cons ':L2_PID (L2_PID msg))
    (cl:cons ':L3_PID (L3_PID msg))
    (cl:cons ':R1_PID (R1_PID msg))
    (cl:cons ':R2_PID (R2_PID msg))
    (cl:cons ':R3_PID (R3_PID msg))
))
