#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LEDNUM 30
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRB + NEO_KHZ800);

int vcc = 2; //attach pin 2 to vcc
int trig = 3; // attach pin 3 to Trig
int echo = 4; //attach pin 4 to Echo
int gnd = 5; //attach pin 5 to GND
int led1 = 8;
int led2 = 9;
int led3 = 10;
int timeDone = 0;
int glowOffset = 50;
int valOffset = 5;
void setup() {

pinMode (trig,OUTPUT);
pinMode (echo,INPUT);
pinMode (vcc,OUTPUT);
pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
// initialize serial communication:
Serial.begin(115200);
digitalWrite(vcc,HIGH);
strip.begin();
strip.setBrightness(50);
strip.show(); // Initialize all pixels to 'off'
}

void loop(){
  
  long cm = cmDetect();
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm > 8){
    timeDone = 0;
    
    //MID ZONE
    if (cm <= 80){
      int onLed = map(80 - cm +8, 8, 80, 0, 30);
      
       for (int i = 0; i < LEDNUM; i++){
         strip.setPixelColor(i, 0, 0, 0);
      }
      for (int i = 0; i < onLed; i++){
         strip.setPixelColor(i, 81-cm, 1.5*cm + 40, 0);
      }
      strip.show();
      
    }else{
      //FAR ZONE
      for (int i = 0; i < LEDNUM; i++){
        strip.setPixelColor(i, 0, 0, 0);
      }
      strip.show();
    }
    int glowOffset = -30;
    int valOffset = 5;
  }else if (cm <= 8){
    
    //CLOSE ZONE
    if (timeDone > 250){
      for (int i = 0; i < LEDNUM; i++){
        strip.setPixelColor(i, 0, 0, 0);
      }
      strip.show();
    
    }else{
      for (int i = 0; i < LEDNUM; i++){
        strip.setPixelColor(i, 80 + glowOffset, 42 + glowOffset, 0);
      }
      strip.show();
      timeDone++;
      
    }
  
  
  
  }
  //Breath effect
  if (glowOffset == 50)
    valOffset = -5;
  else if (glowOffset == -30)
    valOffset = 5;
  glowOffset += valOffset;
  
  delay(30);
}

long cmDetect(){
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH,100000);
  return microsecondsToCentimeters(duration);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
