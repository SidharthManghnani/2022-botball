    #include <kipr/botball.h>
    #include <linefollower.h>

void linefollowfordistance_cm (int sensor_port, int distancein_cm)

{
    float distanceTraveled;
    if (sensor_port == lightsensorport_left);
    
        while (distanceTraveled < distancein_cm)
        {
            if (analog(sensor_port) > 1600)
            {
                motor(motor_right, 90);
                motor(motor_left, 5);
            }
            else
            {
                motor(motor_right, 5);
                motor(motor_left, 90);
            }
            ao();
            
            (get_motor_position_counter(motor_left) + get_motor_position_counter(motor_right))*cmPerTick = distanceTraveled;
        }
    if (sensor_port == lightport_right);
    
        while (distanceTraveled < distancein_cm)
    {
            if (analog(sensor_port) > 1600)
            {
                motor(motor_left, 90);
                motor(motor_right, 5);
            }
            else
            {
                motor(motor_left, 5);
                motor(motor_right, 90);
            }
            ao();
            
            (get_motor_position_counter(motor_left) + get_motor_position_counter(motor_right))*cmPerTick = distanceTraveled;
    }
}