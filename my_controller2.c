/*
 * File:          my_controller2.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>
#include <stdio.h>
#include <webots/distance_sensor.h>

#include <stdio.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();

  wb_keyboard_enable(TIME_STEP); //milliseconds
  int pressed_key;



  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   //MOTOR devices
   WbDeviceTag wheel_right = wb_robot_get_device("motor_right");
   WbDeviceTag wheel_left = wb_robot_get_device("motor_left");

   wb_motor_set_position(wheel_right, 0);
   wb_motor_set_position(wheel_left, 0);

   //Distance sensor devices

   WbDeviceTag dist_sensor = wb_robot_get_device("distance_sensor");

   wb_distance_sensor_enable(dist_sensor, TIME_STEP);

   double ds_value;

   //double ds_value;

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */


  while (wb_robot_step(TIME_STEP) != -1) {

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
    //ds_value = wb_distance_sensor_get_value(dist_sensor);
    /* Process sensor data here */
    ds_value =wb_distance_sensor_get_value(dist_sensor);
    printf("distance_sensor: %lf\n", ds_value);
    
    pressed_key = wb_keyboard_get_key();


    wb_motor_set_position(wheel_right, INFINITY);
    wb_motor_set_position(wheel_left, INFINITY);

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
      if(pressed_key == WB_KEYBOARD_DOWN){

        wb_motor_set_velocity(wheel_right, 10);
        wb_motor_set_velocity(wheel_left,  10);
        }



        else if (pressed_key == WB_KEYBOARD_UP ){

          wb_motor_set_velocity(wheel_right, -10);
          wb_motor_set_velocity(wheel_left, -10);
          }

      else if (pressed_key == WB_KEYBOARD_RIGHT){

         wb_motor_set_velocity(wheel_right, 5);
         wb_motor_set_velocity(wheel_left, 0);
          }


       else if (pressed_key == WB_KEYBOARD_LEFT){

          wb_motor_set_velocity(wheel_right,0);
          wb_motor_set_velocity(wheel_left, 5);
           }
       else {
         wb_motor_set_position(wheel_right, 0);
         wb_motor_set_position(wheel_left, 0);
         wb_motor_set_velocity(wheel_right, 0);
         wb_motor_set_velocity(wheel_left, 0);
         }


  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
