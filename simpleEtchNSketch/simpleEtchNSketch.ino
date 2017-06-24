#include <Servo.h>

const int servoX = 3;       
const int servoY = 10;      
const int joystickX = A3;     
const int joystickY = A4;       

int servoVal;          
Servo myservoX;  
Servo myservoY;  



void setup() {

  // Servo  
  myservoX.attach(servoX);  
  myservoY.attach(servoY);  

  // Inizialize Serial
  Serial.begin(9600);
}


void loop(){

    outputJoystick();

    servoVal = analogRead(joystickX);          
    servoVal = map(servoVal, 0, 1023, 0, 180);     
    myservoY.write(servoVal);                        
    servoVal = analogRead(joystickY);           
    servoVal = map(servoVal, 0, 1023, 70, 180);     
    myservoX.write(servoVal);                          
    delay(15);                                       
}



void outputJoystick(){

    Serial.print(analogRead(joystickX));
    Serial.print ("---"); 
    Serial.print(analogRead(joystickY));
    Serial.println ("----------------");
} 
