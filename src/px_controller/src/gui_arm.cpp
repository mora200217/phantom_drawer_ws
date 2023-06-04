#include "ros/ros.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>

#include "gui_arm.h"
#include "px_msgs/home.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "std_msgs/Float32.h"
char key(' ');


// services 
ros::ServiceClient homeSrv; 
ros::ServiceClient homeGripper; 

// Publishers 
ros::Publisher gripperPublisher; 
ros::Publisher positionPublisher; 

int main(int argc, char**argv){
    ros::init(argc, argv, "gui_arm_controller"); 
    ros::NodeHandle n; 

    // Create services 
    homeSrv = n.serviceClient<px_msgs::home>("/goHome"); 

    // create publishers 
    gripperPublisher = n.advertise<std_msgs::Float32>("/gripper_state", 1000); 
    

    std_msgs::Float32 gripperState;
    gripperState.data = 0.0;  

     printf("%s", msg); // GUI message

     while(ros::ok()){
            key = getch();
            
    
     // Flujo de control 
    switch (key)
    {   
    case 'k':
        // ROS_INFO("Up"); 
        gripperState.data -= 0.1; 
        break;

    case 'l':
        gripperState.data += 0.1; 
        break;

    case 'w':
        gripperState.data += 0.1; 
        break;

    case 's':
        gripperState.data += 0.1; 
        break;

    case 'h':
        px_msgs::home homeSrvReq; 
        homeSrv.call(homeSrvReq); 
        break;
    }

    gripperPublisher.publish(gripperState); 
    
    // Cancel node 
    if (key == '\x03'){
        printf("Gracias por usar turtle_teleop_key2\n Apoyanos en nuestro repo en GH <3");
        break;
    }
    ros::spinOnce();
     }

    return 0; 
}



int getch(void)
{
  int ch;
  struct termios oldt;
  struct termios newt;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_iflag |= IGNBRK;
  newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
  newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newt);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}