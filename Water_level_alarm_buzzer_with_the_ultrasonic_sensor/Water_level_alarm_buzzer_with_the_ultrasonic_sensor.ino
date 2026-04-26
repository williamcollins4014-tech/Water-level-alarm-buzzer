#include <HCSR04.h>

byte triggerPin = 9;
byte echoPin = 10;

const int alarmPin = 11; // Assign pin D11 to the variable 'alarmPin'

void setup () {
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
  pinMode(alarmPin, OUTPUT); // Configure D11 as an output
}

void loop () {
  double* distances = HCSR04.measureDistanceCm();
  
  // 1. Print the numerical distance value for the plotter
  Serial.print("Dist(cm):"); 
  Serial.println(distances[0]); 
  
  // Check if the distance is less than 20 cm. If so, turn the buzzer on!
  if (distances[0]<20){
    digitalWrite(alarmPin, HIGH);
  }
  else{
    digitalWrite(alarmPin, LOW);
  }
  delay(250);
}
