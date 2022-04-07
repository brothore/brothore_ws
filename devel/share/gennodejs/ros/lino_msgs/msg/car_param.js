// Auto-generated. Do not edit!

// (in-package lino_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class car_param {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.R_wheel = null;
      this.W_car = null;
      this.L_car = null;
      this.Reset_car = null;
    }
    else {
      if (initObj.hasOwnProperty('R_wheel')) {
        this.R_wheel = initObj.R_wheel
      }
      else {
        this.R_wheel = 0.0;
      }
      if (initObj.hasOwnProperty('W_car')) {
        this.W_car = initObj.W_car
      }
      else {
        this.W_car = 0.0;
      }
      if (initObj.hasOwnProperty('L_car')) {
        this.L_car = initObj.L_car
      }
      else {
        this.L_car = 0.0;
      }
      if (initObj.hasOwnProperty('Reset_car')) {
        this.Reset_car = initObj.Reset_car
      }
      else {
        this.Reset_car = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type car_param
    // Serialize message field [R_wheel]
    bufferOffset = _serializer.float32(obj.R_wheel, buffer, bufferOffset);
    // Serialize message field [W_car]
    bufferOffset = _serializer.float32(obj.W_car, buffer, bufferOffset);
    // Serialize message field [L_car]
    bufferOffset = _serializer.float32(obj.L_car, buffer, bufferOffset);
    // Serialize message field [Reset_car]
    bufferOffset = _serializer.float32(obj.Reset_car, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type car_param
    let len;
    let data = new car_param(null);
    // Deserialize message field [R_wheel]
    data.R_wheel = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [W_car]
    data.W_car = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L_car]
    data.L_car = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Reset_car]
    data.Reset_car = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lino_msgs/car_param';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '71265fe5412a6ab64209f231f18d49fc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 R_wheel
    float32 W_car
    float32 L_car
    float32 Reset_car
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new car_param(null);
    if (msg.R_wheel !== undefined) {
      resolved.R_wheel = msg.R_wheel;
    }
    else {
      resolved.R_wheel = 0.0
    }

    if (msg.W_car !== undefined) {
      resolved.W_car = msg.W_car;
    }
    else {
      resolved.W_car = 0.0
    }

    if (msg.L_car !== undefined) {
      resolved.L_car = msg.L_car;
    }
    else {
      resolved.L_car = 0.0
    }

    if (msg.Reset_car !== undefined) {
      resolved.Reset_car = msg.Reset_car;
    }
    else {
      resolved.Reset_car = 0.0
    }

    return resolved;
    }
};

module.exports = car_param;
