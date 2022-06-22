
const byte char_num = 32;
char received_chars[char_num] = {0};
char temp_chars[char_num] = {0};
char from_pc[char_num] = {0};
int event_code = 0;
boolean new_event = false;

int rover_dir;
int rover_str;
int rover_spd;

void setup() {
  Serial.begin(115200);
  Setup_Motors();
  rover_stop();
  Setup_Leds();
  leds_off();  
  startup_leds();
}


void loop() {

  get_data();
  
  if (new_event == true) {
    strcpy(temp_chars, received_chars);
    parse_data();
    rover_move(rover_dir, rover_str, rover_spd);
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
  Serial.print("  STR: ");
  Serial.print(rover_str);
  Serial.print("  SPD: ");
  Serial.println(rover_spd);
}

void parse_data() {

    char * strtokIndex;

    strtokIndex = strtok(temp_chars, ",");
//    Serial.print(strtokIndex);
//    Serial.print("   ");
    rover_dir = atoi(strtokIndex);

    strtokIndex = strtok(NULL, ",");
//    Serial.print(strtokIndex);
//    Serial.print("   ");
    rover_str = atoi(strtokIndex);
    
    strtokIndex = strtok(NULL, ",");
//    Serial.print(strtokIndex);
    rover_spd = atoi(strtokIndex);
//    Serial.println(); 
}
