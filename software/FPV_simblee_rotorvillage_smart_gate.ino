/*

Rotorvillage gate
Servo controller using bluetooth


Jerome Demers
January 2018


to do:
- make beeper go off when idle for X minutes. If nothing is actiaved, sound the alarm and reset when you trigger the START button
- read voltage on 1S of the lipo to trigger alarm and shutdown system
- remove all the variable that are not use
- clean the code
- prepare github
- schematic



*/

#include <Servo.h>
#include <SimbleeForMobile.h>

#include "rotorVILLAGE_png.h"

#define LOGO_DOT_IMAGE 1



Servo s1;
int nLevel = 1;

int nStart=0;

int ExpertState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 3000;           // interval at which to change motor direction in expert mode


// pin 3 on the RGB shield is the red led
// (can be turned on/off from the iPhone app)
int led = 3;

// pin 5 on the RGB shield is button 1
// (button press will be shown on the iPhone app)
int button = 5;

// debounce time (in ms)
int debounce_time = 10;

// maximum debounce timeout (in ms)
int debounce_timeout = 100;


int blackSwitch;
int BeginnerSwitch;
int NormalSwitch;
int ExpertSwitch;
int blackText;
int BeginnerText;
int NormalText;
int ExpertText;
int segment;

int LEDText;
int LEDSwitch;

int MotorState = LOW;             // MotorState used to set the LED

int ServoStop = 92;
int ServoBeginner = 95;
int ServoNormal = 98;
int ServoExpert = 110;


void setup() {
  //Serial.begin(9600);
 // Serial.println("Started");

  s1.attach(2);   // servo motor
  
  // led turned on/off from the iPhone app
  pinMode(led, OUTPUT);

  // button press will be shown on the iPhone app)
  pinMode(button, INPUT);

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

int debounce(int state)
{
  int start = millis();
  int debounce_start = start;
  
  while (millis() - start < debounce_timeout)
    if (digitalRead(button) == state)
    {
      if (millis() - debounce_start >= debounce_time)
        return 1;
    }
    else
      debounce_start = millis();

  return 0;
}

int delay_until_button(int state)
{
  // set button edge to wake up on
  if (state)
    Simblee_pinWake(button, HIGH);
  else
    Simblee_pinWake(button, LOW);
    
  do
    // switch to lower power mode until a button edge wakes us up
    Simblee_ULPDelay(INFINITE);
  while (! debounce(state));
  
  // if multiple buttons were configured, this is how you would determine what woke you up
  if (Simblee_pinWoke(button))
  {
    // execute code here
    Simblee_resetPinWake(button);
  }
}

int currentState, previousState = 0;
uint8_t ui_button;
uint8_t ui_rect;
int hello=0;

void loop() {
  
if(hello==1){ // move servo motor in expert mode, the interval and motor speed should be random
  

   unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ExpertState == LOW) {
      ExpertState = HIGH;
      s1.write(96);
    } else {
      ExpertState = LOW;
      s1.write(86);
    }

  }// end if

}

  // process must be called in the loop for SimbleeForMobile
  SimbleeForMobile.process();
}



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

//------------------------------------------------------

  // light grey background
  SimbleeForMobile.drawRect(0,  topMargin-7,320 ,  40,  WHITE );
  LEDText = SimbleeForMobile.drawText(leftMargin, topMargin, "LED Light", BLACK, textSize);
  LEDSwitch = SimbleeForMobile.drawSwitch(switchLeftMargin, topMargin-3);



  ui_button = SimbleeForMobile.drawButton(120, 510, 80, "START");
  SimbleeForMobile.setEvents(ui_button, EVENT_PRESS | EVENT_RELEASE);  



  SimbleeForMobile.endScreen();
}

void SimbleeForMobile_onDisconnect()
{
    digitalWrite(led, LOW);
    s1.write(ServoStop);
    nLevel=1; // make button at beginner mode before leving
    MotorState = LOW; // make sure the state is low so next time when you press the start button it trigger motor
    delay(300);
    s1.detach(); 
}


void SimbleeForMobile_onConnect()
{
  s1.attach(2);   // servo motor
}

void ui_event(event_t &event)
{

  

  // turn on LED
  if (event.id == LEDSwitch) {
    if (event.value == 1)
      digitalWrite(led, HIGH);
    else if (event.value == 0)
      digitalWrite(led, LOW);
  }


// start button
  if (event.id == ui_button) {
    if (event.type == EVENT_PRESS)     {
        // if the motor state is off turn it on and vice-versa:
        // I tried MotorState != MotorState but could not get it to work
        if (MotorState == LOW) {
          MotorState = HIGH;
          } else {
            MotorState = LOW;
         }
      } //end if

    }// end event

   
  // move the servo motor
  if(MotorState == HIGH){

s1.attach(2);   // servo motor
  
    
    if(nLevel==1)
      s1.write(ServoBeginner);
     if(nLevel==2)
      s1.write(ServoNormal);  
     if(nLevel==3)
        hello=1;
      else
        hello=0;
     // Expert();
      
  }else
  {
    s1.detach(); 
   // s1.write(ServoStop);// servo stop
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

void Expert(){
   unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ExpertState == LOW) {
      ExpertState = HIGH;
      s1.write(99);
    } else {
      ExpertState = LOW;
      s1.write(87);
    }

  }// end if
}// end expert





