#define SagMotor1 8
#define SagMotor2 10

#define SolMotor1 9
#define SolMotor2 11

#define sensor1 14
#define sensor2 15
#define sensor3 16
#define sensor4 17
#define sensor5 18

int sensor1Deger, sensor2Deger, sensor3Deger, sensor4Deger, sensor5Deger;

void setup()
{ 
  Serial.begin(9600);

    
  pinMode(SagMotor1, OUTPUT);
  pinMode(SagMotor2, OUTPUT);
  
  pinMode(SolMotor1, OUTPUT);
  pinMode(SolMotor2, OUTPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
}

void loop()
{
  sensor1Deger = digitalRead(sensor1);
  sensor2Deger = digitalRead(sensor2);
  sensor3Deger = digitalRead(sensor3);
  sensor4Deger = digitalRead(sensor4);
  sensor5Deger = digitalRead(sensor5);
  Serial.println(sensor1Deger);

  if (sensor1Deger == 0) {
     digitalWrite(SolMotor1, HIGH);
   
 digitalWrite(SolMotor2, HIGH);
 
 digitalWrite(SagMotor1, HIGH);
 
 digitalWrite(SagMotor2, HIGH);
      
    } else if (sensor3Deger == 0) {
           TurnLeft();
        } else {
           digitalWrite(SolMotor1, HIGH);
   
 digitalWrite(SolMotor2, HIGH);
 
 digitalWrite(SagMotor1, LOW);
 
 digitalWrite(SagMotor2, LOW);
}

}

void TurnLeft() {
 digitalWrite(SolMotor1, LOW);
   
 digitalWrite(SolMotor2, LOW);
 
 digitalWrite(SagMotor1, HIGH);
 
 digitalWrite(SagMotor2, HIGH);
}
