# Robotics-Drone-Gate

This is a robotics smart drone gate for indoor microdrone. I love flying my tinywhoop during winter time.
I have a gate course in my basement and wanted to make this gate that would move and make it more difficult as I fly around.
This gate is actually simple. It's a servo motor connected to a microcontroller. I am using a simblee which is an arduino like microcontroller with bluetooth build in.
You can create directly into the ardiuno ide the iOS or Android app GUI. It's very simple!

I am still working on this github and this readme file.

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=YYNTYF69KT7P8)


## Contents
- [Introduction](#introduction)
  - [What it is](#what-it-is)
  - [How it works](#how-it-works)
  - [What is the simblee](#what-is-the-simblee)
- [Disclaimer](#disclaimer)
- [Videos](#videos)
- [Installation](#installation)
  - [Adding code](#code)
- [FAQ](#faq)
- [License](#license)
- [Sources and additional links](#sources-and-additional-links)

## Introduction ##

### What it is
Smart robotics gate for indoor FPV drone racing controlled via an iOS app. The speed of the servo motor is controlled via the app. This reflects the difficulty. You simply need to go fly through it and have fun!


### How it works

The module is deepsleep mode. When you press the button, it will wake up and then wait for the door to close. The accelerometer will detect the impact of the door closing and then the module will active the motor.

[![Behind the scene] https://github.com/robomaniac/robotics-drone-gate/blob/master/hardware/3D_printed_parts/drone_gate_over_view.JPG
The servo motor is modify for continus rotation. Follow those instructions http://www.instructables.com/id/How-to-modify-a-servo-motor-for-continuous-rotatio/

### What is the simblee

The [Simblee](https://www.simblee.com/) is a bluetooth [Arduino](https://www.arduino.cc/en/Main/Software) like microcontroller. The magic is that you can write very life like iOS and Android app directly inside the [Arduino](https://www.arduino.cc/en/Main/Software) IDE.


## Disclaimer

Jerome Demers (Robomaniac) has made every attempt to ensure the accuracy and reliability of the information provided on this page. However, the information is provided "as is" without warranty of any kind. Jerome Demers (Robomaniac) does not accept any responsibility or liability for the accuracy, legality, content, completeness or reliability of the information contained on this page.


## Videos
  
  
[![Simblee Quick Start Guide](https://img.youtube.com/vi/KUL_jX0mujE/0.jpg)](https://www.youtube.com/watch?v=KUL_jX0mujE)
 
## Installation ##
### Code 


**2** Customize the code for your wiring.  
		here is code exemple  

		  //include the library you need
		  #include "simblee.h"

		  //button pins
		  #define up D1
		  #define down D2




## FAQ

**Is this an amazing question?**

Yes, but more are coming.

### If you have other questions or problems with the Simblee, you can also check out the official [community forum](http://forum.rfduino.com/index.php?topic=1066.0).

## License

This project is licensed under the MIT License - see the [license file](LICENSE) for details.

## Sources and additional links

Sparkfun tutorial: https://learn.sparkfun.com/tutorials/simblee-concepts/setting-up-arduino


Simblee: 
* https://www.simblee.com
