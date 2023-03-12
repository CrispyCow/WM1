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

/* <WIRING DESCRIPTION>                        
Standard brushed DC gearmotor wired to use relays as a full-bridge/H-bridge, with one terminal connected
to R1 and the other connected to R2.
*/

/* <FUNCTIONALITY DESCRIPTION>
  This example code demonstrates how to use the two single pole double throw (SPDT) relays on the WM1
  as a full-bridge/H-bridge to provide bi-dirrectional control of a single motor.

  Using this code the motor should spin for 2 seconds, stop for 2 seconds, spin the opposite dirrection
  for 2 seconds, then stop for 2 seconds again.
*/

void setup() {
  // put your setup code here, to run once:

  /* <CONFIGURE ALL WM1 PINS AS OUTPUTS>
    while not all pins are used in this example it is good practice to 
    configure them as outputs so that they are not left floating */
  // Used Pins    
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  // Unused pins
  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M3_DIR, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);
  pinMode(SERVO1, OUTPUT);
  pinMode(SERVO2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // <DRIVE MOTOR FORWARDS>
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, LOW);

  delay(2000); // wait 2 seconds

  // <STOP MOTOR>
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);

  delay(2000); // wait 2 seconds

  // <DRIVE MOTOR BACKWARDS>
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, HIGH);

  delay(2000); // wait 2 seconds

  // <STOP MOTOR>
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);

  delay(2000); // wait 2 seconds
  
}
