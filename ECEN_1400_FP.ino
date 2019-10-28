#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    60
#define BRIGHTNESS  200
CRGB leds[NUM_LEDS];

long randRed;
long randGreen;
long randBlue;

int run; //this is for the button

void setup() 
{
   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
   
   //FastLED.setBrightness(50);

   pinMode(A0, INPUT); //A0 photoresistor
   pinMode(A1, INPUT); //A1 temperature sensor
   pinMode(A2, INPUT); //A2 motion detector
   pinMode(A3, INPUT); //A3 button 1
   
   Serial.begin(9600);
}


void loop() 
{
  
  
  //Motion Detector-----------------------------
  int motion = analogRead(A2);
  Serial.print("Motion = ");
  Serial.println(motion);
  if(motion > 500)
  {


  //Photoresistor-------------------------------
  float photoresistor = analogRead(A0);
  Serial.print("Photoresistor = ");
  Serial.println(photoresistor);
  float ambientLight = (photoresistor/1023)*250;
  FastLED.setBrightness(ambientLight);


  //Temperature Sensor--------------------------
  float temp = analogRead(A1);
  float celsius = ((temp/1024.)*3.3*100)-50;
  float farenheit = celsius*1.8+32;
  Serial.print("Farenhait = ");
  Serial.print(farenheit);
  Serial.println("degrees F");


  //Buttons--------------------------------------
  int button1 = analogRead(A3);
  Serial.print("Button 1 = ");
  Serial.println(button1);

  //--------------------------------------------
  //LED Control:
  if(button1 > 0)
  {
    for(int i = 0; i <= 60; i++)
    {
      leds[i] = CRGB(0, 0, 0); //off
      FastLED.show();
      delay(0);  
    }
    Serial.end();
  }

  
  //first half 1111111111111111111111111111111111
    if(farenheit < 68)
    {
      for(int i = 0; i <= 29; i++)
      {
        leds[i] = CRGB(0, 0, 255); //blue
        FastLED.show();
        delay(2);  
      }
    }
    else if(farenheit >= 68 && farenheit <= 71)
    {
      for(int i = 0; i <= 29; i++)
      {
        leds[i] = CRGB(255, 0, 90); //purple
        FastLED.show();
        delay(2);  
      }
    }
    else if(farenheit > 71)
    {
      for(int i = 0; i <= 29; i++)
      {
        leds[i] = CRGB(255, 0, 0); //red
        FastLED.show();
        delay(2);  
      }
    }
  
  
    //second half 2222222222222222222222222222222222
    randRed = random(200);
    randGreen = random(200);
    randBlue = random(200);
    for(int i = 30; i <= 59; i++)
    {
      leds[i] = CRGB(randRed, randGreen, randBlue);
      FastLED.show();
      delay(50);  
    }
    
  }//motion
  else
  {
    for(int i = 0; i <= 59; i++)
    {
      leds[i] = CRGB(0,0,0);
      FastLED.show();
      delay(50);  
    }
  }
}
