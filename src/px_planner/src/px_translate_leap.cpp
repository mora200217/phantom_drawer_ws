#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "px_msgs/gripperPose.h"


void callBack(st
d_msgs::Float32::ConstPtr &msg){
    ros::ServiceClient sc = (); 
    msg -> data 
}


int main(int argc, char**argv){
    ros::init(argc, argv, "translater"); 
    ros::NodeHandle nh; 

    ros::Subscriber sub =  nh.subscribe("/gripper",101, callBack); 


    
    return 1; 
}