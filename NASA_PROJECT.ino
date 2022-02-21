#include <Servo.h>

#include <Wire.h>

#include "dht.h"

#define DHT11 7 

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2); 

Servo servo1;

Servo servo2;

Servo servo3;

Servo servo4;

int flame1 = 2;

int flame2 = 4;

int flame3 = 5;

int buzzer = 7;

int PIR = 8 ;

dht DHT;

int x = 0 ;

int gas = A0;

int val = 0 ;

void setup() {

Serial.begin(9600);

lcd.begin(16, 2); 

pinMode(buzzer,OUTPUT);

pinMode(flame1,INPUT);

pinMode(flame2,INPUT);

pinMode(flame3,INPUT);

pinMode(PIR,INPUT);

servo1.attach(3);

servo2.attach(6);

servo3.attach(9);

servo4.attach(11);

}

void loop() 

{


 DHT.read11(DHT11);






//1





if (flame1 == LOW && PIR == LOW){
   
 
  servo4.write(180);
 
  delay(1000);
  
  servo4.write(0);


 
  for (x = 0; x <= 5; x += 1) { 
 
 DHT.read11(DHT11); 

val = map(analogRead(gas), 0, 1024, 0,100);

int TIME  = map(x, 0, 5, 0,100);
 
lcd.clear();

lcd.print("ROOM 1");

lcd.setCursor(0, 0);

delay(10);

lcd.setCursor(6, 1);

lcd.print("PEOPLE IS IN  ");

digitalWrite(buzzer,HIGH);

delay(1000);

digitalWrite(buzzer,LOW);

lcd.clear();

lcd.print("TOOL USED");

lcd.setCursor(0, 1);

delay(10);

lcd.print("CHEMICAL REACTION ");
     
Serial.print("*T"+String(DHT.humidity)+"*");

Serial.print("*T"+String(TIME )+"*");

Serial.print("*W"+String(val)+"*");

Serial.print("*D"+String(DHT.temperature)+"*");

Serial.println("*CR255G0B0*"); //Red

Serial.println("*LR255G0B0*"); //Red

Serial.println("*PR255G0B0*"); //Red

Serial.println("*MR255G0B0*"); //Red

Serial.println("*AR0G255B0*"); // GREEN

Serial.println("*OR0G255B0*"); // GREEN

Serial.println("*IR0G255B0*"); // GREEN

 delay(1000);  
  }
  
x = 0 ;
  
  
  
  
  
  // 2
  
  
  
  
  
  
  } else if (flame2 == LOW && PIR == LOW){
   
  
  
  servo4.write(180);
 
  delay(1000);
  
  servo4.write(0);
 
  for (x = 0; x <= 5; x += 1) { 
 
 DHT.read11(DHT11); 

val = map(analogRead(gas), 0, 1024, 0,100);

int TIME  = map(x, 0, 5, 0,100);
 
lcd.clear();

lcd.print("ROOM 2");

lcd.setCursor(0, 0);

delay(10);

lcd.setCursor(6, 1);

lcd.print("PEOPLE IS IN  ");

digitalWrite(buzzer,HIGH);

delay(1000);

digitalWrite(buzzer,LOW);

lcd.clear();

lcd.print("TOOL USED");

lcd.setCursor(0, 1);

delay(10);

lcd.print("CHEMICAL REACTION ");
     
Serial.print("*T"+String(DHT.humidity)+"*");

Serial.print("*T"+String(TIME )+"*");

Serial.print("*W"+String(val)+"*");

Serial.print("*D"+String(DHT.temperature)+"*");

Serial.println("*CR255G0B0*"); //Red

Serial.println("*LR255G0B0*"); //Red

Serial.println("*OR255G0B0*"); //Red

Serial.println("*MR255G0B0*"); //Red

Serial.println("*AR0G255B0*"); // GREEN

Serial.println("*PR0G255B0*"); // GREEN

Serial.println("*IR0G255B0*"); // GREEN

 delay(1000);  
  } 
x = 0 ;
 
  
  
  
  //3
  
  
  
  
  
  
  }else if (flame3 == LOW && PIR == LOW){
   
  
 
  servo4.write(180);
 
  delay(1000);
  
  servo4.write(0);
 
  for (x = 0; x <= 5; x += 1) { 
 
 DHT.read11(DHT11); 

val = map(analogRead(gas), 0, 1024, 0,100);

int TIME  = map(x, 0, 5, 0,100);
 
lcd.clear();

lcd.print("ROOM 3");

lcd.setCursor(0, 0);

delay(10);

lcd.setCursor(6, 1);

lcd.print("PEOPLE IS IN  ");

digitalWrite(buzzer,HIGH);

delay(1000);

digitalWrite(buzzer,LOW);

lcd.clear();

lcd.print("TOOL USED");

lcd.setCursor(0, 1);

delay(10);

lcd.print("CHEMICAL REACTION ");
     
Serial.print("*T"+String(DHT.humidity)+"*");

Serial.print("*T"+String(TIME )+"*");

Serial.print("*W"+String(val)+"*");

Serial.print("*D"+String(DHT.temperature)+"*");

Serial.println("*CR255G0B0*"); //Red

Serial.println("*LR255G0B0*"); //Red

Serial.println("*IR255G0B0*"); //Red

Serial.println("*MR255G0B0*"); //Red

Serial.println("*AR0G255B0*"); // GREEN

Serial.println("*PR0G255B0*"); // GREEN

Serial.println("*OR0G255B0*"); // GREEN

 delay(1000);  
  } 
x = 0 ;
  
  


  // 4
  
  

  
  }else if (flame1 == LOW && PIR == HIGH){
   
  
  
 servo1.write(0);
 
  servo2.write(30);
  
  servo3.write(90);
  
  delay(1000);
  
  servo3.write(0);
 
  for (x = 0; x <= 5; x += 1) { 
 
 DHT.read11(DHT11); 

val = map(analogRead(gas), 0, 1024, 0,100);

int TIME  = map(x, 0, 5, 0,100);
 
lcd.clear();

lcd.print("ROOM 1");

lcd.setCursor(0, 0);

delay(10);

lcd.setCursor(6, 1);

lcd.print("PEOPLE IS NOT IN  ");

digitalWrite(buzzer,HIGH);

delay(1000);

digitalWrite(buzzer,LOW);

lcd.clear();

lcd.print("TOOL USED");

lcd.setCursor(0, 1);

delay(10);

lcd.print("ELIDE ball ");
     
Serial.print("*T"+String(DHT.humidity)+"*");

Serial.print("*T"+String(TIME )+"*");

Serial.print("*W"+String(val)+"*");

Serial.print("*D"+String(DHT.temperature)+"*");

Serial.println("*CR0G255B0*"); //GREEN

Serial.println("*LR0G255B0*"); //GREEN

Serial.println("*PR255G0B0*"); //Red

Serial.println("*MR255G0B0*"); //Red

Serial.println("*AR255G0B0*"); // Red

Serial.println("*OR0G255B0*"); // GREEN

Serial.println("*IR0G255B0*"); // GREEN

 delay(1000);  
  }
  
x = 0 ;
  
  
  
  
//5

  
  
  
  } else if (flame2 == LOW && PIR == HIGH){
   
  
  
 servo1.write(45);
 
  servo2.write(40);
  
  servo3.write(90);
  
  delay(1000);
  
  servo3.write(0);
 
 
 
  for (x = 0; x <= 5; x += 1) { 
 
 DHT.read11(DHT11); 

val = map(analogRead(gas), 0, 1024, 0,100);

int TIME  = map(x, 0, 5, 0,100);
 
lcd.clear();

lcd.print("ROOM 1");

lcd.setCursor(0, 0);

delay(10);

lcd.setCursor(6, 1);

lcd.print("PEOPLE IS NOT IN  ");

digitalWrite(buzzer,HIGH);

delay(1000);

digitalWrite(buzzer,LOW);

lcd.clear();

lcd.print("TOOL USED");

lcd.setCursor(0, 1);

delay(10);

lcd.print("ELIDE ball ");
     
Serial.print("*T"+String(DHT.humidity)+"*");

Serial.print("*T"+String(TIME )+"*");

Serial.print("*W"+String(val)+"*");

Serial.print("*D"+String(DHT.temperature)+"*");

Serial.println("*CR0G255B0*"); //GREEN

Serial.println("*LR0G255B0*"); //GREEN

Serial.println("*OR255G0B0*"); //Red

Serial.println("*MR255G0B0*"); //Red

Serial.println("*AR255G0B0*"); // Red

Serial.println("*PR0G255B0*"); // GREEN

Serial.println("*IR0G255B0*"); // GREEN

 delay(1000);  
  } 
x = 0 ;
  
  
  
  
  //6
  
  
  
  }else if (flame3 == LOW && PIR == LOW){
   
  
 servo1.write(90);
 
  servo2.write(40);
  
  servo3.write(90);
  
  delay(1000);
  
  servo3.write(0);
 
  for (x = 0; x <= 5; x += 1) { 
 
 DHT.read11(DHT11); 

val = map(analogRead(gas), 0, 1024, 0,100);

int TIME  = map(x, 0, 5, 0,100);
 
lcd.clear();

lcd.print("ROOM 1");

lcd.setCursor(0, 0);

delay(10);

lcd.setCursor(6, 1);

lcd.print("PEOPLE IS NOT IN  ");

digitalWrite(buzzer,HIGH);

delay(1000);

digitalWrite(buzzer,LOW);

lcd.clear();

lcd.print("TOOL USED");

lcd.setCursor(0, 1);

delay(10);

lcd.print("ELIDE ball ");
     
Serial.print("*T"+String(DHT.humidity)+"*");

Serial.print("*T"+String(TIME )+"*");

Serial.print("*W"+String(val)+"*");

Serial.print("*D"+String(DHT.temperature)+"*");

Serial.println("*CR0G255B0*"); //GREEN

Serial.println("*LR0G255B0*"); //GREEN

Serial.println("*PR255G0B0*"); //Red

Serial.println("*MR255G0B0*"); //Red

Serial.println("*AR255G0B0*"); // Red

Serial.println("*IR0G255B0*"); // GREEN

Serial.println("*OR0G255B0*"); // GREEN

 delay(1000);  
  
  } 

x = 0 ;

  }
  
delay (100);

}
