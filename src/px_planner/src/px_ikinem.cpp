// px_ikinem.cpp

#include "ros/ros.h"
#include "px_planner/ikinem.h"
#include "visualization_msgs/Marker.h"
#include "px_controller/moveRobot.h"

// defines 
#define PI 3.1415

// Functions 
void pxIkinem(float x, float y, float z, float* config); 
bool pxIkinemSrv(px_planner::ikinem::Request &req, px_planner::ikinem::Response &res); 
float norm(float L1, float L2); 

px_controller::moveRobot srv; 
ros::ServiceClient move; 
ros::Publisher markerPub;

int main(int argc, char**argv){
    ros::init(argc, argv, "ikinem"); 
    ros::NodeHandle nh;     
    
    ros::ServiceServer myServer = nh.advertiseService("px_ikinem", pxIkinemSrv); 
    
    move = nh.serviceClient<px_controller::moveRobot>("/moveRobot"); 
    markerPub = nh.advertise<visualization_msgs::Marker>("/desired_pos", 100); 
    
    ROS_INFO("Inverse kinematics service ready."); 
    ros::spin(); 
    return 1; 
}

bool pxIkinemSrv(px_planner::ikinem::Request &req, px_planner::ikinem::Response &res){
    const int n_joints = 5; 
    float* config = (float * ) malloc(sizeof(float) * n_joints); 

    // Marker position
    visualization_msgs::Marker markedPosition; 
    markedPosition.header.frame_id = "base_link"; 
    markedPosition.header.stamp = ros::Time::now(); 
    markedPosition.type = visualization_msgs::Marker::SPHERE; 
    markedPosition.action = visualization_msgs::Marker::ADD; 
    
    markedPosition.pose.position.x = req.desiredPosition.x / 100; 
    markedPosition.pose.position.y = req.desiredPosition.y / 100;  
    markedPosition.pose.position.z = req.desiredPosition.z / 100; 

    markedPosition.color.r = 1.0; 
    markedPosition.color.g = 0.0; 
    markedPosition.color.b = 0.0; 

    markedPosition.color.a = 1.0; // Don't forget to set the alpha!
    markedPosition.scale.x = 1.0 / 100; 
    markedPosition.scale.y = 1.0 / 100; 
    markedPosition.scale.z = 1.0 / 100; 

    markerPub.publish(markedPosition); 
    

    pxIkinem(req.desiredPosition.x, req.desiredPosition.y, req.desiredPosition.z, config); 

    

    res.robotConfiguration.q1 = *(config);
    res.robotConfiguration.q2 = *(config + 1);
    res.robotConfiguration.q3 = *(config + 2);
    res.robotConfiguration.q4 = *(config + 3);


    // move robot 
    srv.request.config.q1 = res.robotConfiguration.q1;
    srv.request.config.q2 = res.robotConfiguration.q2;
    srv.request.config.q3 = res.robotConfiguration.q3;
    srv.request.config.q4 = res.robotConfiguration.q4;

    move.call(srv); 

    return true; 
}


/**
 * Calculate Inverse Kinematics
*/
void pxIkinem(float x, float y, float z, float* config){
    // All distances are in Centimeters 
    const float L0 = 5.02;  
    const float L1 = 4.2;  
    const float L21 = 10.3; 
    const float L22 = 3.7; 
    const float L3 = 9.8f; 
    const float L4 = 11.4f; // TCP distance from last joint 
    const float L5 = 5.0f; // Marker height 

    float L2 = norm(L21, L22); 
    float gamma = atan2(L22, L21); 

    float q1, q2, q3, q4; // Joints for 4R 
    q1 = atan2(y, x); // most ez one :v 

    // Solve a 2R for the q2 and q3 joints 
    float y_2r = z + L5 - (L0 + L1); 
    float x_2r = sqrt(pow(x, 2) + pow(y, 2)) - L4; 

    // Angles w/o transformations
    float c3 = (pow(x_2r, 2) + pow(y_2r, 2) - pow(L2, 2) - pow(L3, 2)) / (2 * L2 * L3); 
    q3 = atan2(sqrt(1 - pow(c3, 2)), c3); 
    q2 = atan2(x_2r, y_2r) - atan2(L3 * sin(q3), L2 + L3 * cos(q3)); 

    q2 = -(q2 - gamma); 
    q3 = -(q3 - PI/2); 
    q4 = -q2 - q3;  // to change 

    // 
    *(config) = q1; 
    *(config + 1) = q2; 
    *(config + 2) = q3; 
    *(config + 3) = q4; 
}



float norm(float L1, float L2){
    return sqrt(pow(L1, 2)  + pow(L2, 2)); 
}