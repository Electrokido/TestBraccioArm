 /*
 * ######################
 * ## File Information ##
 * ######################
 * 
 * testBraccioAllMotors.ino 
 * testBraccio90 is a setup sketch to check the movements of all the servo motors
 * Created on 18 Nov 2015
 * by Electrokido
 * This example is not in the public domain.
 * 
 */

#include <Braccio.h>
#include <Servo.h>


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int motorToMove;

void setup() {  
  Braccio.begin();
  Serial.begin(9600);
  Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
}

void loop() {

  if (Serial.available() > 0) {
     motorToMove = Serial.read();
     if (motorToMove == 1) {
      Serial.println("Moving motor 1");
      Braccio.ServoMovement(20,         0, 90, 90, 90, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         180, 90, 90, 90, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
     }
     if (motorToMove == 2) {
      Serial.println("Moving motor 2");
      Braccio.ServoMovement(20,         90, 15, 90, 90, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 165, 90, 90, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
     }
     if (motorToMove == 3) {
      Serial.println("Moving motor 3");
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 0, 90, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 180, 90, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
     }
     if (motorToMove == 1) {
      Serial.println("Moving motor 4");
      Braccio.ServoMovement(20,         90, 90, 90, 0, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 180, 90,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
     }
     if (motorToMove == 1) {
      Serial.println("Moving motor 5");
      Braccio.ServoMovement(20,         90, 90, 90, 90, 0,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 180,  73);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
     }
     if (motorToMove == 1) {
      Serial.println("Moving motor 6");
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  10);
      delay(1000);
      Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
     }
  }
    
   
}

/*
 * #########################
 * ## General Referencing ##
 * #########################
 * 
 * # Motor Working # 
 * Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
 * M1=base degrees. Allowed values from 0 to 180 degrees
 * M2=shoulder degrees. Allowed values from 15 to 165 degrees
 * M3=elbow degrees. Allowed values from 0 to 180 degrees
 * M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
 * M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
 * M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
 * 
 * 
*/
