// Auto-generated. Do not edit!

// (in-package yolov5_pytorch_ros.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class running_time {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time0_pub = null;
      this.time0_sub = null;
      this.time1_pub = null;
      this.time1_sub = null;
      this.time2_pub = null;
      this.time2_sub = null;
    }
    else {
      if (initObj.hasOwnProperty('time0_pub')) {
        this.time0_pub = initObj.time0_pub
      }
      else {
        this.time0_pub = 0.0;
      }
      if (initObj.hasOwnProperty('time0_sub')) {
        this.time0_sub = initObj.time0_sub
      }
      else {
        this.time0_sub = 0.0;
      }
      if (initObj.hasOwnProperty('time1_pub')) {
        this.time1_pub = initObj.time1_pub
      }
      else {
        this.time1_pub = 0.0;
      }
      if (initObj.hasOwnProperty('time1_sub')) {
        this.time1_sub = initObj.time1_sub
      }
      else {
        this.time1_sub = 0.0;
      }
      if (initObj.hasOwnProperty('time2_pub')) {
        this.time2_pub = initObj.time2_pub
      }
      else {
        this.time2_pub = 0.0;
      }
      if (initObj.hasOwnProperty('time2_sub')) {
        this.time2_sub = initObj.time2_sub
      }
      else {
        this.time2_sub = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type running_time
    // Serialize message field [time0_pub]
    bufferOffset = _serializer.float64(obj.time0_pub, buffer, bufferOffset);
    // Serialize message field [time0_sub]
    bufferOffset = _serializer.float64(obj.time0_sub, buffer, bufferOffset);
    // Serialize message field [time1_pub]
    bufferOffset = _serializer.float64(obj.time1_pub, buffer, bufferOffset);
    // Serialize message field [time1_sub]
    bufferOffset = _serializer.float64(obj.time1_sub, buffer, bufferOffset);
    // Serialize message field [time2_pub]
    bufferOffset = _serializer.float64(obj.time2_pub, buffer, bufferOffset);
    // Serialize message field [time2_sub]
    bufferOffset = _serializer.float64(obj.time2_sub, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type running_time
    let len;
    let data = new running_time(null);
    // Deserialize message field [time0_pub]
    data.time0_pub = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time0_sub]
    data.time0_sub = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time1_pub]
    data.time1_pub = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time1_sub]
    data.time1_sub = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time2_pub]
    data.time2_pub = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time2_sub]
    data.time2_sub = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'yolov5_pytorch_ros/running_time';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fba7101da493706fc2932a90aa6f2991';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 time0_pub
    float64 time0_sub
    float64 time1_pub
    float64 time1_sub
    float64 time2_pub
    float64 time2_sub
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new running_time(null);
    if (msg.time0_pub !== undefined) {
      resolved.time0_pub = msg.time0_pub;
    }
    else {
      resolved.time0_pub = 0.0
    }

    if (msg.time0_sub !== undefined) {
      resolved.time0_sub = msg.time0_sub;
    }
    else {
      resolved.time0_sub = 0.0
    }

    if (msg.time1_pub !== undefined) {
      resolved.time1_pub = msg.time1_pub;
    }
    else {
      resolved.time1_pub = 0.0
    }

    if (msg.time1_sub !== undefined) {
      resolved.time1_sub = msg.time1_sub;
    }
    else {
      resolved.time1_sub = 0.0
    }

    if (msg.time2_pub !== undefined) {
      resolved.time2_pub = msg.time2_pub;
    }
    else {
      resolved.time2_pub = 0.0
    }

    if (msg.time2_sub !== undefined) {
      resolved.time2_sub = msg.time2_sub;
    }
    else {
      resolved.time2_sub = 0.0
    }

    return resolved;
    }
};

module.exports = running_time;
