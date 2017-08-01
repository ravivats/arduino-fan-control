float temp;
char mode='a';
char data='a';

int tempPin = A0; 
int tempMin = 30; 
int tempMax = 70;

int fan = 6; 
int fanSpeed = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(fan, OUTPUT);
  pinMode(tempPin, INPUT);
  
}

void loop() {

  if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.println(data);          //Print Value inside data in Serial monitor
       

      if(data == 'a' || data == 'b')
      {
        mode=data;
      }
     
      if(data == 'a')
      {
        Serial.println(temp);
      }

      else if(data == 'b')
       {
         fanSpeed=255;
       }
  }
      if(mode == 'a')
      {
        temp = analogRead(tempPin);
        temp = (temp *5.0*100.0)/1024.0; //calculate the temperature in Celsius  
        delay(1000); // delay in between reads for stability
        
        if(temp < tempMin) 
        { 
          fanSpeed = 0; // fan is not spinning
          digitalWrite(fan, LOW);
        }
        if((temp >= tempMin) && (temp <= tempMax))
        {
          fanSpeed = map(temp, tempMin, tempMax, 32, 255); // the actual speed of fan
          analogWrite(fan, fanSpeed); // spin the fan at the fanSpeed speed
        }
      }
      else if(mode == 'b')
      {
          if(data == '5')
            fanSpeed= 255;
          else if(data == '4')  
            fanSpeed= 200;
          else if(data == '3')  
            fanSpeed= 150;
          else if(data == '2')  
            fanSpeed= 100;
          else if(data == '1')  
            fanSpeed= 50;
          else if(data == '0')  
            fanSpeed= 0;
         
          analogWrite(fan, fanSpeed);
      }
}
