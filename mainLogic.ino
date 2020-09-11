//- LIBRARY -
#include <DmxSimple.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <Chrono.h>



//AUDIO DEFINE

static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 12; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
// Create the Player object
DFRobotDFPlayerMini player;



//PIR SENSOR DEFINE

int PIR_PIN = 9;

//the time we give it to calibrate
int calibrationTime = 15;

//the time when it outputs a low impulse
long unsigned int lowIn;

//the amount of ms it has to be low
//before we assune all motion has stopped
long unsigned int pause = 2500;

boolean lockLow = true;
boolean takeLowTime;



//LIGHT SENSOR DEFINE

int LIGHT_PIN = 8;

int toggleState;
int lastLightState = 1;
long unsigned int lastLight;
int debounceTime = 20;



//DMX DEFINE

int dmxMaxChannel = 7;
int DMX_PIN = 10;



//RELAY_DEFINE
//Relay
const int relayPin1 = 0;
const int relayPin2 = 1;
const int relayPin3 = 2;
const int relayPin4 = 3;
const int relayPin5 = 4;
const int relayPin6 = 5;
const int relayPin7 = 6;
const int relayPin8 = 7;

//Create Variables to hold the RELAY states
int relayState1 = HIGH;
int relayState2 = HIGH;
int relayState3 = HIGH;
int relayState4 = HIGH;
int relayState5 = HIGH;
int relayState6 = HIGH;
int relayState7 = HIGH;
int relayState8 = HIGH;

//Chronos DEFINE
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

  { //RELAY SETUP
    pinMode(relayPin1, OUTPUT);
    digitalWrite(relayPin1, relayState1);

    pinMode(relayPin2, OUTPUT);
    digitalWrite(relayPin2, relayState2);

    pinMode(relayPin3, OUTPUT);
    digitalWrite(relayPin3, relayState3);

    pinMode(relayPin4, OUTPUT);
    digitalWrite(relayPin4, relayState4);

    pinMode(relayPin5, OUTPUT);
    digitalWrite(relayPin5, relayState5);

    pinMode(relayPin6, OUTPUT);
    digitalWrite(relayPin6, relayState6);

    pinMode(relayPin7, OUTPUT);
    digitalWrite(relayPin7, relayState7);

    pinMode(relayPin8, OUTPUT);
    digitalWrite(relayPin8, relayState8);

  }

  { //LIGHT SENSOR SETUP
    pinMode(LIGHT_PIN, INPUT_PULLUP);
    int lightState = digitalRead(LIGHT_PIN);

  }

  { //PIR SETUP
    pinMode(PIR_PIN, INPUT);
    //give the sensor some time to calibrate
    Serial.print("calibrating sensor ");
    for (int i = 0; i < calibrationTime; i++) {
      Serial.print(".");
      delay(1000);
    }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }

  { //DMX SETUP
    DmxSimple.maxChannel(dmxMaxChannel);
    DmxSimple.usePin(DMX_PIN);

  }

  { //AUDIO SETUP
    player.volume(20);

  }

}

void loop() {

  idle();

//LIGHT DETECT
  if (lightState == HIGH){
    
    detect_light();
  }

//PIR DETECT
  if (digitalRead(PIR_PIN) == LOW){
    detect_pir();
  }

  //TEST
  /* int lightState = digitalRead(LIGHT_PIN);

    if((millis() - lastLight) > debounceTime)
    {
     lastLight = millis();

     if(lightState == 0 && lastLightState == 1)
     {
       toggleState =! toggleState;
       digitalWrite(relayPin1,toggleState);
     }
    }
    /*if ( previousLightState != LightState ) {
     previousLightState = LightState;

    if ( chrono1.hasPassed(100) ) {
       relayState1 = !relayState1;
       digitalWrite(relayPin1,relayState1);
     }
     chrono1.restart();
     }
     
     if ( chrono2.hasPassed(1000) ) { // returns true if it passed 1000 ms since it was started
    chrono2.restart(); // restart the crono so that it triggers again later
    relayState2 = !relayState2; // !: toggle the state from 0 to 1 or from 1 to 0
    digitalWrite(relayPin2, relayState2);

  }*/

}

void idle() {
//do stuff
}

void detect_pir() {
//do stuff
}

void detect_light() {
//do stuff
}
