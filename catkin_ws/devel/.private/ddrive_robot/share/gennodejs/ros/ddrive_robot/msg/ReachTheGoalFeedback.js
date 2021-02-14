// Auto-generated. Do not edit!

// (in-package ddrive_robot.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ReachTheGoalFeedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x_status = null;
      this.y_status = null;
    }
    else {
      if (initObj.hasOwnProperty('x_status')) {
        this.x_status = initObj.x_status
      }
      else {
        this.x_status = 0.0;
      }
      if (initObj.hasOwnProperty('y_status')) {
        this.y_status = initObj.y_status
      }
      else {
        this.y_status = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReachTheGoalFeedback
    // Serialize message field [x_status]
    bufferOffset = _serializer.float32(obj.x_status, buffer, bufferOffset);
    // Serialize message field [y_status]
    bufferOffset = _serializer.float32(obj.y_status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReachTheGoalFeedback
    let len;
    let data = new ReachTheGoalFeedback(null);
    // Deserialize message field [x_status]
    data.x_status = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y_status]
    data.y_status = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ddrive_robot/ReachTheGoalFeedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a25804fcdc19934866f12b8ef1c3cc33';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    #Feedback
    float32 x_status
    float32 y_status
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReachTheGoalFeedback(null);
    if (msg.x_status !== undefined) {
      resolved.x_status = msg.x_status;
    }
    else {
      resolved.x_status = 0.0
    }

    if (msg.y_status !== undefined) {
      resolved.y_status = msg.y_status;
    }
    else {
      resolved.y_status = 0.0
    }

    return resolved;
    }
};

module.exports = ReachTheGoalFeedback;