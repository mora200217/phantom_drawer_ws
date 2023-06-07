
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

# Laboratorio #5 Robótica
Quinto laboratorio de la asignatura de Robótica de la Universidad Nacional de Colombia 2023-i.


**Integrantes**: 
* Nelson David Ramírez Marín
* Andrés Zuleta 
* Andrés Morales Martínez


## Planteamiento del Problema 
Se busca generar figuras, letras y otras funcionalidades con el Phantom X, aplicando la cinematica inversa del mismo.
 
## Desarrollo 




