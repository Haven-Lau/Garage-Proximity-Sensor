# Garage-Proximity-Sensor
My parent's minivan is very hard to park in our garage, 
so I made a proximity sensing device using ultrasonic sensor and neopixels to give some information about how far the car is til bumping into the wall.
Nothing too overly complex and my focus was to have a good LED pattern such that it is easy to interpret the distance,
Hence the choice of Neopixels.

Neopixels aka WS2812B have integrated drivers, are addressable and possible to control multiple leds with 1 data line.
Flowchart of the program:
 
80>cm or undetected region(glitch region) = all lights off
 
80 - 10cm = value is mapped to the 30 leds, color will also fade from cyan to yellow depending on distance
 
10<cm = color will cycle between orange to yellow, with breathing animation, light will turn off after 10 cycles
