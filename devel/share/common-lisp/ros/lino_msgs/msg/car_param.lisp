; Auto-generated. Do not edit!


(cl:in-package lino_msgs-msg)


;//! \htmlinclude car_param.msg.html

(cl:defclass <car_param> (roslisp-msg-protocol:ros-message)
  ((R_wheel
    :reader R_wheel
    :initarg :R_wheel
    :type cl:float
    :initform 0.0)
   (W_car
    :reader W_car
    :initarg :W_car
    :type cl:float
    :initform 0.0)
   (L_car
    :reader L_car
    :initarg :L_car
    :type cl:float
    :initform 0.0)
   (Reset_car
    :reader Reset_car
    :initarg :Reset_car
    :type cl:float
    :initform 0.0)
   (out_time
    :reader out_time
    :initarg :out_time
    :type cl:integer
    :initform 0))
)

(cl:defclass car_param (<car_param>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <car_param>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'car_param)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lino_msgs-msg:<car_param> is deprecated: use lino_msgs-msg:car_param instead.")))

(cl:ensure-generic-function 'R_wheel-val :lambda-list '(m))
(cl:defmethod R_wheel-val ((m <car_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:R_wheel-val is deprecated.  Use lino_msgs-msg:R_wheel instead.")
  (R_wheel m))

(cl:ensure-generic-function 'W_car-val :lambda-list '(m))
(cl:defmethod W_car-val ((m <car_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:W_car-val is deprecated.  Use lino_msgs-msg:W_car instead.")
  (W_car m))

(cl:ensure-generic-function 'L_car-val :lambda-list '(m))
(cl:defmethod L_car-val ((m <car_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:L_car-val is deprecated.  Use lino_msgs-msg:L_car instead.")
  (L_car m))

(cl:ensure-generic-function 'Reset_car-val :lambda-list '(m))
(cl:defmethod Reset_car-val ((m <car_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:Reset_car-val is deprecated.  Use lino_msgs-msg:Reset_car instead.")
  (Reset_car m))

(cl:ensure-generic-function 'out_time-val :lambda-list '(m))
(cl:defmethod out_time-val ((m <car_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lino_msgs-msg:out_time-val is deprecated.  Use lino_msgs-msg:out_time instead.")
  (out_time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <car_param>) ostream)
  "Serializes a message object of type '<car_param>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'R_wheel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'W_car))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'L_car))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Reset_car))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'out_time)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <car_param>) istream)
  "Deserializes a message object of type '<car_param>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'R_wheel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'W_car) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'L_car) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Reset_car) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'out_time) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<car_param>)))
  "Returns string type for a message object of type '<car_param>"
  "lino_msgs/car_param")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'car_param)))
  "Returns string type for a message object of type 'car_param"
  "lino_msgs/car_param")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<car_param>)))
  "Returns md5sum for a message object of type '<car_param>"
  "3ea72a41c2a9f150b8f2e47b164a570d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'car_param)))
  "Returns md5sum for a message object of type 'car_param"
  "3ea72a41c2a9f150b8f2e47b164a570d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<car_param>)))
  "Returns full string definition for message of type '<car_param>"
  (cl:format cl:nil "float32 R_wheel~%float32 W_car~%float32 L_car~%float32 Reset_car~%int32 out_time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'car_param)))
  "Returns full string definition for message of type 'car_param"
  (cl:format cl:nil "float32 R_wheel~%float32 W_car~%float32 L_car~%float32 Reset_car~%int32 out_time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <car_param>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <car_param>))
  "Converts a ROS message object to a list"
  (cl:list 'car_param
    (cl:cons ':R_wheel (R_wheel msg))
    (cl:cons ':W_car (W_car msg))
    (cl:cons ':L_car (L_car msg))
    (cl:cons ':Reset_car (Reset_car msg))
    (cl:cons ':out_time (out_time msg))
))
