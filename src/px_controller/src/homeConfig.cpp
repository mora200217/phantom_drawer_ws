#include "ros/ros.h"
#include "px_msgs/home.h"
#include "px_msgs/moveRobot.h"

ros::ServiceClient move; 
px_msgs::moveRobot srv; 

bool goHome(px_msgs::home::Request &req, px_msgs::home::Response &res); 
ros::Publisher pub; 


int main(int argc, char** argv){
    ros::init(argc, argv, "homeConfig"); 
    ros::NodeHandle nh; 

    move = nh.serviceClient<px_msgs::moveRobot>("/moveRobot"); 
    ros::ServiceServer server = nh.advertiseService("/goHome", goHome); 
 
    ros::spin(); 
    return 1; 
}

bool goHome(px_msgs::home::Request &req, px_msgs::home::Response &res){
    srv.request.config.q1 = 0.0; 
    srv.request.config.q2 = 0.0; 
    srv.request.config.q3 = 0.0; 
    srv.request.config.q4 = 0.0; 
    srv.request.config.q5 = 0.0; 

     if(move.call(srv))
        ROS_INFO("Going home!"); 

    return true; 
}