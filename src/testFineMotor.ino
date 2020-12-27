/*
 * ######################
 * ## File Information ##
 * ######################
 * 
 * testBraccioMotorPoint.ino
 * 
 * Test the braccio using the serial port and set the correct angles
 * 
 * Created on 27 Dec 2020
 * by Electrokido
 * 
 * This example is not in the public domain
 */

// Using the libraries

#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int motorToMove;
int degreeToMove;
int inputStatus;

void setup() {
  // Setup for the Braccio and Serial Port
  Braccio.begin();
  Serial.begin(9600);
  
}

void loop() {
  // When the data is available, get it and then store it
  if (Serial.available() > 0) {
    if (inputStatus == 0) {
      while(Serial.available() == 0) {
      } 
      motorToMove = Serial.parseInt();
      inputStatus = 1;
      Serial.println("Moving motor " + String(motorToMove) + ".");
    }
    else if (inputStatus == 1) {
      while(Serial.available() == 0) {
      } 
      degreeToMove = Serial.parseInt();
      inputStatus = 0;
      Serial.println(" to " + String(degreeToMove) + " degrees.");
      move(motorToMove, degreeToMove); // Finally, move the motor
    }
  }
}

int move( int motor, int degree ) {
  // Move to the angle dependent on the motor
  if (motor == 1) {
    Braccio.ServoMovement(20,  degree, 90, 90, 90, 90, 73);
  }
  if (motor == 2) {
    Braccio.ServoMovement(20,  90, degree, 90, 90, 90, 73);
  }
  if (motor == 3) {
    Braccio.ServoMovement(20,  90, 90, degree, 90, 90, 73);
  }
  if (motor == 4) {
    Braccio.ServoMovement(20,  90, 90, 90, degree, 90, 73);
  }
  if (motor == 5) {
    Braccio.ServoMovement(20,  90, 90, 90, 90, degree, 73);
  }
  if (motor == 6) {
    Braccio.ServoMovement(20,  90, 90, 90, 90, 90, degree);
  }
  return 1;
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

*/
