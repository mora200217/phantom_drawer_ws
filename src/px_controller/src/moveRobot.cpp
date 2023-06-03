#include "ros/ros.h"
#include "px_controller/moveRobot.h"

#include "trajectory_msgs/JointTrajectory.h"
#include "sensor_msgs/JointState.h"

bool moveMyRobot(px_controller::moveRobot::Request &req, px_controller::moveRobot::Response &res ); 

ros::Publisher configPublisher; 
ros::Publisher rvizConfigPublisher; 


int main(int argc, char** argv){
    ros::init(argc, argv, "moveRobot"); 
    ros::NodeHandle nh; 

    ros::ServiceServer myServer = nh.advertiseService("/moveRobot", moveMyRobot); 
    configPublisher = nh.advertise<trajectory_msgs::JointTrajectory>("/joint_trajectory", 1000); 
    rvizConfigPublisher = nh.advertise<sensor_msgs::JointState>("/joint_states_custom", 1000); 

    ROS_INFO("ready for moving the robot"); 
    ros::spin(); 
    return 1; 
}


bool moveMyRobot(px_controller::moveRobot::Request &req, px_controller::moveRobot::Response &res ){
    float q1 = req.config.q1; 
    float q2 = req.config.q2; 
    float q3 = req.config.q3; 
    float q4 = req.config.q4; 
    float q5 = req.config.q5; 
    
    trajectory_msgs::JointTrajectory trajectoryMessage; 

    trajectoryMessage.header.stamp = ros::Time::now(); 
    trajectoryMessage.joint_names.clear(); 

    trajectoryMessage.joint_names.push_back("joint_1"); 
    trajectoryMessage.joint_names.push_back("joint_2"); 
    trajectoryMessage.joint_names.push_back("joint_3"); 
    trajectoryMessage.joint_names.push_back("joint_4"); 
    trajectoryMessage.joint_names.push_back("joint_5"); 


    // Create Joint Trajectroy Point 
    trajectory_msgs::JointTrajectoryPoint trajectoryPoint; 
    trajectoryPoint.time_from_start = ros::Duration(0.7); 
    trajectoryPoint.positions = {q1, q2, q3, q4, q5}; 

    trajectoryMessage.points = {trajectoryPoint}; 
    // Send information 
    configPublisher.publish(trajectoryMessage); 
    ROS_INFO_STREAM("sending: " << trajectoryMessage); 

    /**
     * Joint States for Rviz 
    */

   sensor_msgs::JointState state; 
   state.header.stamp = ros::Time::now(); 

   state.name.push_back("joint_1"); 
   state.name.push_back("joint_2"); 
   state.name.push_back("joint_3"); 
   state.name.push_back("joint_4"); 

   state.position = {q1, q2, q3, q4}; 

   rvizConfigPublisher.publish(state); 
   ROS_INFO_STREAM("Gazebo sending: " << state); 

    return 1; 
}