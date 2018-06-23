# MAVLINK for Arduino Pixhawk Communication
After scrolling over the internet and finding no any usefull stuff about how to retrieve datas from Pixhawk to Arduino Board. I started about writing my own solution to this. Used mavlink to generate C lib and using that one for the arduino. Right now example codes have been done to recieve only sensor data from the Pixhawk, if you want to send the datas as well please follow the MAVLink actual documentation.
**Created By:** Shashi Kant
**Date:** 23/06/2018
**Sources:** See the Links below
**Project Status:** Ongoing

# Some usefull Links:
1. [MAVLink Developer Guide](https://mavlink.io/en/)
1. [MAVLink Step By Step](https://discuss.ardupilot.org/t/mavlink-step-by-step/9629)
1. [MAVLink Tutorial for Absolute Dummies (Part –I)](https://diydrones.com/group/arducopterusergroup/forum/topics/mavlink-tutorial-for-absolute-dummies-part-i?xg_source=activity)
1. [MAVLink Erle Robotics](http://erlerobot.github.io/erle_gitbook/en/mavlink/mavlink.html)

# How to install this library?
1. Git Clone this repo or download the zip version for it.
1. Find the libraries folder inside it.
1. Just rename it with "PixhawkArduinoMAVLink" and paste it inside the "libraries" folder of your default arduino sketchbook directory.
1. To use it follow this [Tutorial](tutorial.md)
