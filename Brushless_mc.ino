// variables 
// const int motorpin=9; for brushed motor 
const int potpin=A0;
int pot;
int throttle;
int U_high = 7;
int U_low = 6;
int V_high = 5;
int V_low = 4;
int W_high = 3;
int W_low = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(U_high, OUTPUT);
  pinMode(U_low, OUTPUT);
  pinMode(V_high, OUTPUT);
  pinMode(V_low, OUTPUT);
  pinMode(W_high, OUTPUT);
  pinMode(W_low, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //add code that sets limit for actual motor
 // read potentiometer (0-1023) 
  pot = analogRead (potpin);
  // convert to 0-255
  throttle = map(pot,0,1023,0,255);
  // set motor speed 
  //analogWrite (motorpin,throttle);  //old code for sending potentiometer reading 
  
  //Read Hall Effect 
  bool A = digitalRead(8); //pin 
  bool B = digitalRead(9);
  bool C = digitalRead(10);

  //create integer from 2-7
  unsigned int state = A<<2 | B<<1 | C;
  

 //Run through states
 //analogwrite(pin,value) 
  switch(state)
  {
    case 4: //State 1: Phase A on, B off, C off, 100
      digitalWrite(U_high,1); 
      digitalWrite(U_low, 0);
      digitalWrite(V_high,0);
      digitalWrite(V_low, 0); 
      digitalWrite(W_high,0);
      digitalWrite(W_low, 1);
      Serial.println("4"); 
      break;
    case 5: //State 2: Phase A on, B off, C on, 101
      digitalWrite(U_high,1); 
      digitalWrite(U_low, 0);
      digitalWrite(V_high,0);
      digitalWrite(V_low, 1); 
      digitalWrite(W_high,0);
      digitalWrite(W_low, 0);
      Serial.println("5");
      break;
    case 1: //State 3: Phase A off, B off, C on, 001
      digitalWrite(U_high,0); 
      digitalWrite(U_low, 0);
      digitalWrite(V_high,0);
      digitalWrite(V_low, 1); 
      digitalWrite(W_high,1);
      digitalWrite(W_low, 0);
      Serial.println("1");
      break;
    case 3: //State 4: Phase A off, B on, C on, 011
      digitalWrite(U_high,0); 
      digitalWrite(U_low, 1);
      digitalWrite(V_high,0);
      digitalWrite(V_low, 0); 
      digitalWrite(W_high,1);
      digitalWrite(W_low, 0);
      Serial.println("3");
      break;
    case 2: //State 5: Phase A off, B on, C off, 010
      digitalWrite(U_high,0); 
      digitalWrite(U_low, 1);
      digitalWrite(V_high,1);
      digitalWrite(V_low, 0); 
      digitalWrite(W_high,0);
      digitalWrite(W_low, 0);
      Serial.println("2");
      break;
    case 6: //State 6: Phase A on, B on, C off, 110
      digitalWrite(U_high,0); 
      digitalWrite(U_low, 0);
      digitalWrite(V_high,1);
      digitalWrite(V_low, 0); 
      digitalWrite(W_high,0);
      digitalWrite(W_low, 1);
      Serial.println("6");
      break;
    default:
      // Set code that can count number of defaults and shut system down with excessive faults 
      // Ignore/shutdown 
      break;
  }
}
