/*
Rotorvillage gate
Servo controller using bluetooth.

Servo is connected to pin 2
LED strip connected to pin 3
Buzzer connected to pin 4 (not yet used in code)

Jerome Demers
January 2018

to do:
- DONE make the Start switch position base on witdh of phone and not hard coded (SimbleeForMobile.screenWidth/2)
- make beeper go off when idle for X minutes. If nothing is actiaved, sound the alarm and reset when you trigger the START button
- read voltage on 1S of the lipo to trigger alarm and shutdown system
- clean the code

*/

#include <Servo.h>
#include <SimbleeForMobile.h>
#include "rotorVILLAGE_png.h"         // the logo was generated using this instructions https://www.youtube.com/watch?v=NglwMpqrTpI
#define LOGO_DOT_IMAGE 1



Servo s1;
int nLevel = 1;                       // skills level, 1 to 3
int ExpertState = LOW;                // ledState used to set the LED
unsigned long previousMillis = 0;     // will store last time LED was updated
const long interval = 3000;           // interval at which to change motor direction in expert mode

const int led = 3;                    // white LED ring is connected to pin 3
const int buzzer = 4;

int BeginnerSwitch;                   // these are switchs and text for the user interface
int NormalSwitch;
int ExpertSwitch;

int BeginnerText;
int NormalText;
int ExpertText;

int LEDText;
int LEDSwitch;

int MotorState = LOW;                 // MotorState used to set the LED
  
int ServoStop = 92;                   // value so the motor stop moving. It's the center position
int ServoBeginner = 95;               // speed for all level
int ServoNormal = 98;
int ServoExpert = 110;

int currentState, previousState = 0;
uint8_t ui_start_button;                    // user interface START button
int nExpertMode=0;                    // state needed to start the fwd and reverse motor motion


//===============================================================================================
void setup() {
  
  s1.attach(2);   // servo motor on pin2 of simblee
  pinMode(led, OUTPUT);  // led turned on/off from the iPhone app
  pinMode(buzzer, OUTPUT); 

  // this is the data we want to appear in the advertisement
  // (if the deviceName and advertisementData are too long to fix into the 31 byte
  // ble advertisement packet, then the advertisementData is truncated first down to
  // a single byte, then it will truncate the deviceName)

  SimbleeForMobile.deviceName = "RotorVillage";
  SimbleeForMobile.advertisementData = "Jay";
  
  // use a shared cache
  SimbleeForMobile.domain = "Simblee.com";
  SimbleeForMobile.begin();
}




//===============================================================================================
void loop() {
  
if(nExpertMode==1){ // move servo motor in expert mode, the interval and motor speed should be random
  
  unsigned long currentMillis = millis();  
  
  if (currentMillis - previousMillis >= interval) {  // this is where it wait 3 sec before the servo motor change direction
    
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ExpertState == LOW) {
      ExpertState = HIGH;
      s1.write(96);   // these should be variable so I can randomly change them
    } else {
      ExpertState = LOW;
      s1.write(86); // these should not be hardcoded
    }

  }// end if

}

  // process must be called in the loop for SimbleeForMobile
  SimbleeForMobile.process();
  
}  //end loop


//===============================================================================================
// this is where you design and create the user interface
void ui()
{

  int titleLeftMargin = 20;
  int titleTopMargin = 230; //250

  int leftMargin = 20;
  int switchLeftMargin = 255;
  int topMargin = 310;//300
  int deltaY = 40;
  int textSize = 20;

  int segmentWidth = 250;
  
  SimbleeForMobile.beginScreen(0xFF112244);
  SimbleeForMobile.drawRect(0,0,SimbleeForMobile.screenWidth, SimbleeForMobile.screenHeight,  rgb(235,235,235));
  
    //SimbleeForMobile.drawRect(19,  33, 285,  17,  0xFF112244);//rectangle parfait
  
  // Rotorvillage logo
  SimbleeForMobile.imageSource(LOGO_DOT_IMAGE, rotorVILLAGEpanda_png_Type, rotorVILLAGEpanda_png, rotorVILLAGEpanda_png_len);
  SimbleeForMobile.drawImage(LOGO_DOT_IMAGE, 20, 60);

  // title for the menu
  SimbleeForMobile.drawText(leftMargin, titleTopMargin+20, "Select Skill Level", BLACK, 35);

  // light grey background
  SimbleeForMobile.drawRect(0,  titleTopMargin + 75, 320,  120,  WHITE);

  BeginnerText = SimbleeForMobile.drawText(leftMargin, topMargin, "Beginner",BLACK, textSize);
  BeginnerSwitch = SimbleeForMobile.drawSwitch(switchLeftMargin, topMargin);
  SimbleeForMobile.updateValue(BeginnerSwitch, 1); // activate that switch
  topMargin += deltaY;

 //separation line
 SimbleeForMobile.drawRect(leftMargin,  topMargin-5, 315,  1,   rgb(221,221,221));

  NormalText = SimbleeForMobile.drawText(leftMargin, topMargin, "Normal", BLACK, textSize);
  NormalSwitch = SimbleeForMobile.drawSwitch(switchLeftMargin, topMargin);
  topMargin += deltaY;
  
 //separation line
  SimbleeForMobile.drawRect(leftMargin,  topMargin-5, 315,  1,  rgb(221,221,221));

   ExpertText = SimbleeForMobile.drawText(leftMargin, topMargin, "Expert", BLACK, textSize);
  ExpertSwitch = SimbleeForMobile.drawSwitch(switchLeftMargin, topMargin);
  topMargin += deltaY+27;

  // light grey background
  SimbleeForMobile.drawRect(0,  topMargin-7,320 ,  40,  WHITE );
  LEDText = SimbleeForMobile.drawText(leftMargin, topMargin, "LED Light", BLACK, textSize);
  LEDSwitch = SimbleeForMobile.drawSwitch(switchLeftMargin, topMargin-3);

  ui_start_button = SimbleeForMobile.drawButton(SimbleeForMobile.screenWidth/2, 510, 80, "START");
  SimbleeForMobile.setEvents(ui_start_button, EVENT_PRESS | EVENT_RELEASE);  

  SimbleeForMobile.endScreen();
  
} // end ui

//===============================================================================================
// the moment you close the app, it goes here
void SimbleeForMobile_onDisconnect()
{
    // we make sure we turn off everything when the app is disconnected
    digitalWrite(led, LOW);
    s1.write(ServoStop);
    nLevel=1; // make button at beginner mode before leving
    MotorState = LOW; // make sure the state is low so next time when you press the start button it trigger motor
    delay(300);
    s1.detach(); // wait before detach servo
}

//===============================================================================================
// the moment you open the app it pass here
void SimbleeForMobile_onConnect()
{
  // you can do an action when the phone connects to the simblee
}

//===============================================================================================
// this handle all the event related to the user interface. Each button, slider, etc are link to an event id
void ui_event(event_t &event)
{

  // turn on LED strip 
  if (event.id == LEDSwitch) {
    if (event.value == 1)
      digitalWrite(led, HIGH);
    else if (event.value == 0)
      digitalWrite(led, LOW);
  }


  // start button
  if (event.id == ui_start_button) {
    if (event.type == EVENT_PRESS)     {
        // if the motor state is off turn it on and vice-versa:
        // I tried MotorState != MotorState but could not get it to work
        if (MotorState == LOW)
           MotorState = HIGH;
        else
           MotorState = LOW;
      } //end if

    }// end event.id

   
  // move the servo motor
  if(MotorState == HIGH){
    
    s1.attach(2);   // servo motor
  
    if(nLevel==1)
      s1.write(ServoBeginner);
     if(nLevel==2)
      s1.write(ServoNormal);  
     if(nLevel==3)  // go into expert mode
        nExpertMode=1;
      else
        nExpertMode=0;

  }else
  {
    s1.detach(); 
  }


  

// simply only let one switch out of the 3 be activated
if (event.id == BeginnerSwitch && event.value == 1) {   
    nLevel = 1;                                                   // tell the servo motor which state you are
    SimbleeForMobile.updateValue(BeginnerSwitch, 1);
    SimbleeForMobile.updateValue(NormalSwitch, 0);
    SimbleeForMobile.updateValue(ExpertSwitch, 0);
  } else if (event.id == NormalSwitch && event.value == 1) {
    nLevel = 2;                                                   // tell the servo motor which state you are
    SimbleeForMobile.updateValue(BeginnerSwitch, 0);
    SimbleeForMobile.updateValue(NormalSwitch, 1);
    SimbleeForMobile.updateValue(ExpertSwitch, 0);    
  } else if (event.id == ExpertSwitch && event.value == 1) {
    nLevel = 3;                                                   // tell the servo motor which state you are
    SimbleeForMobile.updateValue(BeginnerSwitch, 0);
    SimbleeForMobile.updateValue(NormalSwitch, 0);
    SimbleeForMobile.updateValue(ExpertSwitch, 1);
    
  }  else if (event.id == BeginnerSwitch && event.value == 0) {   // this 3 if's are for when you press the same button, it won't let the button be off
  
    SimbleeForMobile.updateValue(BeginnerSwitch, 1);
    SimbleeForMobile.updateValue(NormalSwitch, 0);
    SimbleeForMobile.updateValue(ExpertSwitch, 0);
  } else if (event.id == NormalSwitch && event.value == 0) {

    SimbleeForMobile.updateValue(BeginnerSwitch, 0);
    SimbleeForMobile.updateValue(NormalSwitch, 1);
    SimbleeForMobile.updateValue(ExpertSwitch, 0);    
  } else if (event.id == ExpertSwitch && event.value == 0) {

    SimbleeForMobile.updateValue(BeginnerSwitch, 0);
    SimbleeForMobile.updateValue(NormalSwitch, 0);
    SimbleeForMobile.updateValue(ExpertSwitch, 1);
    
  }

  
} // end ui_event



