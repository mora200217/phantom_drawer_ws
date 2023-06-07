#include "ros/ros.h"
#include "px_msgs/ikinem.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/Float64.h"

#include "px_msgs/gripperPose.h"

ros::ServiceClient client; 
ros::ServiceClient clientGripper;


void callback(const geometry_msgs::Vector3::ConstPtr& msg){
    float x = msg->x ; 
    float y = msg->y ; 
    float z = msg->z ; 

    px_msgs::ikinem srv; 

    srv.request.desiredPosition.x = x; 
    srv.request.desiredPosition.y = y; 
    srv.request.desiredPosition.z = z; 

    client.call(srv);

    ROS_INFO_STREAM("Desired position: " << srv.request);  
}

void callbackGripper(const std_msgs::Float64::ConstPtr& msg){
    px_msgs::gripperPose srv; 

    srv.request.desiredGripperPose = msg -> data; 
    clientGripper.call(srv); 
    ROS_INFO("Calling gripper!"); 
   
}

int main(int argc, char** argv){
    ros::init(argc, argv, "pose_converter_matlab"); 
    ros::NodeHandle n; 
    
    // Subscribers 
    ros::Subscriber sub = n.subscribe<geometry_msgs::Vector3>("/matlab_app_pose", 1000, callback); 
    ros::Subscriber subGripper = n.subscribe<std_msgs::Float64>("/matlab_app_gripper", 1000, callbackGripper); 

    // Clients 
    client = n.serviceClient<px_msgs::ikinem>("/px_planner/px_ikinem"); 
    clientGripper = n.serviceClient<px_msgs::ikinem>("/setGripper"); 

    ros::spin(); 
    return 0; 
}