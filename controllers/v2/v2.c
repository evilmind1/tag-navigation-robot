#include <stdio.h>
#include <webots/camera.h>
#include <webots/camera_recognition_object.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include <string.h>


#define SPEED 3
#define TIME_STEP 64

int main() {
  WbDeviceTag camera, left_motor, right_motor;
  int i;
  wb_robot_init();
  
  camera = wb_robot_get_device("camera");
  wb_camera_enable(camera, TIME_STEP);
  wb_camera_recognition_enable(camera, TIME_STEP);

    
  while (wb_robot_step(TIME_STEP) != -1) {
    int number_of_objects = wb_camera_recognition_get_number_of_objects(camera);
    printf("\nRecognized %d objects.\n", number_of_objects);
    
    const WbCameraRecognitionObject *objects = wb_camera_recognition_get_objects(camera);
    for (i = 0; i < number_of_objects; ++i) {
    int height, width;
    int area;
    char *model;
    model = objects[i].model;
    height = objects[i].size_on_image[0];
    width = objects[i].size_on_image[1];
    area = height * width;
  left_motor = wb_robot_get_device("left wheel motor");
  right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);
  wb_motor_set_velocity(right_motor, 0.0);
 int number_of_objects = wb_camera_recognition_get_number_of_objects(camera);
 printf("\nRecognized %d objects.\n", number_of_objects);
   
   
    if ((strcmp(model, "right")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, -SPEED);
    wb_robot_step(900);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    else if ((strcmp(model, "left")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, -SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(900);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    else if ((strcmp(model, "right135")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, -SPEED);
    wb_robot_step(1350);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    else if ((strcmp(model, "right45")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, -SPEED);
    wb_robot_step(450);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    else if ((strcmp(model, "uright")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, -SPEED);
    wb_robot_step(900);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(1000);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, -SPEED);
    wb_robot_step(860);
    }
    else if ((strcmp(model, "uleft")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, -SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(900);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(1000);
    wb_motor_set_velocity(left_motor, -SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(860);
    }
    else if ((strcmp(model, "left135")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, -SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(1350);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    else if ((strcmp(model, "left45")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, -SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    wb_robot_step(450);
    wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    else if ((strcmp(model, "stop")==0) && (area > 354590)){
    wb_motor_set_velocity(left_motor, 0);
    wb_motor_set_velocity(right_motor, 0);
    }
    else {
     wb_motor_set_velocity(left_motor, SPEED);
    wb_motor_set_velocity(right_motor, SPEED);
    }
    
      printf("Model of the object = %s\n", model);
      printf("height, width = %d , %d\n", height, width);
      printf("area = %d\n", area);
    }
    
  }

  wb_robot_cleanup();

  return 0;
}