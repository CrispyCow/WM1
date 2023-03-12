// <INCLUDE REQUIRED LIBRARIES>
#include <Servo.h>

// <WM1 PIN DEFINITIONS>
#define M1_PWM 6
#define M1_DIR 7

#define M2_PWM 3
#define M2_DIR 8

#define M3_PWM 5
#define M3_DIR 12

#define M4_PWM 11
#define M4_DIR 13

#define RELAY1 2
#define RELAY2 4

#define SERVO1 9
#define SERVO2 10

// <GLOBAL DECLARATIONS>
Servo firstServo;  // create servo object to control servos
Servo secondServo; // two servo objects can be created using the functionallity available on the WM1

int pos = 0;    // variable to store the servo position

/* <WIRING DESCRIPTION>                        
  Standard 5V 180° RC servos are connected to WM1 servo header 'S1' and 'S2'
  Ensure servo pinout matches that of the WM1 board
*/

/* <FUNCTIONALITY DESCRIPTION>
  This example code demonstrates how to use the servo headers built into the WM1 to control two
  standard 180° RC servos. This code is based on the standard arduino 'Sweep' example and will
  move both servos back and forth from 0° to 180°
*/

void setup() {
  // put your setup code here, to run once:

  // <ASSIGN PINS TO THE SERVO OBJECTS>
  // Used Pins 
  firstServo.attach(SERVO1);
  secondServo.attach(SERVO2);

  /* <CONFIGURE ALL REMAINING WM1 PINS AS OUTPUTS>
    while not all pins are used in this example it is good practice to 
    configure unused pins them as outputs so that they are not left floating */ 
  // Unused pins   
  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M3_DIR, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    firstServo.write(pos);              // tell servos to go to position in variable 'pos'
    secondServo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    firstServo.write(pos);              // tell servos to go to position in variable 'pos'
    secondServo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
