#include "ros/ros.h"
#include "trajectory_msgs/JointTrajectory.h"



int main(int argc, char** argv){
    ros::init(argc, argv, "controller_node"); 
    ros::NodeHandle nh; 
    
    // Create Publisher 
    ros::Publisher pub = nh.advertise<trajectory_msgs::JointTrajectory>("/joint_trajectory", 1000); 
    
    trajectory_msgs::JointTrajectory configMsg;   // Create message 


    
    
    

    return 1; 
}