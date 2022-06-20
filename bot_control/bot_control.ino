
void setup() {
  Serial.begin(9600);
}


void loop() {

  if (Serial.available() > 0) {
     char input = Serial.read();
     Serial.println(input);
  }

}
