/*
*Locker guard based on Arduino Uno
* This system generates a beep sound whenever someone attempts to open the locked safe. 
*
*for more detail about this project please visit:
*https://arduinounomagic.com/locker-guard-based-on-arduino-uno-story/

*Copyright (C) 2007 Free Software Foundation, Inc. <arduinounomagic@gmail.com>
*for more projects based on Arduino uno please visit: https://arduinounomagic.com/
*/

#include<LiquidCrystal.h> // Include LCD header file.

 
LiquidCrystal G_LCD(12, 11, 5, 4, 3, 2); // Configure pins of LCD {LCD object name(RS, Enable, data pin-4, data pin-5, data pin-6, data pin-7).
 
const intG_LDR=A0; // Connect LDR to pin AO
const int G_BUZZER=6; // Connect buzzer to pin 6
 
void setup() 
{
Serial.begin(9600);
G_LCD.begin(16, 2); // Initallize the dimension of the display (width, height)
G_LCD.clear(); // Clears the display
pinMode(G_LDR, INPUT); // Set LDR as input
pinMode(G_BUZZER, OUTPUT); // Set buzzer as output
}
 
void loop()
 {
G_LCD.setCursor(0,0); // Set the location of the displayed text to be written on LCD at colomn:0, row:0
G_LCD.print(“Sensor value:”); // This statement prints on LCD screen

G_LCD.print(analogRead(G_LDR)); // Read data from LDR and print on LCD

int light_sensor=analogRead(G_LDR);// Store the value of LDR in light_sensor named integer variable.
delay(200);
G_LCD.setCursor(0,2);// Set the location of the displayed text to be written on LCD at colomn:0, row:2
 
if (light_sensor>=100) // If the value of LDR stored in light_sensor is greater than and equal to 100 
{
 G_LCD.setCursor(0,1); // Set the location of the displayed text to be written on LCD at colomn:0, row:1
  G_LCD.print(“it’s bright“); //Its bright 
tone(G_BUZZER, 1000);// Buzzer on with 1 KHz sound signal
delay(1000); // Delay for 1 sec
noTone(G_BUZZER);// Stop sound
G_LCD.clear(); // Clear the display
}
else
{
   G_LCD.setCursor(0,1); // Set the location of the displayed text to be written on LCD at colomn:0, row:1

  G_LCD.print(“it’s dark“); //Its dark
noTone(G_BUZZER); //Stop sound
}
}
