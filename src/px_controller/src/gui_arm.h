
const char* msg = R"(
-------------------------------
Movimiento
  h: Go to home

Gripper: 
  L: Open Gripper
  K: Close Gripper

Position: 
    w: Move +Y
    s: Move -Y
    a: Move +X
    d: Move -X

    z: Move -Z
    x: Move +Z
-------------------------------
CTRL-C to quit
)";


// turtlesim_node parámetros
const float _HALF_WIDTH = 5.5; 
const float _HALF_HEIGHT = 5.5; 

float _DEFAULT_LINEAR_VEL = 1.5;  // unidades 
float _DEFAULT_ANGULAR_VEL = 1.0; // rads

int getch(void); 

