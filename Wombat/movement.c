#include <movement.h>
#include <robot_constants.h>

void turn_left_spin(int degrees) {
    turn_spin(degrees, 1);
}

void turn_right_spin(int degrees) {
    turn_spin(degrees, 0);
}

// 0 = right, 1 = left
void turn_spin(int degrees, int direction) {
    int circumference = 2 * PI * (DISTANCE_BETWEEN_WHEELS_MM/2);
    int mm = circumference * (degrees/360);
    int ticks = mm_to_tick(mm);

    if (direction) {
        turn(-50, 50, ticks);
    } else {
        turn(50, -50, ticks);
    }
}

void turn_left_pivot(int degrees) {
    turn_pivot(degrees, 1);
}

void turn_right_pivot(int degrees) {
    turn_pivot(degrees, 0);
}

// 0 = right, 1 = left
void turn_pivot(int degrees, int direction) {
    int circumference = 2 * PI * DISTANCE_BETWEEN_WHEELS_MM;
    int mm = circumference * (degrees/360);
    int ticks = mm_to_tick(mm);

    if (direction) {
        turn(0, 50, ticks);
    } else {
        turn(50, 0, ticks);
    }
}

void turn(int leftmotorspeed, int rightmotorspeed, int ticks) {
    motor(LEFTMOTOR, leftmotorspeed);
    motor(RIGHTMOTOR, rightmotorspeed);
    while (gmpc(RIGHTMOTOR) <= ticks) {
        msleep(1);
    }

    motor(LEFTMOTOR, 0);
    motor(RIGHTMOTOR, 0);
}

int mm_to_tick(int mm) {
    return WHEEL_CIRCUMFERENCE_MM / TICKS_IN_ROTATION;
}
