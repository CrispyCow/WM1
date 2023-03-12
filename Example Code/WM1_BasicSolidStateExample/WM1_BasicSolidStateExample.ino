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
int duty = 0;    // variable to store duty cycle which controls the motor's effective voltage (range 0-255)

/* <WIRING DESCRIPTION>                        
Standard brushed DC gearmotor wired to M1 outputs
*/

/* <FUNCTIONALITY DESCRIPTION>
  This example code demonstrates how to use one of the WM1's four solid state motor drivers
  to PWM/voltage control a brushed DC motor. This allows the user to vary a motors speed.

  Using this code, the motor's speed should ramp up to the maximum and then ramp back down to zero.
  The dirrection will then swap and the motor speed will ramp up and down spinning the other way.
*/

void setup() {
  // put your setup code here, to run once:

  /* <CONFIGURE ALL WM1 PINS AS OUTPUTS>
    while not all pins are used in this example it is good practice to 
    configure them as outputs so that they are not left floating */
  // Used Pins    
  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR, OUTPUT);
  // Unused pins
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

  // DIR pin dictates motor's dirrection
  // PWM pin dictates the motor's voltage, which loosley controls speed

  // <SET M1 DIRECTION TO FORWARDS>
  digitalWrite(M1_DIR, HIGH); 

  // <RAMP SPEED UP AND THEN DOWN>
  for (duty = 0; duty <= 255; duty += 1) {  // loop will increase variable 'duty' up from 0 to 255
    analogWrite(M1_PWM, duty);              // motor 1 duty cycle set to value of variable 'duty'
    delay(4);                               // delay will wait 4ms to slow loop down                
  }
  for (duty = 255; duty >= 0; duty -= 1) {  // loop will decrease variable 'duty' down from 255 to 0
    analogWrite(M1_PWM, duty);              // motor 1 duty cycle set to value of variable 'duty'
    delay(4);                               // delay will wait 4ms to slow loop down                
  }


  // <SET M1 DIRECTION TO BACKWARDS>
  digitalWrite(M1_DIR, LOW); 

  // <RAMP SPEED UP AND THEN DOWN>
  for (duty = 0; duty <= 255; duty += 1) {  // loop will increase variable 'duty' up from 0 to 255
    analogWrite(M1_PWM, duty);              // motor 1 duty cycle set to value of variable 'duty'
    delay(4);                               // delay will wait 4ms to slow loop down                
  }
  for (duty = 255; duty >= 0; duty -= 1) {  // loop will decrease variable 'duty' down from 255 to 0
    analogWrite(M1_PWM, duty);              // motor 1 duty cycle set to value of variable 'duty'
    delay(4);                               // delay will wait 4ms to slow loop down                
  }

}
