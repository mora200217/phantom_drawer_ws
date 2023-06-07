
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
Se busca generar figuras, letras y otras funcionalidades con el Phantom X, aplicando la cinematica inversa del mismo y que estos procesos se logren visualizar en una HMI.
 
## Descripción e la solución planteada

Dht

Se encontró el modelo geómetrico inverso bajo la condicion de una orientación de la herramienta horizontal, para poder garantizar una correcta escritura en el tablero con el marcador.

Se usó ROS para definir un stack de servicios y topicos que permitan: 
- Ajustar la posición del gripper [Servicio] 
- Calcular la configuracion para cierta pose del efector [Servicio] 
- Mover el efector final a una posición en el espacio diestro [Servicio]

El archivo `px_planner/check_ikinem` con los parámetros `show_rviz` y `console_gui` permite mostrar la configuración actual del phantom en rviz y tener una gui en la terminal para mover el gripper y posicionar a la posición de home. 

## 

## Imagenes HMI

<p align="center">
<img margin="auto" src="https://github.com/mora200217/wireless-phantom-ros-controller/blob/master/imgs/dhparams.png" width="60%"/> 
</p> 

## Video resumen completo laboratorio


## Analisis y resultados de la verificacion dimensional




