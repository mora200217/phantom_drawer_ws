
/**
 * Calculate Inverse Kinematics
*/
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
    q3 = -(q3 - PI/2); 
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