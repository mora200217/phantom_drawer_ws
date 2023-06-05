#include "ros/ros.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"
#define pi 3.1415; 


int main(int argc, char** argv){
    ros::init(argc, argv, "create_paths"); 
    
    ros::NodeHandle n; 

    ros::Publisher trajPub = n.advertise<trajectory_msgs::JointTrajectory>("/joint_trajectory", 1000);
    // ros::ServiceClient ikinemService = n.serviceClient("/ikin")
    trajectory_msgs::JointTrajectory traj; 
    ros::Rate waitRate(ros::Duration(2)); 
    waitRate.sleep(); 
    
    
    traj.header.stamp = ros::Time::now(); 

    traj.joint_names.push_back("joint_1"); 
    traj.joint_names.push_back("joint_2"); 
    traj.joint_names.push_back("joint_3"); 
    traj.joint_names.push_back("joint_4"); 
    traj.joint_names.push_back("joint_5"); 

    // float delta_time = 0.1f;  // seconds 

    // for(float theta = -3.14 / 2.0; theta <= 3.14 / 2.0; theta += 0.1 ){
    //     trajectory_msgs::JointTrajectoryPoint point; 

    //     point = 
    // }



    // traj.points.push_back(pointA); 
    // traj.points.push_back(pointB); 

    
    // // while(ros::ok()){
    //     trajPub.publish(traj); 
    //     ROS_INFO_STREAM("send trajectory" << traj);
    //     waitRate.sleep(); 
    //     ros::spinOnce(); 
    // // }
    

    


    return 0; 
}


