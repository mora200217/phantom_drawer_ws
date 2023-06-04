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
    const float L1 = 9.0;  
    const float L2 = 10.5f; 
    const float L3 = 10.0f; 
    const float L4 = 11.0f; 
    const float L5 = 5.0f; 

    float xp, yp, zp; 
    // EE conversion from cosntraints
    float r = sqrt(pow(x, 2) + pow(y,2));
    float r_new = r - L4;  

    xp = x * (r_new / r); 
    yp = y * (r_new / r); 
    zp = z + L5; // High effector 


    float q1, q2, q3, q4; // robot joints  (4R); 
    q1 = atan2(y, x); 

    // Solution for 2R config in q2 and q3 for (xp, yp, zp)
    float x_2r = sqrt(pow(xp ,2) + pow(yp, 2)); 
    float z_2r = zp; 

    // cosine theorem
    float c2 = (pow(x_2r, 2) + pow(z_2r, 2) - pow(L2, 2) - pow(L3, 2)) / (2 * L2 * L3); 
    q3 = PI/2  - atan2(sqrt(1 - pow(c2, 2)), c2); 

    q2 = atan2(x_2r, z_2r) - atan2(L3 * sin(q3), L2 + L3 * cos(q3)); 
    q2 = q2 - PI/6; // TODO: use real measurements 

    float gamma = q2  - (PI/2 - q3);
    q4 = -(PI/2 - gamma); // condition for planar movement.

    // 
    *(config) = q1; 
    *(config + 1) = q2; 
    *(config + 2) = q3; 
    *(config + 3) = q4; 
}

