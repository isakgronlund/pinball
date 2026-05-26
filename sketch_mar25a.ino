/*
* Name: Flipperspel
* Author: Isak Grönlund
* Date: 2025-10-14
* Description: This project uses two servos, one sensor, one oled screen and two buttons
* So the project is a pinballgame and it uses servos as the shooting mechanism, and the sensor is made for giving points if the ball passes in a sertant place and finally the oled screen is keeping track of the score
*/
// Include Libraries
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Servo myservo;
//setts up arduino componets
const int buttonPin = 3;
const int sensor = 10;
int i = 0;
int u = 0;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
//starts the servo, button, sensor and display
void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
pinMode(buttonPin, INPUT);
Serial.begin(9600);
pinMode(sensor, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //moves servo if button is pressed
  if (digitalRead(buttonPin)){
    myservo.write(70);
    }

    else {
    myservo.write(0);
  }
  //if else for giving points if the sensor senses movement and only gives one point without delay
  if (digitalRead(sensor)){
       Serial.print(i);
       u = 1;
    }
    else if (u == 1){
      i = i+1;
      u = 0;
    }
//Gives the oled screen instructions on how it should work
  display.clearDisplay();
  display.setTextSize(3);
  display.println(i);
  display.display();
}
