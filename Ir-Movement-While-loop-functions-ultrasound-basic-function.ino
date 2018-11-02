int m1 = 5; //right wheel +ve direction
int m2 = 6; //left wheel -ve direction
int en1 = 10; //right wheel -ve direction
int en2 = 11; //left wheel +ve direction
int ir1 = 9;//right wheel -ve direction
int ir2 = 8;
int ir3 = 7;
#define trigPin 13
#define echoPin 12
void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
while((digitalRead(ir2) == LOW)){
    while (ultrasound() <= 10){
       stp(50);
     }
    
     fwd(30);
    
   }
   
 if (((digitalRead(ir3) == HIGH) && digitalRead(ir2) == HIGH && digitalRead(ir1) == HIGH));{ //Don't move
     stp(50);
     }
   while(digitalRead(ir1) == LOW){;//rotate right
     right(30);
   }
   while (digitalRead(ir3) == LOW){;//rotate left
     left(30);
   }
}
void stp(int delayTimer){
     digitalWrite(5, LOW); //==========
     digitalWrite(10, LOW);//Stopping
     digitalWrite(6, LOW);//quickly
     digitalWrite(11, LOW);//========
     delay(delayTimer);
   }
void fwd(int delayTimer){
     digitalWrite(5, LOW);//========
      analogWrite(10, 158);//Forward
      analogWrite(6, 158);//
      digitalWrite(11, LOW);//==========
     delay(delayTimer);
   }
void left(int delayTimer){
     digitalWrite(5, LOW); //==========
     analogWrite(10, 158);//turning left from forwards
     digitalWrite(6, LOW);//quickly
     analogWrite(11, 158);//========
     delay(delayTimer);
   }
void right(int delayTimer){
     analogWrite(5, 158); //===========
     digitalWrite(10, LOW);// turning right from forwards
     analogWrite(6, 158);//quickly
     digitalWrite(11, LOW);
     delay(delayTimer);
   }
long ultrasound(){
  long duration, distance;
     digitalWrite(trigPin, LOW);  // Added this line
     delayMicroseconds(2); // Added this line
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10); // Added this line
     digitalWrite(trigPin, LOW);
     duration = pulseIn(echoPin, HIGH);
     distance = (duration/2) / 29.1;
     return (distance);
}


