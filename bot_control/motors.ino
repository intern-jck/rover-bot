#include <Servo.h>
Servo steering;
int steering_pin = 2;

// Rear Motors
const int pwm_a = 6;
const int in_1 = 7;
const int in_2 = 8;

//Front Motors
const int pwm_b = 5;
const int in_3 = 4;
const int in_4 = 3;

void Setup_Motors() {
  
  pinMode(pwm_a, OUTPUT);
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  
  pinMode(pwm_b, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);

  steering.attach(steering_pin);

}

void Motor_Test(int motor_speed, int test_time) {
  
  Serial.println("Forward");
  Rover_Forward(motor_speed);
  delay(test_time);
  
  Serial.println("Stop");
  Rover_Stop();
  delay(test_time);
  
  Serial.println("Backward");
  Rover_Backward(motor_speed);
  delay(test_time);
  
  Serial.println("Stop");
  Rover_Stop();
  delay(test_time);
  
  Serial.println("Left");
  Rover_Left(20);
  delay(test_time);
  
  Serial.println("Staight");
  Rover_Straight(90);
  delay(test_time);
  
  Serial.println("Right");
  Rover_Right(160);
  delay(test_time);
  
  Serial.println("Straight");
  Rover_Straight(90);
  delay(test_time);
  
}

void Rover_Forward(int motor_speed) {
  analogWrite(pwm_a, motor_speed);
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
  analogWrite(pwm_b, motor_speed);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, HIGH);
}

void Rover_Backward(int motor_speed) {
  analogWrite(pwm_a, motor_speed);
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  analogWrite(pwm_b, motor_speed);
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
}

void Rover_Stop() {
  analogWrite(pwm_a, 0);
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  analogWrite(pwm_b, 0);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, LOW);
}

void Rover_Steering(int pos) {
  steering.write(pos);
}

void Rover_Left(int pos) {
  steering.write(pos);
}

void Rover_Right(int pos) {
  steering.write(pos);
}

void Rover_Straight(int pos) {
  steering.write(pos);
}
