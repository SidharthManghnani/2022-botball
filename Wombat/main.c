#include <kipr/wombat.h>
#include <unistd.h>
#include <defaults.h>
#include <movement.h>
#include <linefollowing.h>

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
