# Garage-Proximity-Sensor
An elegant proximity device designed to make the parking experience smoother. As my parent's minivan is very long and hard to park in our garage, so I made a proximity sensing device using an ultrasonic sensor and neopixels to tell the distance remaining before bumping into the wall. Nothing too overly complex and my focus was to have an intuitive LED pattern such that it is easy to read and interpret the distance, without the use of arbritary numbers, hence the choice of Neopixels.

Neopixels aka WS2812B have integrated drivers, are addressable and it is possible for multiple leds to be controlled  with 1 data line.

Flowchart of the program:
 
80>cm or undetected region(glitch region) = all lights off
 
80 - 10cm = value is mapped to the 30 leds, color will also fade from cyan to yellow depending on distance
 
10<cm = color will cycle between orange to yellow, with breathing animation, light will turn off after 10 cycles

video demo: https://youtu.be/T8M_66g_C6g
