#include <Servo.h>
Servo steering;
const int STEERING_PIN = 2;

// Rear Motors
const int PWM_A = 6;
const int IN_1 = 7;
const int IN_2 = 8;

//Front Motors
const int PWM_B = 5;
const int IN_3 = 4;
const int IN_4 = 3;

void Setup_Motors() {  
  pinMode(PWM_A, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);  
  pinMode(PWM_B, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  steering.attach(STEERING_PIN);
}

void rover_move(int dir, int str, int spd) {

  rover_steering(str);

  switch(dir) {
  
    case 0:
      rover_stop();
      break;
      
    case 1:
      rover_forward(spd);
      break;   
      
    case 2:
      rover_backward(spd);
      break;
  }

}


void rover_forward(int motor_speed) {
  analogWrite(PWM_A, motor_speed);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
}

void rover_backward(int motor_speed) {
  analogWrite(PWM_A, motor_speed);
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
}

void rover_stop() {
  analogWrite(PWM_A, 0);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(PWM_B, 0);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}

void rover_steering(int pos) {
  steering.write(pos);
}

// Core Functions and Tests
void motor_test(int motor_speed, int test_time) {
  
  Serial.println("Forward");
  rover_forward(motor_speed);
  delay(test_time);
  
  Serial.println("Stop");
  rover_stop();
  delay(test_time);
  
  Serial.println("Backward");
  rover_backward(motor_speed);
  delay(test_time);
  
  Serial.println("Stop");
  rover_stop();
  delay(test_time);
  
  Serial.println("Left");
  rover_steering(20);
  delay(test_time);
  
  Serial.println("Staight");
  rover_steering(90);
  delay(test_time);
  
  Serial.println("Right");
  rover_steering(160);
  delay(test_time);
  
  Serial.println("Straight");
  rover_steering(90);
  delay(test_time);
  
}
