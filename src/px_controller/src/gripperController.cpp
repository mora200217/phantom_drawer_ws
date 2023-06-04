#include "ros/ros.h"
#include "px_msgs/gripperPose.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "px_msgs/moveRobot.h"

trajectory_msgs::JointTrajectory pos; 
ros::ServiceClient move; 
ros::Publisher configPub; 


bool setGripper(px_msgs::gripperPose::Request &req, px_msgs::gripperPose::Response &res ); 

int main(int argc, char** argv){
    ros::init(argc, argv, "gripper_controller"); 
    ros::NodeHandle nh; 
    ros::Rate loopRate(100); 
    ROS_INFO("Begining gripper controller node"); 
    configPub = nh.advertise<trajectory_msgs::JointTrajectory>("joint_trajectory", 1000); 
    move = nh.serviceClient<px_msgs::moveRobot>("moveRobot"); 

    // Create service 
    ros::ServiceServer gripperServer = nh.advertiseService("setGripper", setGripper); 
    ROS_INFO("Service created"); 
    ros::spin(); 
    
    return 1; 
}

bool setGripper(px_msgs::gripperPose::Request &req, px_msgs::gripperPose::Response &res ){
    ROS_INFO("modifying gripper"); 

    trajectory_msgs::JointTrajectory trajectoryMessage; 

    trajectoryMessage.header.stamp = ros::Time::now(); 
    trajectoryMessage.joint_names.clear(); 

    trajectoryMessage.joint_names.push_back("joint_5"); 
    
    // Create Joint Trajectroy Point 
    trajectory_msgs::JointTrajectoryPoint trajectoryPoint; 
    trajectoryPoint.time_from_start = ros::Duration(0.7); 
    trajectoryPoint.positions = {req.desiredGripperPose}; 

    trajectoryMessage.points = {trajectoryPoint}; 
    // Send information 
    configPub.publish(trajectoryMessage); 

    ROS_INFO_STREAM("sending: " << trajectoryMessage); 

    return true; 
}