const int LED_1 = 14;
const int LED_2 = 15;
const int LED_3 = 16;
const int LED_4 = 17;

byte led_1_val = 0;
byte led_2_val = 0;
byte led_3_val = 0;
byte led_4_val = 0;

void Setup_Leds() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);  
  pinMode(LED_4, OUTPUT);
}

void startup_leds() {
  
  led_on(14);
  delay(500);
  led_on(LED_2);
  delay(500);
  led_on(LED_3);
  delay(500);
  led_on(LED_4);
  delay(500);

  leds_off();
  delay(250);
  leds_on();
  delay(250);
  
  leds_off();
  delay(250);
  leds_on();
  delay(250);
  
  leds_off();
  delay(250);
  leds_on();
  delay(250);
}

void leds_off() {
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, HIGH);

}

void leds_on() {
//  led_pwm(LED_1, 10);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
}

void led_on(int pin) {
  digitalWrite(pin, LOW);
}

void led_off(int pin) {
  digitalWrite(pin, HIGH);  
}

void blink_leds(int ms) {
  leds_on();
  delay(ms);
  leds_off();
  delay(ms);
}
