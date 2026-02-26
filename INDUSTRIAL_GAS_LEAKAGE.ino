#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
LiquidCrystal lcd(2,3,4,5,6,7);

const int LED = 8;
const int Gassensor = A0;
const int Relay = 9;
const int Threshold = 300;

void setup() 
{
  pinMode(Gassensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Relay, OUTPUT);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.clear();
  Serial.begin(9600);

  
  if (!rtc.begin()) 
  {
    Serial.println("RTC NOT FOUND");
    while (1);
  }
  if (rtc.lostPower()) 
  {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }  
}

void loop() 
{
  DateTime now=rtc.now();
  int Gassensorlevel = analogRead(Gassensor);

  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.setCursor(13,0);
  lcd.print(Gassensorlevel);
      
  lcd.setCursor(8,1);

  if(now.hour()>12)
  {
    int n=now.hour()-12;
    if(n<10)
    {
      lcd.print("0");
    }
    lcd.print(n);
  }
  else
  {
    if(now.hour()<10)
    {
      lcd.print("0");
    }
    lcd.print(now.hour());
  }
  
  lcd.print(':');
  if(now.minute()<10)
  {
    lcd.print("0");
  }
  lcd.print(now.minute());
  lcd.print(':');
  if(now.second()<10)
  {
    lcd.print("0");
  }
  lcd.print(now.second());    

  Serial.print("Gas Level: ");
  Serial.print(Gassensorlevel);
  Serial.print(" ");
  if(now.hour()>12)
  {
    int n=now.hour()-12;
    if(n<10)
    {
      Serial.print("0");
    }
    Serial.print(n);
  }
  else
  {
    if(now.hour()<10)
    {
      Serial.print("0");
    }
    Serial.print(now.hour());
  }
  Serial.print('/');
  if(now.minute()<10)
  {
    Serial.print("0");
  }
  Serial.print(now.minute());
  Serial.print('/');
  if(now.second()<10)
  {
    Serial.print("0");
  }
  Serial.print(now.second());
  Serial.print(" ");

  if(Gassensorlevel < Threshold)
  {
    lcd.setCursor(0,1);
    lcd.print("SAFE");

    Serial.println("Safe");
    
    digitalWrite(LED,LOW);
    digitalWrite(Relay,HIGH);
    delay(500);   
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("WARNING");
    
    digitalWrite(LED,HIGH);
    digitalWrite(Relay,LOW);
    Serial.println("Warning!!");
    
    delay(500);
    digitalWrite(LED,LOW);
  }
  delay(500);
  lcd.clear();   
}
