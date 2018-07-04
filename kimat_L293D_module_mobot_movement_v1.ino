
/***************************************************************************
 Example Code to move the motor of a 2 (or 4) wheel robot driven by the Kimat L293D Motor Driver Module.
 This is meant as a first test code. It moves the robot forward, backward, left and right with certain time intervals.
 
 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
  
 Author(s): C.D.Malecdan for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2017/08/17 - initial creation
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 +63-916-442-8565

 * NOTES and WARNINGS:
 * Install right motor(s) on OUT1 and OUT2
 * Install left motor(s) on OUT3 and OUT4
 * 
 * REG IN JUMPER
 * 
 * 5-12V Motor:
 * If you are working with a 5-12V motor, then set the REG IN jumer to the VM position.
 * This jumper option will take the power for the logic circuit from the Motor Power terminals labeled VM.
 * 
 * >12-20V Motor
 * If you are working on a motor above 12V up to 20V, then you must set the REG IN jumper to the EXT position.
 * You will need to connect a 5-12V / >= 100mA power supply for the logic circuit using the EXT and GND pins.
 * 
 * MOTOR CURRENT:
 * 
 * The L293D is rated for a maximum of 600mA continous motor current and 1.2A surge current per channel. 
 * Make sure your motors do not exceed these ratings.
 * 
 * SPEED CONTROL / EN1 and EN2 JUMPERS
 * 
 * If you do not plan to control speed and want to operate at full speed, leave the EN1 and EN2 jumpers installed.
 * If you want to control speed using PWM, remove the jumpers and connect EN1 and EN2 (beside IN4) to PWM pins of your
 * microcontroller. For the Saleng Uno/Arduino Uno, this pins may be used for the EN1/EN2: pins 3,5,6,9,10,11.
 * If you are using the Arduino Mega2560, use pins 2-13.
 ****************************************************************************/

//Pin Assignments:
const byte PIN_IN1 = 6;
const byte PIN_IN2 = 7;
const byte PIN_IN3 = 8;
const byte PIN_IN4 = 9;
const byte PIN_EN1 = 3;
const byte PIN_EN2 = 5;

void speedSetting(byte val)
{
  analogWrite(PIN_EN1,val);
  analogWrite(PIN_EN2,val);
}

void forward()
{
  // move right motor(s) forward
  digitalWrite(PIN_IN1,LOW);
  digitalWrite(PIN_IN2,HIGH);
  // move left motor(s) forward
  digitalWrite(PIN_IN3,LOW);
  digitalWrite(PIN_IN4,HIGH);
}

void backward()
{
  // move right motor(s) backward
  digitalWrite(PIN_IN1,HIGH);
  digitalWrite(PIN_IN2,LOW);
  // move right motor(s) backward
  digitalWrite(PIN_IN3,HIGH);
  digitalWrite(PIN_IN4,LOW);
}

void turnleft()
{
  // move right motor(s) forward
  digitalWrite(PIN_IN1,LOW);
  digitalWrite(PIN_IN2,HIGH);
  // move left motor(s) backward
  digitalWrite(PIN_IN3,HIGH);
  digitalWrite(PIN_IN4,LOW);
}

void turnright()
{
  // move right motor(s) backward
  digitalWrite(PIN_IN1,HIGH);
  digitalWrite(PIN_IN2,LOW);
  // move left motor(s) forward
  digitalWrite(PIN_IN3,LOW);
  digitalWrite(PIN_IN4,HIGH);
}

void motorstop()
{
  digitalWrite(PIN_IN1,LOW);
  digitalWrite(PIN_IN2,LOW);
  digitalWrite(PIN_IN3,LOW);
  digitalWrite(PIN_IN4,LOW);
}


void setup() {
  pinMode(PIN_IN1,OUTPUT);
  pinMode(PIN_IN2,OUTPUT);
  pinMode(PIN_IN3,OUTPUT);
  pinMode(PIN_IN4,OUTPUT);
  pinMode(PIN_EN1,OUTPUT);
  pinMode(PIN_EN2,OUTPUT);
  
  motorstop();
  delay(2000);
  speedSetting(128);

}

void loop() {
  forward(); // call this function to move the robot forward
  delay(1000);
  motorstop();
  delay(500);
  backward();// call this function to move the robot backward
  delay(1000);
  motorstop();
  delay(500);  
  turnright(); // call this function to turn the robot right
  delay(1000);
  motorstop();
  delay(500); 
  turnleft(); // call this function to turn the robot left
  delay(1000);
  motorstop();
  delay(500);   
}
