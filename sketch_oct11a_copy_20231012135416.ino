#include <Ultrasonic.h>
#include <Servo.h>
#include <SoftwareSerial.h>


int trigPin = 12;
int echoPin = 13;
int servoPin = 9;
int interrupcao = 0;
int pinoRX = 7;
int pinoTX = 8;

int informacao;  

SoftwareSerial bluetooth(pinoTX, pinoRX); 

Ultrasonic ultrasonic(trigPin, echoPin);
int distance;

Servo servomotor;
int pos = 0; 

void setup() {

  Serial.begin(9600);
  bluetooth.begin(9600);
  delay(100); 

  servomotor.attach(9);
}

void loop() {
if (bluetooth.available() > 0)
{
  informacao = bluetooth.read();
}
  distance = ultrasonic.read();
  Serial.println(interrupcao);
  
  Serial.println(distance);
  delay(100);
  if (interrupcao < 2)
  {
    if (distance < 25){
      digitalWrite(servoPin, HIGH);
      
      for(pos = 0; pos <= 179; pos += 1) {  
        servomotor.write(pos);
        delay (15);
      }
      interrupcao += 1;
    }
    if (interrupcao >= 2){
    bluetooth.print("capturado");
    }
    
  }


}