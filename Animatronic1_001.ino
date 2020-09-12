// - LIBRARY -
#include <DmxSimple.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <Chrono.h>


// AUDIO DEFINE
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 12; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
// Create the Player object
DFRobotDFPlayerMini player;


// PIR SENSOR DEFINE
int PIR_PIN = 9;

// the time we give it to calibrate
int calibrationTime = 15;

// the time when it outputs a low impulse
long unsigned int lowIn;

// the amount of ms it has to be low
// before we assune all motion has stopped
long unsigned int pause = 2500;

boolean lockLow = true;
boolean takeLowTime;


// LIGHT SENSOR DEFINE
int LIGHT_PIN = 8;
int toggleState;
int lastLightState = 1;
long unsigned int lastLight;
int debounceTime = 20;


// DMX DEFINE
int dmxMaxChannel = 7;
int DMX_PIN = 10;


// Create Variables to denote RELAY channels
const int relayPin1 = 0;
const int relayPin2 = 1;
const int relayPin3 = 2;
const int relayPin4 = 3;
const int relayPin5 = 4;
const int relayPin6 = 5;
const int relayPin7 = 6;
const int relayPin8 = 7;

// Create Variables to hold the RELAY states
int relayState1 = HIGH;
int relayState2 = HIGH;
int relayState3 = HIGH;
int relayState4 = HIGH;
int relayState5 = HIGH;
int relayState6 = HIGH;
int relayState7 = HIGH;
int relayState8 = HIGH;

// Creating timeline for each RELAY
Chrono chrono1;
Chrono chrono2;
Chrono chrono3;
Chrono chrono4;
Chrono chrono5;
Chrono chrono6;
Chrono chrono7;
Chrono chrono8;



void setup() {

  Serial.begin(9600);
  softwareSerial.begin(9600);

  // Assigns Relay Channels to Arduino Pinouts
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  pinMode(relayPin5, OUTPUT);
  pinMode(relayPin6, OUTPUT);
  pinMode(relayPin7, OUTPUT);
  pinMode(relayPin8, OUTPUT);

  // Assign Relay Channels with Constant States
  digitalWrite(relayPin1, relayState1);
  digitalWrite(relayPin2, relayState2);
  digitalWrite(relayPin3, relayState3);
  digitalWrite(relayPin4, relayState4);
  digitalWrite(relayPin5, relayState5);
  digitalWrite(relayPin6, relayState6);
  digitalWrite(relayPin7, relayState7);
  digitalWrite(relayPin8, relayState8);


  // LIGHT SENSOR SETUP
  pinMode(LIGHT_PIN, INPUT_PULLUP);
  int lightState = digitalRead(LIGHT_PIN);


  // PIR SETUP
  pinMode(PIR_PIN, INPUT);
  // give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);


  // DMX SETUP
  DmxSimple.maxChannel(dmxMaxChannel);
  DmxSimple.usePin(DMX_PIN);


  // AUDIO SETUP
  player.volume(20);


}


void loop() {

  int pirState = digitalRead(PIR_PIN);
  int lightState = digitalRead(LIGHT_PIN);
  detect_pir();
  idle();

  // Trigger Program when PIR detected movement
  if (pirState == HIGH) {

    detect_pir();

  }else{
    idle();
  }

  // Trigger Program when light is detected
  if (lightState == HIGH) {

    detect_light();

  }

}

void idle() {
  //do stuff
}

void detect_pir() {

  player.play(1); // audio file to play

  //Animation on relay
  PIR_RELAY_1();
  PIR_RELAY_2();
  /*PIR_RELAY_3();
    PIR_RELAY_4();
    PIR_RELAY_5();
    PIR_RELAY_6();
    PIR_RELAY_7();
    PIR_RELAY_8();*/

}

void detect_light() {

  player.play(2); // audio file to play

  //Animation on relay
  LGT_RELAY_1();
  /*LGT_RELAY_2();
    LGT_RELAY_3();
    LGT_RELAY_4();
    LGT_RELAY_5();
    LGT_RELAY_6();
    LGT_RELAY_7();
    LGT_RELAY_8();*/

}

////////////////////////     ANIMATION   //////////////////////////////////

// PIR Sensor

void PIR_RELAY_1() { // Relay_1

  chrono1.restart();

  if ( chrono1.hasPassed(10000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(11000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(12000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(13000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(14000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(15000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(16000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(17000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(18000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(19000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(20000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(21000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(22000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(23000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(24000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(25000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(26000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(27000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(28000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(29000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }
  if ( chrono1.hasPassed(30000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }

  chrono1.restart();

}
void PIR_RELAY_2() { // Relay_2

  chrono1.restart();

  if ( chrono2.hasPassed(10000) ) {
    relayState2 = !relayState2;
    digitalWrite(relayPin2, relayState2);
  }


  chrono1.restart();
}


// Light Sensor

void LGT_RELAY_1() { // Relay_1

  int lightState = digitalRead(LIGHT_PIN);

  chrono1.restart();

  if ( chrono1.hasPassed(1000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }

  if ( chrono1.hasPassed(2000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }

  if ( chrono1.hasPassed(5000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }

  if ( chrono1.hasPassed(8000) ) {
    relayState1 = !relayState1;
    digitalWrite(relayPin1, relayState1);
  }

  if ((millis() - lastLight) > debounceTime)
  {
    lastLight = millis();

    if (lightState == 0 && lastLightState == 1) {
      toggleState = ! toggleState;
      digitalWrite(relayPin1, toggleState);
    }
  }

  chrono1.restart();

}
