#include "ros/ros.h"
#include "px_msgs/pxIkinem.h"

bool calculate_ikinem(px_msgs::pxIkinem::Request &req, 
                      px_msgs::pxIkinem::Response &res); 

int main(int argc, char** argv){
    ros::init(argc, argv, "ikinem_calculator"); 
    ros::NodeHandle n; 
    
    ros::ServiceServer service = n.advertiseService("/get_inverse_kinematics", calculate_ikinem); 
    ROS_INFO("Listo para recibir peticiones!"); 
    ros::spin(); 
    return 1; 
}

bool calculate_ikinem(px_msgs::pxIkinem::Request &req, 
                      px_msgs::pxIkinem::Response &res){

    // End effector position 
    float x = req.position.x; 
    float y = req.position.y; 
    float z = req.position.z;

    float theta = atan2(y, x); 

    res.config.q1 = theta; 
    res.config.q2 = theta; 
    res.config.q3 = theta; 
    res.config.q4 = theta; 
    res.config.q5 = theta; 

    ROS_INFO("Encontrada la posicion y resuelta la cinemática inversa"); 
    return true; 

}