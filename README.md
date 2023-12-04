
Clone this workspace (WS) and compile the packages either using catkin_make or catkin build. 
```bash
$ catkin build
```
source the compiled files
```bash
$ source devel/setup.bash
```

To activate the robot use `/dynamixel_workbench` to open the `JointTrajectory` topic for changing the manipulator configuration. 
```bash
$ roslaunch px_robot px_controllers.launch
```

## How to vizualize different positions with rviz 
Start the nodes. 
```bash
$ roslaunch px_planner check_ikinem.launch
```

<p align="center">
  <img width="60%" src="https://github.com/mora200217/phantom_drawer_ws/blob/master/imgs/rviz_config.png" /> 
</p>

After rviz has been initizalizated correctly, you can call the ikinem service in order to vizualize the config for the desiredpose of the end-effector. 

source the compiled files
```bash
$ source devel/setup.bash
```

```bash
$ rosservice call /px_planner/px_ikinem "desiredPosition:
  x: 13.0
  y: 21.0
  z: 0"
```

## How to use the perception neuron 
In the package `px_neuron` you will find the axis-streamer submodule. Begin installing the required modules. 

```
$ yarn install # or npm install
```

Then, open two terminal windows. In the first one, lets launch the `perception.launch` file, which will build up the whole archiqueture of the system. 

> Remember to update the network configuration, by exporting ROS_IP and ROS_MASTER_URI. see http://wiki.ros.org/ROS/NetworkSetup for more information 

In the second terminal, run 
```
$ yarn run with --mode stream
```

This will open the webserver for vizualizing the BVH from axis neuron, and open the broadcasting routine for publishing to rostopic from roslibjs. (A connected alert should appear if everything is alright). 

I








