
int  = 10;


void setup() 
{
  pinMode(digIn, INPUT); //sets D10 as input
  pinMode(digOut, OUTPUT); //sets D13 as output
  Serial.begin(9600);
}

void loop() 
{
//MOTION DETECTOR

  
//TEMPERATURE
  int tempVoltageInput = analogRead(/*temperaturePin*/);
  float voltage = (((float)tempVoltageInput*5.0)/1023);
  double temperature = 0;
  temperature = (voltage - 0.821)/0.014;
  //fahrenheight = (9/5)*temperature + 32;
  if(temperature < 68)
  {
    //change color blue
  }
  else if(temperature > 68 && temperature < 72)
  {
    //change color purple
  }
  else if(temperature > 72)
  {
    //change color red
  }

//light intensity
  int analogPin = /*analogPin*/;
  int raw = 0;
  int Vin = 5;
  float Vout = 0;
  float R1 = 1000;
  float R2 = 0;
  float buffer = 0;

  raw = analogRead(analogPin); //reads voltage divider with the photoresistor
  if(raw)
  {
    buffer = raw*Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2 = R1*buffer;

    if(R2 > 20000)//if the resistance is greater than 20000 ohms, the LEDs turn on
    {
      digitalWrite(/*pin number*/,HIGH);
    }
    else
    {
      digitalWrite(/*pin number*/,LOW);
    }

    delay(1000);
  }
  

//button


  
}
