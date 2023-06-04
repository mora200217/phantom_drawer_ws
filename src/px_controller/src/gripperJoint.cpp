#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<trajectory_msgs::JointTrajectory>("/joint_trajectory", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("/gripper_state", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const std_msgs::Float32::ConstPtr& gripper_state)
  {
    float gripperState = gripper_state.get()->data; 

    trajectory_msgs::JointTrajectory jointTraj; 
    
    jointTraj.header.stamp = ros::Time::now(); 
    jointTraj.joint_names.push_back("joint_5"); // only gripper 

    // Point definition 
    trajectory_msgs::JointTrajectoryPoint point; 
    point.positions = {gripperState}; 
    point.time_from_start = ros::Duration(0.7); 

    jointTraj.points = { point }; 

    pub_.publish(jointTraj);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "gripper_state_translator");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}