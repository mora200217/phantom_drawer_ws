#include "ros/ros.h"
#include "tcp.hpp"



int main(int argc, char ** argv){
    ros::init(argc, argv, "tcp_reader"); 
    ros::NodeHandle nh; 
    
    return 0; 
}