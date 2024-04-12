#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);

int buz=4;
int mot=5;
int a=0;
int b=0;
int pdata;
String bdata;
void setup() 
{
  Serial.begin(9600);
  bt.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BANK LOCKER");
  lcd.setCursor(0,1);
  lcd.print("SECURITY SYS.");
  delay(2000);
  pinMode(buz,OUTPUT);
  pinMode(mot,OUTPUT);

  // put your setup code here, to run once:
  digitalWrite(buz,LOW);
  digitalWrite(mot,HIGH);
}

void loop() 
{
  if(Serial.available())
  {
    pdata=Serial.read();
    Serial.println(pdata);
    delay(500);
    
    if(pdata=='1')
    {
      a=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PYTHON DATA:");
      lcd.setCursor(0,1);
      lcd.print("USER DETECTED");
      Serial.println(pdata);
      delay(2000); 
    }
    if(pdata=='0')
    {
      a=0;
      digitalWrite(buz,LOW);
      digitalWrite(mot,HIGH);
    }
 }
 if(bt.available())
    {
      bdata=bt.readString();
      Serial.println(bdata);
      
      delay(500);
      if(bdata=="secure")
      {
        b=1;
        lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("BLUETOOTH DATA:");
      lcd.setCursor(0,1);
      lcd.print(bdata);
      Serial.println(bdata);
      delay(2000);
      }
    }
 if(a==1&&b==1)
 {
  Serial.println("Motor ON");
  
  digitalWrite(mot,LOW);
  delay(3000);
//  digitalWrite(mot,HIGH);
  digitalWrite(buz,HIGH);
  delay(3000);
  digitalWrite(buz,LOW);
 }
 
}
