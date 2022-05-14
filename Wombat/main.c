#include <kipr/wombat.h>
#include <unistd.h>
#include <defaults.h>
#include <movement.h>
#include <linefollowing.h>

void rings();

int main() {
    wait_for_light(INIT_LIGHT_SENSOR); // comment for testing
    shut_down_in(119); // just incase
    enable_servos();
    rings();
    sleep(1);
    printf("1\n");
    forwardUntilBlack(RIGHT_COLOR_SENSOR);
    printf("2\n");
   turn_right_pivot(80);
    printf("3\n");
    sleep(1);
    followLineMilliseconds(30000, 100);
    printf("4\n");
    sleep(5);
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

