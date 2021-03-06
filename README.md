﻿# Robotics Drone Gate

This is a robotics smart drone gate for indoor microdrone. I love flying my tinywhoop during winter time.
I have a gate course in my basement and wanted to make this gate that would move and make it more difficult as I fly around.  

[![flight video](https://img.youtube.com/vi/2EXwwkreShI/0.jpg)](https://youtu.be/2EXwwkreShI)

This gate is actually simple. It's a servo motor connected to a microcontroller. I am using a simblee which is an arduino like microcontroller with bluetooth build in.
You can create directly into the ardiuno ide the iOS or Android app GUI. It's very simple!


[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=YYNTYF69KT7P8)


## Table of Contents
- [Introduction](#introduction)
  - [What it is](#what-it-is)
  - [How it works](#how-it-works)
  - [What is the simblee](#what-is-the-simblee)
- [Todo](#todo)
- [Videos](#videos)
- [Disclaimer](#disclaimer)
- [FAQ](#faq)
- [Sources and additional links](#sources-and-additional-links)
-  [License](#license)
-  [Author](#author)

## Introduction ##

### What it is
Smart robotics gate for indoor FPV drone racing controlled via an iOS app. The speed of the servo motor is controlled via the app. This reflects the difficulty. You simply need to go fly through it and have fun!

Check out the [video section](#videos) to see it in action.

<img src="https://github.com/robomaniac/robotics-drone-gate/raw/master/images/drone_gate_overall.JPG" alt="overall image" style="max-width:10%;">
<img src="https://github.com/robomaniac/robotics-drone-gate/raw/master/images/drone_gate_back.JPG" alt="back of the system" style="max-width:10%;">


### How it works

You have a app on iOS that control the speed and direction of a servo motor. That app is actually writting directly inside the Arduino IDE. No MAC computer, no Xcode, no Apple Developer membership was required. That is the beauty of the Simblee module.

<img src="https://github.com/robomaniac/robotics-drone-gate/blob/master/images/drone_gate_GUI.JPG" width="400">

![electronic](https://github.com/robomaniac/robotics-drone-gate/blob/master/images/drone_gate_closeup.JPG)

Here is the servo motor that make the propeller spin. 
![servo motor](https://github.com/robomaniac/robotics-drone-gate/blob/master/images/drone_gate_servo_horn.JPG)

the entire gate is portable and can be added to a tripod
![tripod](https://github.com/robomaniac/robotics-drone-gate/blob/master/images/drone_gate_tripod.JPG)

### What is the simblee

The [Simblee](https://www.simblee.com/) is a bluetooth [Arduino](https://www.arduino.cc/en/Main/Software) like microcontroller. The magic is that you can write very life like iOS and Android app directly inside the [Arduino](https://www.arduino.cc/en/Main/Software) IDE.

## Todo
The most to date list of todo is writting inside the [arduino code](https://github.com/robomaniac/robotics-drone-gate/blob/master/software/FPV_simblee_rotorvillage_smart_gate.ino).
- [X] <strike>remove all the variable that are not use</strike>
- [X] <strike>make the Start switch position base on witdh of phone and not hard coded</strike>
- [X] add random time in expert mode
- [X] add random servo motor speed in expert mode
- [X] clean the code
- [X] make beeper go off when idle for X minutes. If nothing is actiaved, sound the alarm and reset when you trigger the START button
-  [X] read voltage of the lipo to trigger alarm and shutdown system

## Videos
  
  Here is a video that explain the project in general.
  
[![technical explanation](https://img.youtube.com/vi/98bTcw-L2r0/0.jpg)](https://youtu.be/98bTcw-L2r0)
 
 This video is a flight video with no explanation of the project
[![flight video](https://img.youtube.com/vi/2EXwwkreShI/0.jpg)](https://youtu.be/2EXwwkreShI)


## Disclaimer

Jerome Demers (Robomaniac) has made every attempt to ensure the accuracy and reliability of the information provided on this page. However, the information is provided "as is" without warranty of any kind. Jerome Demers (Robomaniac) does not accept any responsibility or liability for the accuracy, legality, content, completeness or reliability of the information contained on this page.



## FAQ

**What is a tinywhoop?**  
Tinywhoop is a very small flying drone. You place goggles over your eyes to have first person view (FPV) of the drone flying around. Have look here [www.tinywhoop.com](https://www.tinywhoop.com) to start.

**What material did you use?**  
I use *foam core* and glue 2 sheets together to make it stronger around the edge of my gate. 

**Can I use other type of motors?**  
Yes, you can use stepper motors, DC motors, normal servo, etc. Have a look at the [GM serie motors](https://solarbotics.com/catalog/motors-servos/gear-motors/) from solarbotics. You could even use linear actuators like [these](https://www.pololu.com/category/127/linear-actuators) from Pololu. You could have a gate that goes up and down.

**I do not have ressource to cut material to build this**  
No problem, you can buy some mechanical parts like [these](https://www.servocity.com/structural-components) to build your gate. Servocity offers a huge variety of components to build cool projects. Motors, actuator, brackets, clamps, etc. You only need a screw driver!

**Where can I find more information about simblee mobile example?**  
Once you have installed simblee in arduino ide. Go to Files->Examples->SimbleeForMobile
I recomment you try all of them to see what you can do with the  simblee and the limits of it. 
*SimbleeUITest* is a good start.

**What does .MD standfor?**  
MarkDown and you can use a online editor like [stackedit](https://stackedit.io/app) or [dillinger](https://dillinger.io/) to edit before commiting to github

**I have zero programming skills**  
You can plug a batterie directly to a DC motor to make it spin. No need of arduino.
Follow these instructions http://www.instructables.com/id/How-to-modify-a-servo-motor-for-continuous-rotatio/

**Need more help with Simblee**  
If you have other questions or problems with the Simblee, you can also check out the official [community forum](http://forum.rfduino.com/index.php?topic=1066.0).


## Ressources and additional links
Sparkfun tutorial: https://learn.sparkfun.com/tutorials/simblee-concepts/setting-up-arduino  
Simblee:  https://www.simblee.com  
Simblee function reference guide: https://www.simblee.com/Simblee%20Functions%20Reference%20V1.0.pdf  
Simblee user guide: https://www.simblee.com/Simblee%20User%20Guide%20v2.06.pdf  


## License
This project is licensed under the MIT License - see the [license file](LICENSE) for details.

## Author
Jérôme Demers [robomaniac](https://www.instagram.com/robo_maniac/)
