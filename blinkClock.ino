// Clock Timing Module for UNOAnimatronics Project
const int RATE_CONSTANT = 100;

// Configuring constants to denote relay channels
const int RELAY_CHANNEL_1 = 1;
const int RELAY_CHANNEL_2 = 2;
const int RELAY_CHANNEL_3 = 3;
const int RELAY_CHANNEL_4 = 4;
const int RELAY_CHANNEL_5 = 5;
const int RELAY_CHANNEL_6 = 6;
const int RELAY_CHANNEL_7 = 7;
const int RELAY_CHANNEL_8 = 8;

// Channel Signal Push Constants
const float RELAY_PUSH_1 = 250;
const float RELAY_PUSH_2 = 500;
const float RELAY_PUSH_3 = 1000;
const float RELAY_PUSH_4 = 1500;
const float RELAY_PUSH_5 = 2000;
const float RELAY_PUSH_6 = 2500;
const float RELAY_PUSH_7 = 3000;
const float RELAY_PUSH_8 = 500;

// Channel Signal Pull Constants
const float RELAY_PULL_1 = 250;
const float RELAY_PULL_2 = 500;
const float RELAY_PULL_3 = 500;
const float RELAY_PULL_4 = 500;
const float RELAY_PULL_5 = 500;
const float RELAY_PULL_6 = 500;
const float RELAY_PULL_7 = 500;
const float RELAY_PULL_8 = 1500;

// Elapsed Time Since State-Flip
volatile float CHANNEL_TIME_1 = 0;
volatile float CHANNEL_TIME_2 = 0;
volatile float CHANNEL_TIME_3 = 0;
volatile float CHANNEL_TIME_4 = 0;
volatile float CHANNEL_TIME_5 = 0;
volatile float CHANNEL_TIME_6 = 0;
volatile float CHANNEL_TIME_7 = 0;
volatile float CHANNEL_TIME_8 = 0;

// Executed on-boot
void setup() {
  // Assigns Relay channels to Arduino Pinouts
  pinMode(RELAY_CHANNEL_1, OUTPUT);
  pinMode(RELAY_CHANNEL_2, OUTPUT);
  pinMode(RELAY_CHANNEL_3, OUTPUT);
  pinMode(RELAY_CHANNEL_4, OUTPUT);
  pinMode(RELAY_CHANNEL_5, OUTPUT);
  pinMode(RELAY_CHANNEL_6, OUTPUT);
  pinMode(RELAY_CHANNEL_7, OUTPUT);
  pinMode(RELAY_CHANNEL_8, OUTPUT);
}

// Function to check if it is time to flip state
bool isTime(float CHANNEL_TIME, float CHALLENGE_TIME) { // Challenge Time is either Push or Pull
  float CURRENT_TIME = millis();
  if ((CURRENT_TIME - CHANNEL_TIME) >= CHALLENGE_TIME) {
    CHANNEL_TIME = CURRENT_TIME;
    return true;
  }
  else return false;
}

// Function to Refresh Channel State
void refreshChannel(int RELAY_CHANNEL, float CHANNEL_TIME, float RELAY_PUSH, float RELAY_PULL) {
  if (digitalRead(RELAY_CHANNEL) == HIGH) {
    if (isTime(CHANNEL_TIME, RELAY_PUSH)) {
      // Trigger Flip from HIGH to LOW
      digitalWrite(RELAY_CHANNEL, LOW);
      delay(RATE_CONSTANT);
      }
    ;}
  else if (digitalRead(RELAY_CHANNEL) == LOW) {
    if (isTime(CHANNEL_TIME, RELAY_PULL)) {
      // Trigger Flip from LOW to HIGH
      digitalWrite(RELAY_CHANNEL, HIGH);
      delay(RATE_CONSTANT);
      }
    ;}
;}

// Infinite loop
void loop() {
  refreshChannel(RELAY_CHANNEL_1, CHANNEL_TIME_1, RELAY_PUSH_1, RELAY_PULL_1);
  refreshChannel(RELAY_CHANNEL_2, CHANNEL_TIME_2, RELAY_PUSH_2, RELAY_PULL_2);
  refreshChannel(RELAY_CHANNEL_3, CHANNEL_TIME_3, RELAY_PUSH_3, RELAY_PULL_3);
  refreshChannel(RELAY_CHANNEL_4, CHANNEL_TIME_4, RELAY_PUSH_4, RELAY_PULL_4);
  refreshChannel(RELAY_CHANNEL_5, CHANNEL_TIME_5, RELAY_PUSH_5, RELAY_PULL_5);
  refreshChannel(RELAY_CHANNEL_6, CHANNEL_TIME_6, RELAY_PUSH_6, RELAY_PULL_6);
  refreshChannel(RELAY_CHANNEL_7, CHANNEL_TIME_7, RELAY_PUSH_7, RELAY_PULL_7);
  refreshChannel(RELAY_CHANNEL_8, CHANNEL_TIME_8, RELAY_PUSH_8, RELAY_PULL_8);
}
