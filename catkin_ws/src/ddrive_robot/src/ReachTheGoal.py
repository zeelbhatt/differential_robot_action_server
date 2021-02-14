#!/usr/bin/env python

import rospy
import math
import actionlib
from geometry_msgs.msg import Twist, PoseStamped
from turtlesim.msg import Pose
from turtlesim.srv import (TeleportAbsolute, TeleportAbsoluteRequest)
from ddrive_robot.msg import ReachTheGoalAction, ReachTheGoalFeedback, ReachTheGoalResult


class ReachGoal:
    def __init__(self):
        self.pub = None
        self.xp = None
        self.yp = None
        self.theta = None
        self.x_goal = None
        self.y_goal = None
        self.r = rospy.Rate(100)
        self.chase_distance = None
        self.distance_int = 0
        self.feedback = ReachTheGoalFeedback()
        self.result = ReachTheGoalResult()

        self.kp_l = 1
        self.kd_l = 0.1
        self.ki_l = 0.0001

        self.kp_a = 2
        self.kd_a = 0.1
        self.ki_a = 0.001

        self._init_sub_pub()

    def _init_sub_pub(self):
        rospy.Subscriber('/turtle1/pose', Pose, self._turtle_cb)
        rospy.Subscriber('/goal', PoseStamped, self._goal_cb)
        self.pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=1)
        self.a_server = actionlib.SimpleActionServer("ReachGoalServer", ReachTheGoalAction, execute_cb=self._execute_cb,
                                                     auto_start=False)
        self.a_server.start()

    def _turtle_cb(self, req):
        self.xp = req.x
        self.yp = req.y
        self.yaw = req.theta
        self.line_vel = req.linear_velocity
        self.ang_vel = req.angular_velocity

    def _goal_cb(self, req):
        self.x_goal = req.pose.position.x
        self.y_goal = req.pose.position.y
        print('Goal set to ', self.x_goal, self.y_goal)

    def _execute_cb(self, req):
        success = True
        if req.call_mission is True and self.x_goal is not None:
            print('Check 1')
            self.chase_distance = math.sqrt((self.xp - self.x_goal) ** 2 + (self.yp - self.y_goal) ** 2)
            while self.chase_distance >= 0.3:
                if self.a_server.is_preempt_requested():
                    success = False
                    break
                command = Twist()
                command.linear.x = 0.01 * self._set_linear_speed()
                command.angular.z = 0.01 * self._set_angular_speed()
                self.pub.publish(command)

                self.feedback.x_status = self.xp
                self.feedback.y_status = self.yp
                self.a_server.publish_feedback(self.feedback)

                self.r.sleep()
            self.result.success = True
            self.result.message = "Bot reached to goal"

            if success:
                self.a_server.set_succeeded(self.result)

        elif req.call_mission is False:
            command = Twist()
            command.linear.x = 0
            command.angular.z = 0
            self.pub.publish(command)

            self.result.success = True
            self.result.message = "Bot Stopped"

            self.a_server.set_succeeded(self.result)

    def _set_linear_speed(self):
        self.chase_distance = math.sqrt((self.xp - self.x_goal) ** 2 + (self.yp - self.y_goal) ** 2)
        self.distance_int = self.distance_int + self.chase_distance
        command_linear_speed = (self.kp_l * self.chase_distance) + ((-self.kd_l) * self.line_vel) + \
                               (self.ki_l * self.distance_int)

        return command_linear_speed

    def _set_angular_speed(self):
        target_rad = math.atan2(self.y_goal - self.yp, self.x_goal - self.xp)
        self.yaw_diff = target_rad - self.yaw

        if math.degrees(self.yaw_diff) >= 180:
            self.yaw_diff = self.yaw_diff - 6.2832
        if math.degrees(self.yaw_diff) <= -180:
            self.yaw_diff = self.yaw_diff + 6.2832

        command_angular_speed = (self.kp_a * self.yaw_diff) + ((-self.kd_a) * self.ang_vel)
        return command_angular_speed


def main():
    rospy.init_node('ReachTheGoal')
    rospy.loginfo("[ReachTheGoal] initialized")
    call_reset = rospy.ServiceProxy('/turtle1/teleport_absolute', TeleportAbsolute)
    setr = TeleportAbsoluteRequest()
    setr.x = 1.0
    setr.y = 1.0
    setr.theta = 0
    response = call_reset(setr)
    obj = ReachGoal()

    try:
        print('Spinning')
        rospy.spin()
    except KeyboardInterrupt:
        rospy.loginfo('[ReachTheGoal] closed')


if __name__ == '__main__':
    main()
