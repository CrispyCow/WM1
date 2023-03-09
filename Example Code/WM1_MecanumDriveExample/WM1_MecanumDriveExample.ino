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

// <CONSTANT DEFINITIONS>
#define duty 255  // motor duty cycle between 0-255
#define wait 4000 // time delay between each action in ms

/* <MOTOR ARRANGEMENTS>                        
Front Left wired to M3  |  Front Right wired to M1
------------------------+-------------------------
Back Left wired to M4   |  Back Right wired to M2
*/

/* <EXAMPLE FUNCTIONALITY DESCRIPTION>
  This example code demonstrates how to use the WM1's 4 solid state motor drivers
  to control individual wheels of a mecanum wheeled rover. The code steps thorugh
  various basic maneuvers such as driving, strafing, and turning on the spot.
*/

void setup() {
  // put your setup code here, to run once:

  /* <CONFIGURE ALL WM1 PINS AS OUTPUTS>
    while not all pins are used in this example it is good practice to 
    configure them as outputs so that they are not left floating */    
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
  pinMode(SERVO1, OUTPUT);
  pinMode(SERVO2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // <MOVE FORWARD>
  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M2_DIR, HIGH);   
  digitalWrite(M3_DIR, HIGH);   
  digitalWrite(M4_DIR, HIGH); 

  analogWrite(M1_PWM, duty);
  analogWrite(M2_PWM, duty);
  analogWrite(M3_PWM, duty);
  analogWrite(M4_PWM, duty);   

  delay(wait);

  // <MOVE BACKWARDS>
  digitalWrite(M1_DIR, LOW); 
  digitalWrite(M2_DIR, LOW);   
  digitalWrite(M3_DIR, LOW);   
  digitalWrite(M4_DIR, LOW); 

  delay(wait);

  // <STOP>
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);

  delay(wait);

  // <STRAFE LEFT>
  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M2_DIR, LOW);   
  digitalWrite(M3_DIR, LOW);   
  digitalWrite(M4_DIR, HIGH); 

  analogWrite(M1_PWM, duty);
  analogWrite(M2_PWM, duty);
  analogWrite(M3_PWM, duty);
  analogWrite(M4_PWM, duty); 

  delay(wait);

  // <STRAFE RIGHT>
  digitalWrite(M1_DIR, LOW); 
  digitalWrite(M2_DIR, HIGH);   
  digitalWrite(M3_DIR, HIGH);   
  digitalWrite(M4_DIR, LOW); 

  analogWrite(M1_PWM, duty);
  analogWrite(M2_PWM, duty);
  analogWrite(M3_PWM, duty);
  analogWrite(M4_PWM, duty); 

  delay(wait);

  // <STOP>
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0); 

  delay(wait);

    // <TURN LEFT>
  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M2_DIR, HIGH);   
  digitalWrite(M3_DIR, LOW);   
  digitalWrite(M4_DIR, LOW); 

  analogWrite(M1_PWM, duty);
  analogWrite(M2_PWM, duty);
  analogWrite(M3_PWM, duty);
  analogWrite(M4_PWM, duty);
  
  delay(wait);

  // <TURN RIGHT>
  digitalWrite(M1_DIR, LOW); 
  digitalWrite(M2_DIR, LOW);   
  digitalWrite(M3_DIR, HIGH);   
  digitalWrite(M4_DIR, HIGH); 

  analogWrite(M1_PWM, duty);
  analogWrite(M2_PWM, duty);
  analogWrite(M3_PWM, duty);
  analogWrite(M4_PWM, duty); 

  delay(wait);

  // <STOP>
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);

  delay(wait);
}
