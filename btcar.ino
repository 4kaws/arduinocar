//#define LED 13  // The pin the LED is connected to PIN 13 
int Input_Pin_4 = 3;
int Input_Pin_3 = 4;
int Input_Pin_2 = 5;
int Input_Pin_1 = 6;
char Value;
//const int buzzer = 11; //buzzer to arduino pin 11
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 // pinMode(LED, OUTPUT); // Declare the LED as an output
 //pinMode(buzzer, OUTPUT); // Set buzzer - pin 11 as an output
  pinMode(Input_Pin_4, OUTPUT);  // Digital pin 3
  pinMode(Input_Pin_3, OUTPUT);  // Digital pin 4
  pinMode(Input_Pin_2, OUTPUT);  // Digital pin 5
  pinMode(Input_Pin_1, OUTPUT);  // Digital pin 6
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    Value = Serial.read();
    Serial.println(Value);
  }

  if ( Value == 'F') {
    // Robo Pe_t Run Forward
    digitalWrite(Input_Pin_1, HIGH);
    digitalWrite(Input_Pin_2, LOW);
    digitalWrite(Input_Pin_3, HIGH);
    digitalWrite(Input_Pin_4, LOW);
    analogWrite(8, 255);
    analogWrite(9, 255);
  } else if (Value == 'B') {
    //Robo Pet Run Backward
    digitalWrite(Input_Pin_1, LOW);
    digitalWrite(Input_Pin_2, HIGH);
    digitalWrite(Input_Pin_3, LOW);
    digitalWrite(Input_Pin_4, HIGH);
    analogWrite(8, 255);
    analogWrite(9, 255);
 //  tone(buzzer, 1000); // Send 1KHz sound signal...
 //  digitalWrite(LED, HIGH); // sets the LED on
  } 
  

  else if (Value == 'L') {
    //Robo Pet Turn Left
    digitalWrite(Input_Pin_1, HIGH);
    digitalWrite(Input_Pin_2, LOW);
    digitalWrite(Input_Pin_3, HIGH);
    digitalWrite(Input_Pin_4, LOW);
    analogWrite(8, 100);
    analogWrite(9, 255);
  }
  else if (Value == 'R') {
    //Robo Pet Turn Right
    digitalWrite(Input_Pin_1, HIGH);
    digitalWrite(Input_Pin_2, LOW);
    digitalWrite(Input_Pin_3, HIGH);
    digitalWrite(Input_Pin_4, LOW);
    analogWrite(8, 255);
    analogWrite(9, 100);
  } else if (Value == 'S') {
    //Robo Pet Stop
    digitalWrite(Input_Pin_1, LOW);
    digitalWrite(Input_Pin_2, LOW);
    digitalWrite(Input_Pin_3, LOW);
    digitalWrite(Input_Pin_4, LOW);
    analogWrite(8, 0);
    analogWrite(9, 0);
    noTone(buzzer);     // Stop sound...
 //   digitalWrite(LED, LOW);  // sets the LED off
  }
}
