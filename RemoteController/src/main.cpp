#include <Arduino.h>
#include <SoftwareSerial.h>
#define BT_RX 2
#define BT_TX 3
#define VRx A1
#define VRy A2

SoftwareSerial masterSerial(BT_RX, BT_TX);

void setup() {
  Serial.begin(9600);           // Serial monitor communication
  Serial.println("Master initialized");
  masterSerial.begin(9600);     // Communication with the HC-05 module
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

}

const int xCenter = 500;
const int yCenter = 500;
const int threshold = 200;
void loop() {

  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  if (xValue < xCenter - threshold){ 
    masterSerial.write('B');
    Serial.println("Sent: B");
    Serial.print(xValue);
    Serial.print(" ");
    Serial.println(yValue);
  }
  if (xValue > xCenter + threshold ){
    masterSerial.write('F');
    Serial.println("Sent: F");
    Serial.print(xValue);
    Serial.print(" ");
    Serial.println(yValue);
  }
  if (yValue < yCenter - threshold){ 
    masterSerial.write('L');
    Serial.println("Sent: L");
    Serial.print(xValue);
    Serial.print(" ");
    Serial.println(yValue);
  }
  if (yValue > yCenter + threshold) {
    masterSerial.write('R');
    Serial.println("Sent: R");
    Serial.print(xValue);
    Serial.print(" ");
    Serial.println(yValue);
  }

}

