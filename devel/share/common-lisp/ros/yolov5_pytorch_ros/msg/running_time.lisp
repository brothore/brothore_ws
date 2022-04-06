; Auto-generated. Do not edit!


(cl:in-package yolov5_pytorch_ros-msg)


;//! \htmlinclude running_time.msg.html

(cl:defclass <running_time> (roslisp-msg-protocol:ros-message)
  ((time0_pub
    :reader time0_pub
    :initarg :time0_pub
    :type cl:float
    :initform 0.0)
   (time0_sub
    :reader time0_sub
    :initarg :time0_sub
    :type cl:float
    :initform 0.0)
   (time1_pub
    :reader time1_pub
    :initarg :time1_pub
    :type cl:float
    :initform 0.0)
   (time1_sub
    :reader time1_sub
    :initarg :time1_sub
    :type cl:float
    :initform 0.0)
   (time2_pub
    :reader time2_pub
    :initarg :time2_pub
    :type cl:float
    :initform 0.0)
   (time2_sub
    :reader time2_sub
    :initarg :time2_sub
    :type cl:float
    :initform 0.0))
)

(cl:defclass running_time (<running_time>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <running_time>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'running_time)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolov5_pytorch_ros-msg:<running_time> is deprecated: use yolov5_pytorch_ros-msg:running_time instead.")))

(cl:ensure-generic-function 'time0_pub-val :lambda-list '(m))
(cl:defmethod time0_pub-val ((m <running_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_pytorch_ros-msg:time0_pub-val is deprecated.  Use yolov5_pytorch_ros-msg:time0_pub instead.")
  (time0_pub m))

(cl:ensure-generic-function 'time0_sub-val :lambda-list '(m))
(cl:defmethod time0_sub-val ((m <running_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_pytorch_ros-msg:time0_sub-val is deprecated.  Use yolov5_pytorch_ros-msg:time0_sub instead.")
  (time0_sub m))

(cl:ensure-generic-function 'time1_pub-val :lambda-list '(m))
(cl:defmethod time1_pub-val ((m <running_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_pytorch_ros-msg:time1_pub-val is deprecated.  Use yolov5_pytorch_ros-msg:time1_pub instead.")
  (time1_pub m))

(cl:ensure-generic-function 'time1_sub-val :lambda-list '(m))
(cl:defmethod time1_sub-val ((m <running_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_pytorch_ros-msg:time1_sub-val is deprecated.  Use yolov5_pytorch_ros-msg:time1_sub instead.")
  (time1_sub m))

(cl:ensure-generic-function 'time2_pub-val :lambda-list '(m))
(cl:defmethod time2_pub-val ((m <running_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_pytorch_ros-msg:time2_pub-val is deprecated.  Use yolov5_pytorch_ros-msg:time2_pub instead.")
  (time2_pub m))

(cl:ensure-generic-function 'time2_sub-val :lambda-list '(m))
(cl:defmethod time2_sub-val ((m <running_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_pytorch_ros-msg:time2_sub-val is deprecated.  Use yolov5_pytorch_ros-msg:time2_sub instead.")
  (time2_sub m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <running_time>) ostream)
  "Serializes a message object of type '<running_time>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time0_pub))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time0_sub))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time1_pub))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time1_sub))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time2_pub))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time2_sub))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <running_time>) istream)
  "Deserializes a message object of type '<running_time>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time0_pub) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time0_sub) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time1_pub) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time1_sub) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time2_pub) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time2_sub) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<running_time>)))
  "Returns string type for a message object of type '<running_time>"
  "yolov5_pytorch_ros/running_time")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'running_time)))
  "Returns string type for a message object of type 'running_time"
  "yolov5_pytorch_ros/running_time")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<running_time>)))
  "Returns md5sum for a message object of type '<running_time>"
  "fba7101da493706fc2932a90aa6f2991")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'running_time)))
  "Returns md5sum for a message object of type 'running_time"
  "fba7101da493706fc2932a90aa6f2991")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<running_time>)))
  "Returns full string definition for message of type '<running_time>"
  (cl:format cl:nil "float64 time0_pub~%float64 time0_sub~%float64 time1_pub~%float64 time1_sub~%float64 time2_pub~%float64 time2_sub~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'running_time)))
  "Returns full string definition for message of type 'running_time"
  (cl:format cl:nil "float64 time0_pub~%float64 time0_sub~%float64 time1_pub~%float64 time1_sub~%float64 time2_pub~%float64 time2_sub~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <running_time>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <running_time>))
  "Converts a ROS message object to a list"
  (cl:list 'running_time
    (cl:cons ':time0_pub (time0_pub msg))
    (cl:cons ':time0_sub (time0_sub msg))
    (cl:cons ':time1_pub (time1_pub msg))
    (cl:cons ':time1_sub (time1_sub msg))
    (cl:cons ':time2_pub (time2_pub msg))
    (cl:cons ':time2_sub (time2_sub msg))
))
