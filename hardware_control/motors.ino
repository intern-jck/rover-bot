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


int current_key = 0;

void Setup_Motors() {
  
  pinMode(pwm_a, OUTPUT);
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  
  pinMode(pwm_b, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);

  steering.attach(steering_pin);

}




void rover_move(int key, int spd) {
  
   switch(key) {

// Full stop
      case 0:
        Serial.println("All Stop");
        rover_stop();
        rover_straight();
        break;
//        Straighten out after steering
      case 1:
        rover_straight();
        break;       
      // w
      case 87:
        Serial.println("Forward");
        rover_forward(spd);
        break;
//        s
      case 83:
        Serial.println("Backward");
        rover_backward(spd);
        break;
//        a
      case 65:
        Serial.println("Left");
        rover_left(spd);
        break;
//        d
      case 68:
        Serial.println("Right");
        rover_right(spd);
        break;
//        q
      case 81:
        Serial.println("Stop");
        rover_stop();
        break;
        
        break;
//        ArrowUp
      case 38:
        break;
//        ArrowDown
      case 40:
        break;
//        ArrowLeft
      case 37:
        break;
//        ArrowRight
      case 39:
        break;
   
   
   }
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
  rover_left(20);
  delay(test_time);
  
  Serial.println("Staight");
  rover_straight();
  delay(test_time);
  
  Serial.println("Right");
  rover_right(160);
  delay(test_time);
  
  Serial.println("Straight");
  rover_straight();
  delay(test_time);
  
}

void rover_forward(int motor_speed) {
  analogWrite(pwm_a, motor_speed);
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
  analogWrite(pwm_b, motor_speed);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, HIGH);
}

void rover_backward(int motor_speed) {
  analogWrite(pwm_a, motor_speed);
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  analogWrite(pwm_b, motor_speed);
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
}

void rover_stop() {
  analogWrite(pwm_a, 0);
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  analogWrite(pwm_b, 0);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, LOW);
}

void rover_steering(int pos) {
  steering.write(pos);
}

void rover_left(int pos) {
  steering.write(pos);
}

void rover_right(int pos) {
  steering.write(pos);
}

void rover_straight() {
  steering.write(90);
}
