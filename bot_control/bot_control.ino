
const byte char_num = 32;
char received_chars[char_num] = {0};
char temp_chars[char_num] = {0};
char from_pc[char_num] = {0};
int event_code = 0;
boolean new_event = false;

int rover_dir;
int rover_spd;

void setup() {
  Serial.begin(9600);
  Setup_Motors();
  Rover_Stop();
  Setup_Leds();
  delay(1000);
  leds_off();
}


void loop() {

  get_data();

  if (new_event == true) {
    strcpy(temp_chars, received_chars);
//    move_rover();
    parse_data();
    print_data();
    new_event = false;
  }

}

void get_data() {

  static boolean recv_in_progress = false;
  static byte index = 0;
  char start_marker = '<';
  char end_marker = '>';
  char received;

  while (Serial.available() > 0 && new_event == false) {
    received = Serial.read();
    if (recv_in_progress == true) {

      if (received != end_marker) {
        received_chars[index] = received;
        index += 1;
        if (index >= char_num) {
          index = char_num - 1;
        }
      }

      else {
        received_chars[index] = '\0';
        recv_in_progress = false;
        index = 0;
        new_event = true;
      }

    }
    else if (received == start_marker) {
      recv_in_progress = true;
    }
  }

}

void print_data() {

  Serial.print("DIR: ");
  Serial.print(rover_dir);
  Serial.print("  SPD: ");
  Serial.println(rover_spd);
//  for (int i = 0; i < char_num; i++) {
//    Serial.print(temp_chars[i]);
//    //    temp_chars[i] = 0;
//  }
//  Serial.println();
}

void parse_data() {      // split the data into its parts

    char * strtokIndex;

//    strtokIndex = strtok(tempChars,",");      // get the first part - the string
//    strcpy(messageFromPC, strtokIndex); // copy it to messageFromPC
 
    strtokIndex = strtok(NULL, ","); // this continues where the previous call left off
    rover_dir = atoi(strtokIndex);     // convert this part to an integer

    strtokIndex = strtok(NULL, ",");
    rover_spd = atoi(strtokIndex);     // convert this part to a float

}


int rover_speed = 200;

void move_rover() {

  char rover_direction = temp_chars[0];
  char rover_bearing = temp_chars[1];

  if (rover_direction == '1') {
    Rover_Forward(rover_speed);
  } else if (rover_direction == '2') {
    Rover_Backward(rover_speed);
  } else if (rover_direction == '0') {
    Rover_Stop();
  }

  if (rover_bearing == '1') {
    Rover_Left(60);
  } else if (rover_bearing == '2') {
    Rover_Right(120);
  } else if (rover_bearing == '0') {
    Rover_Straight(90);
  }

  Serial.print("DIR: ");
  Serial.print(rover_direction);
  Serial.print("  ");
  Serial.print("BER: ");
  Serial.println(rover_bearing);

}
