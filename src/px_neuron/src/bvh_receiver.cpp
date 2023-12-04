#include "ros/ros.h"
#include "px_neuron_msg/hand_poses.h"

int main(int argc, char** argv){
    ros::init(argc, argv, "bvh_receiver_node"); 
    ros::NodeHandle nh; 

    ros::Publisher pub = nh.advertise<px_neuron_msg::hand_poses>("/neuron/body", 1000);  
    ROS_INFO(" Neuron body loaded"); 
   
    return 0; 
}