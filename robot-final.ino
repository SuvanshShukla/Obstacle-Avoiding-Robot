#include <Servo.h>
Servo myservo;

int trig = 4;
int echo = 5;
float d, t;


void setup() {
  // put your setup code here, to run once:
  //right motor- 8,9
  //left motor - 2,3
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT); //left motor
  pinMode(9, OUTPUT); //left motor

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);  
  

  myservo.attach(6);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  lookLeft();
  lookRight();

  moveForward();
}

void moveForward(){
  //this moves the wheels forward
    digitalWrite(2, HIGH);  //forward
    digitalWrite(8, HIGH);  //forward
    
    digitalWrite(3, LOW);   
    digitalWrite(9, LOW);
}

void moveStop(){
  //this stops the motor
    digitalWrite(2, LOW); 
    digitalWrite(8, LOW);    
    digitalWrite(3, LOW);   
    digitalWrite(9, LOW);
}

void moveBackward(){
  //this moves the robot backward
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    
    digitalWrite(3, HIGH);  //backward
    digitalWrite(9, HIGH);  //backward
}

void moveRight(){
  //thismoves the robot right
    digitalWrite(2, HIGH); 
    digitalWrite(8, LOW);    
    digitalWrite(3, LOW);  
    digitalWrite(9, LOW); 
    delay(500);

    //this moves the wheels forward
    digitalWrite(2, HIGH);  //forward
    digitalWrite(8, HIGH);  //forward
    
    digitalWrite(3, LOW);   
    digitalWrite(9, LOW);
}

void moveLeft(){
  //this moves the robot left
    digitalWrite(2, LOW); 
    digitalWrite(8, HIGH);    
    digitalWrite(3, LOW);  
    digitalWrite(9, LOW); 
    delay(500);

    //this moves the wheels forward
    digitalWrite(2, HIGH);  //forward
    digitalWrite(8, HIGH);  //forward
    
    digitalWrite(3, LOW);   
    digitalWrite(9, LOW);
}

int readDistance(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);
  d = 0.01715 * t;

  return d;  
}

void lookLeft(){ 
    myservo.write(30);  //this line is used for rotating left change for more left
    delay(1000);
    int distance = readDistance();
    myservo.write(75);
    delay(500);
    return distance;
    delay(100);
  
}

void lookRight(){
    myservo.write(120);  //this line is used for rotating left change for more right 
    delay(1000);
    int distance = readDistance();
    myservo.write(75);
    delay(500);
    return distance;
    delay(100); 
}
