#include <Servo.h> // servo library

Servo myservo; 
int m=0;
int n=0;
int pos = 0; 
void setup()
 {
  // put your setup code here, to run once:
pinMode(A0, INPUT_PULLUP);           // Soil Moisture Sensor 1 PIN A0
pinMode(A1, INPUT_PULLUP);           // Soil Moisture Sensor 1 PIN A1
pinMode(8,OUTPUT);                             // Relay Module PIN D8
Serial.begin(9600);                                  //  Sensor Buart Rate
myservo.attach(9);                                   //  Servo PIN D9

digitalWrite(8, HIGH);                           // Relay Normally Hight for OFF condition
}

void loop() 
{

// put your main code here, to run repeatedly:

int m= analogRead(A0);                         // Soil Moisture Sensor 1 PIN A0
int n= analogRead(A1);                           // Soil Moisture Sensor 1 PIN A1
Serial.println(m);
delay(10);
Serial.println(n);
delay(200);
if (m>=600)
{
 myservo.write(90);              // tell servo to go to position in variable 'pos'
        
  digitalWrite(8, LOW);       // Relay ON
  delay(1000);
  }

else if(m<=600) 
{
 digitalWrite(8, HIGH);      // Relay ON
 }

 if (n>=600)
{

  myservo.write(0);              // tell servo to go to position in variable 'pos'
        
  digitalWrite(8, LOW);       // Relay ON
  delay(1000);
  
  }

else if(n<=600)
{

  digitalWrite(8, HIGH);    // Relay OFF
  }
  
else
{
  digitalWrite(8, HIGH);   // Relay OFF
  }
}
