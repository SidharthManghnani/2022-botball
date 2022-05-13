#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

  void drive(int speed, int dist)
    {
        
       set_create_distance(0);
       while (abs(get_create_distance()) < dist) 
       {
           create_drive_direct(speed, speed);
       }
   }
  
     
    void spin_turn(int speed, int angle)
    {
        set_create_total_angle(0);
        	while (get_create_total_angle() < angle)
            {
                printf("%d\n", get_create_total_angle());
            	create_drive_direct(speed, -speed);
                msleep(100);
            }
            create_drive_direct(0,0);
    }
 int main()
 {
    create_connect();
	//resets servos
          set_servo_position(0, 2047);
    enable_servo(0);
    msleep(100);
    set_servo_position(3, 0);
    enable_servo(3);
    msleep(100);
  
     
    drive(200, 670);
    msleep(100);
    create_stop();
         
    spin_turn(-50, 90);
    msleep(100);
    create_stop();
     
    drive(200, 770);
    msleep(100);
    create_stop();
     
     
     set_servo_position(3,1450);
     enable_servo(3);
     msleep(1500);
    
     
     set_servo_position(0, 350);
     enable_servo(0);
     msleep(1500);
     
     drive(-200, 335);
     msleep(100);
     create_stop();
     
     spin_turn(-50, 120);
     msleep(100);
     create_stop(); 
     
     drive(100, 670);
     msleep(100);
     create_stop();
     
    
     create_disconnect();
    return 0;
     
}
