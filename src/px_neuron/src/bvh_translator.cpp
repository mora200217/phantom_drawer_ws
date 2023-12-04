#include <algorithm>
#include "ros/ros.h"
#include "px_neuron_msg/hand_poses.h"
#include "px_msgs/gripperPose.h"

#include "trajectory_msgs/JointTrajectory.h"
#include "px_msgs/pxConfig.h"
#include "sensor_msgs/JointState.h"

ros::ServiceClient gripper;
ros::Publisher configPublisher; 

float norm(float L1, float L2); 
void pxIkinem(float x, float y, float z, float* config); 
float dist(float x1, float y1, float z1, float x2, float y2, float z2 ); 
float gripperOpening = -1; 

void callback(const px_neuron_msg::hand_poses::ConstPtr& msg){
    // Index spatial data
    float rhiX = msg->RightHandIndex.x; 
    float rhiY = msg->RightHandIndex.y; 
    float rhiZ = msg->RightHandIndex.z; 

    // Thumb spatial data
    float rhtX = msg->RightHandThumb.x; 
    float rhtY = msg->RightHandThumb.y; 
    float rhtZ = msg->RightHandThumb.z; 

    float handX = msg -> RightHand.x; 
    float handY = msg -> RightHand.y; 
    float handZ = msg -> RightHand.z; 

    float foreX = msg -> RightArm.x; 
    float foreY = msg -> RightArm.y; 
    float foreZ = msg -> RightArm.z; 

    float deltaX = std::max(std::min(handY - foreY, (float) 17.0), (float) 9.0); 
    float deltaY = std::max(std::min(-handZ + foreZ, (float) -10.0), (float) -10); 
    float deltaZ = std::max(std::min(handX - foreX, (float) 17.0), (float) 8); 

    const int n_joints = 5; 
    float* config = (float * ) malloc(sizeof(float) * n_joints); 

    pxIkinem(deltaX, deltaY, deltaZ, config); 

    float q1 = *(config); 
    float q2 = *(config + 1); 
    float q3 = *(config + 2); 
    float q4 = *(config + 3); 
    
    // Calculate distance 
    gripperOpening = dist(rhiX, rhiY, rhiZ, rhtX, rhtY, rhtZ);
    if(gripperOpening >= 8.0) 
    gripperOpening = 2;
    else
     gripperOpening = 0;
  
    // Movement 
    
    trajectory_msgs::JointTrajectory trajectoryMessage; 

    trajectoryMessage.header.stamp = ros::Time::now(); 
    trajectoryMessage.joint_names.clear(); 

    trajectoryMessage.joint_names.push_back("joint_1"); 
    trajectoryMessage.joint_names.push_back("joint_2"); 
    trajectoryMessage.joint_names.push_back("joint_3"); 
    trajectoryMessage.joint_names.push_back("joint_4"); 
    trajectoryMessage.joint_names.push_back("joint_5"); 


    // Create Joint Trajectroy Point 
    trajectory_msgs::JointTrajectoryPoint trajectoryPoint; 
    trajectoryPoint.time_from_start = ros::Duration(0.1); 
    trajectoryPoint.positions = {q1, q2, q3, q4, gripperOpening}; 

    trajectoryMessage.points = {trajectoryPoint}; 
    // Send information 
    configPublisher.publish(trajectoryMessage); 
    ROS_INFO_STREAM("sending: " << trajectoryMessage); 
    

}


int main(int argc, char** argv){
    ros::init(argc, argv, "bvh_translator"); 
    ros::NodeHandle nh;     

    ros::Subscriber sub = nh.subscribe("/neuron/body", 1000, callback); 
    px_msgs::pxConfig config; 

    configPublisher = nh.advertise<trajectory_msgs::JointTrajectory>("/joint_trajectory", 1000); 
    gripper = nh.serviceClient<px_msgs::gripperPose>("/setGripper"); 


    ros::spin();
    return 0; 
}


// Distance 
float dist(float x1, float y1, float z1, float x2, float y2, float z2 ){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2,2) + pow(z1 - z2, 2)); 
}


// ikinem

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
    q3 = -(q3 - 3.1415/2); 
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