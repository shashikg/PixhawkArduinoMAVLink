# MAVLINK for Arduino Pixhawk Communication
After scrolling over the internet and finding very less usefull stuffs about how to retrieve datas from Pixhawk to Arduino Board, I decided about writing a Arduino Library for this. Moreover, most of them have some of their own problem! Well Juan Pedro's Article really helped a lot! but that too didn't worked for me, maybe due to the older version of mavlink library! So, I started about writing my own solution to this. Using mavlink to generate C libs, I had written a whole bunch of Arduino library to hide lots of processing scenes which are working behind the window! so as to provide easy access to the usefull data which is required in different projects!

**Created By:** Shashi Kant

**Date Started:** 23/06/2018

**Sources:** See the Links Below (Huge thanks to their contributors!). Special thanks to [Juan Pedro](https://discuss.ardupilot.org/u/jplopezll/) for his excellent article on [MAVLink and Arduino](https://discuss.ardupilot.org/t/mavlink-and-arduino-step-by-step/25566)

**Project Status:** On Halt

# Some Usefull Links:
1. [MAVLink and Arduino: step by step](https://discuss.ardupilot.org/t/mavlink-and-arduino-step-by-step/25566)
1. [MAVLink Developer Guide](https://mavlink.io/en/)
1. [MAVLink Step By Step](https://discuss.ardupilot.org/t/mavlink-step-by-step/9629)
1. [MAVLink Tutorial for Absolute Dummies (Part –I)](https://diydrones.com/group/arducopterusergroup/forum/topics/mavlink-tutorial-for-absolute-dummies-part-i?xg_source=activity)
1. [MAVLink Erle Robotics](http://erlerobot.github.io/erle_gitbook/en/mavlink/mavlink.html)

# How to install this library?
1. Git Clone this repo or [download the zip version for it](https://github.com/shashikg/PixhawkArduinoMAVLink/archive/master.zip).
1. (In the Arduino IDE) Sketch > Include Library > Add .ZIP Library > select the downloaded file > Open
1. To use it follow this [Guide](guide.md)

# License
PixhawkArduinoMAVLink is licensed under the terms  of the MIT License. It uses C-language version of MAVLink header libraries which are inside ```libraries/PixhawkArduinoMAVLink/src/``` directory generated using the mavlink generator. The generated files are also under MIT License
1. See the [LICENSE](LICENSE) file for this project.
1. [LICENSE.txt](libraries/PixhawkArduinoMAVLink/src/LICENSE.txt) file for the MIT License declaration by mavlink. See the mavlink's COPYING file for more information about license of MAVLink header files.
