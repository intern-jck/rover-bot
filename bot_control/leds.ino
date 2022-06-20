const int led1 = 14;
const int led2 = 15;
const int led3 = 16;
const int led4 = 17;

void Setup_Leds() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);  
  pinMode(led4, OUTPUT);
}


void leds_on() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

void leds_off() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}


void led_on(int pin) {
  digitalWrite(pin, HIGH);
}

void led_off(int pin) {
  digitalWrite(pin, LOW);  
}

void blink_leds(int ms) {
  leds_on();
  delay(ms);
  leds_off();
  delay(ms);
}
