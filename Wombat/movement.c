#include <defaults.h>
#include <kipr/wombat.h>
#include <movement.h>

void forward(int mm, int speed) {
    double circumference = wheel_diameter * PI;
    int distance = (mm/circumference) * 1800; //in ticks
       
    cmpc(LEFTMOTOR);
    cmpc(RIGHTMOTOR);
    while (gmpc(LEFTMOTOR) < distance)   {
        motor(LEFTMOTOR, speed);
        motor(RIGHTMOTOR, speed);
    }
    freeze(LEFTMOTOR);
    freeze(RIGHTMOTOR);
}

void forwardForSeconds(int speed, int timeMillis) {
    motor(LEFTMOTOR, speed);
    motor(RIGHTMOTOR, speed);
       
    msleep(timeMillis);
    freeze(LEFTMOTOR);
    freeze(RIGHTMOTOR);
}

int mm_to_tick(int mm);

void turn(int leftmotorspeed, int rightmotorspeed, int ticks);

void turn_spin(int degrees, int direction);

void turn_left_spin(int degrees) {
    turn_spin(degrees, 1);
}

void turn_right_spin(int degrees) {
    turn_spin(degrees, 0);
}

// 0 = right, 1 = left
void turn_spin(int degrees, int direction) {
    cmpc(LEFTMOTOR);
    cmpc(RIGHTMOTOR);
    
    int circumference = PI * DISTANCE_BETWEEN_WHEELS_MM;
    int mm = circumference / (360 / degrees);
    int ticks = mm_to_tick(mm);

    if (direction) {
    	mrp(LEFTMOTOR, -1000, -ticks);
    	mrp(RIGHTMOTOR, 1000, ticks);
    } else {
    	mrp(LEFTMOTOR, 1000, ticks);
    	mrp(RIGHTMOTOR, -1000, -ticks);
    }
}

void turn_pivot(int degrees, int direction);

void turn_left_pivot(int degrees) {
    turn_pivot(degrees, 1);
}

void turn_right_pivot(int degrees) {
    turn_pivot(degrees, 0);
}

// 0 = right, 1 = left
void turn_pivot(int degrees, int direction) {
    cmpc(LEFTMOTOR);
    cmpc(RIGHTMOTOR);
    int circumference = 2 * PI * DISTANCE_BETWEEN_WHEELS_MM;
    int mm = circumference / (360/degrees);
    int ticks = mm_to_tick(mm);

    if (direction) {
        mrp(RIGHTMOTOR, 1000, ticks);
    } else {
        mrp(LEFTMOTOR, 1000, ticks);
    }
}

int mm_to_tick(int mm) {
    int circumference = wheel_diameter * PI;
    int ticks_per_mm = TICKS_IN_ROTATION / circumference;
    return ticks_per_mm * mm;
    
}

void rings() {
    forwardForSeconds(30,1000);
    msleep(1);
set_servo_position(2,180);
    msleep(1);
    forwardForSeconds(-30,3300);
    msleep(1);

    int startPos = get_servo_position(2);
    int step = (1500-startPos)/50;
    int i = startPos;
    for(i = startPos; i<=1500; i+=step){
    set_servo_position(2,i); 
        msleep(50);
    }
    forwardForSeconds(30,3000);
    turn_left_pivot(90);
    set_servo_position(2,175);
}
