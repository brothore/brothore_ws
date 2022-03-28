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

class wheel_speed {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.L1 = null;
      this.L2 = null;
      this.L3 = null;
      this.R1 = null;
      this.R2 = null;
      this.R3 = null;
      this.L_SPEED = null;
      this.R_SPEED = null;
      this.L1_PID = null;
      this.L2_PID = null;
      this.L3_PID = null;
      this.R1_PID = null;
      this.R2_PID = null;
      this.R3_PID = null;
    }
    else {
      if (initObj.hasOwnProperty('L1')) {
        this.L1 = initObj.L1
      }
      else {
        this.L1 = 0.0;
      }
      if (initObj.hasOwnProperty('L2')) {
        this.L2 = initObj.L2
      }
      else {
        this.L2 = 0.0;
      }
      if (initObj.hasOwnProperty('L3')) {
        this.L3 = initObj.L3
      }
      else {
        this.L3 = 0.0;
      }
      if (initObj.hasOwnProperty('R1')) {
        this.R1 = initObj.R1
      }
      else {
        this.R1 = 0.0;
      }
      if (initObj.hasOwnProperty('R2')) {
        this.R2 = initObj.R2
      }
      else {
        this.R2 = 0.0;
      }
      if (initObj.hasOwnProperty('R3')) {
        this.R3 = initObj.R3
      }
      else {
        this.R3 = 0.0;
      }
      if (initObj.hasOwnProperty('L_SPEED')) {
        this.L_SPEED = initObj.L_SPEED
      }
      else {
        this.L_SPEED = 0.0;
      }
      if (initObj.hasOwnProperty('R_SPEED')) {
        this.R_SPEED = initObj.R_SPEED
      }
      else {
        this.R_SPEED = 0.0;
      }
      if (initObj.hasOwnProperty('L1_PID')) {
        this.L1_PID = initObj.L1_PID
      }
      else {
        this.L1_PID = 0.0;
      }
      if (initObj.hasOwnProperty('L2_PID')) {
        this.L2_PID = initObj.L2_PID
      }
      else {
        this.L2_PID = 0.0;
      }
      if (initObj.hasOwnProperty('L3_PID')) {
        this.L3_PID = initObj.L3_PID
      }
      else {
        this.L3_PID = 0.0;
      }
      if (initObj.hasOwnProperty('R1_PID')) {
        this.R1_PID = initObj.R1_PID
      }
      else {
        this.R1_PID = 0.0;
      }
      if (initObj.hasOwnProperty('R2_PID')) {
        this.R2_PID = initObj.R2_PID
      }
      else {
        this.R2_PID = 0.0;
      }
      if (initObj.hasOwnProperty('R3_PID')) {
        this.R3_PID = initObj.R3_PID
      }
      else {
        this.R3_PID = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type wheel_speed
    // Serialize message field [L1]
    bufferOffset = _serializer.float32(obj.L1, buffer, bufferOffset);
    // Serialize message field [L2]
    bufferOffset = _serializer.float32(obj.L2, buffer, bufferOffset);
    // Serialize message field [L3]
    bufferOffset = _serializer.float32(obj.L3, buffer, bufferOffset);
    // Serialize message field [R1]
    bufferOffset = _serializer.float32(obj.R1, buffer, bufferOffset);
    // Serialize message field [R2]
    bufferOffset = _serializer.float32(obj.R2, buffer, bufferOffset);
    // Serialize message field [R3]
    bufferOffset = _serializer.float32(obj.R3, buffer, bufferOffset);
    // Serialize message field [L_SPEED]
    bufferOffset = _serializer.float32(obj.L_SPEED, buffer, bufferOffset);
    // Serialize message field [R_SPEED]
    bufferOffset = _serializer.float32(obj.R_SPEED, buffer, bufferOffset);
    // Serialize message field [L1_PID]
    bufferOffset = _serializer.float32(obj.L1_PID, buffer, bufferOffset);
    // Serialize message field [L2_PID]
    bufferOffset = _serializer.float32(obj.L2_PID, buffer, bufferOffset);
    // Serialize message field [L3_PID]
    bufferOffset = _serializer.float32(obj.L3_PID, buffer, bufferOffset);
    // Serialize message field [R1_PID]
    bufferOffset = _serializer.float32(obj.R1_PID, buffer, bufferOffset);
    // Serialize message field [R2_PID]
    bufferOffset = _serializer.float32(obj.R2_PID, buffer, bufferOffset);
    // Serialize message field [R3_PID]
    bufferOffset = _serializer.float32(obj.R3_PID, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type wheel_speed
    let len;
    let data = new wheel_speed(null);
    // Deserialize message field [L1]
    data.L1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L2]
    data.L2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L3]
    data.L3 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R1]
    data.R1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R2]
    data.R2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R3]
    data.R3 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L_SPEED]
    data.L_SPEED = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R_SPEED]
    data.R_SPEED = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L1_PID]
    data.L1_PID = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L2_PID]
    data.L2_PID = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [L3_PID]
    data.L3_PID = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R1_PID]
    data.R1_PID = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R2_PID]
    data.R2_PID = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [R3_PID]
    data.R3_PID = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 56;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lino_msgs/wheel_speed';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dcc44326156228f397c3cb547e1a862c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 L1
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new wheel_speed(null);
    if (msg.L1 !== undefined) {
      resolved.L1 = msg.L1;
    }
    else {
      resolved.L1 = 0.0
    }

    if (msg.L2 !== undefined) {
      resolved.L2 = msg.L2;
    }
    else {
      resolved.L2 = 0.0
    }

    if (msg.L3 !== undefined) {
      resolved.L3 = msg.L3;
    }
    else {
      resolved.L3 = 0.0
    }

    if (msg.R1 !== undefined) {
      resolved.R1 = msg.R1;
    }
    else {
      resolved.R1 = 0.0
    }

    if (msg.R2 !== undefined) {
      resolved.R2 = msg.R2;
    }
    else {
      resolved.R2 = 0.0
    }

    if (msg.R3 !== undefined) {
      resolved.R3 = msg.R3;
    }
    else {
      resolved.R3 = 0.0
    }

    if (msg.L_SPEED !== undefined) {
      resolved.L_SPEED = msg.L_SPEED;
    }
    else {
      resolved.L_SPEED = 0.0
    }

    if (msg.R_SPEED !== undefined) {
      resolved.R_SPEED = msg.R_SPEED;
    }
    else {
      resolved.R_SPEED = 0.0
    }

    if (msg.L1_PID !== undefined) {
      resolved.L1_PID = msg.L1_PID;
    }
    else {
      resolved.L1_PID = 0.0
    }

    if (msg.L2_PID !== undefined) {
      resolved.L2_PID = msg.L2_PID;
    }
    else {
      resolved.L2_PID = 0.0
    }

    if (msg.L3_PID !== undefined) {
      resolved.L3_PID = msg.L3_PID;
    }
    else {
      resolved.L3_PID = 0.0
    }

    if (msg.R1_PID !== undefined) {
      resolved.R1_PID = msg.R1_PID;
    }
    else {
      resolved.R1_PID = 0.0
    }

    if (msg.R2_PID !== undefined) {
      resolved.R2_PID = msg.R2_PID;
    }
    else {
      resolved.R2_PID = 0.0
    }

    if (msg.R3_PID !== undefined) {
      resolved.R3_PID = msg.R3_PID;
    }
    else {
      resolved.R3_PID = 0.0
    }

    return resolved;
    }
};

module.exports = wheel_speed;
