#include"ros/ros.h"
#include "std_msgs/Bool.h"

#include "px_msgs/home.h"

ros::ServiceClient srv; 
    

void callback(const std_msgs::Bool::ConstPtr& income){
        ROS_INFO("go home from cellphone");    
        if(income -> data){
            px_msgs::home msg; 
            srv.call(msg); 
        }    
}

int main(int argc,char** argv){
    ros::init(argc, argv, "button_node"); 
    ros::NodeHandle n;
    
    srv = n.serviceClient<px_msgs::home>("/goHome"); 

    ros::Subscriber sub = n.subscribe("/press_button",1000, callback); 
    ros::spin(); 

    return 0; 
}