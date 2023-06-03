#include "ros/ros.h"
#include "px_controller/home.h"
#include "px_controller/moveRobot.h"

ros::ServiceClient move; 
px_controller::moveRobot srv; 

bool goHome(px_controller::home::Request &req, px_controller::home::Response &res); 
ros::Publisher pub; 


int main(int argc, char** argv){
    ros::init(argc, argv, "homeConfig"); 
    ros::NodeHandle nh; 

    move = nh.serviceClient<px_controller::moveRobot>("/moveRobot"); 
    ros::ServiceServer server = nh.advertiseService("/goHome", goHome); 
 
    ros::spin(); 
    return 1; 
}

bool goHome(px_controller::home::Request &req, px_controller::home::Response &res){
    srv.request.config.q1 = 0.0; 
    srv.request.config.q2 = 0.0; 
    srv.request.config.q3 = 0.0; 
    srv.request.config.q4 = 0.0; 
    srv.request.config.q5 = 0.0; 

     if(move.call(srv))
        ROS_INFO("Going home!"); 

    return true; 
}