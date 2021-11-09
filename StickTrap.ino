const int led = 13;
// Input Switches
const int INPUT1 = A1;
const int INPUT2 = A0;
const int INPUT3 = A3;
const int INPUT4 = A2;

// Output Relays
const int j1 = 10;
const int j2 = 11;
const int j3 = 12;
const int j4 = 6;

// Input Micro switches
//const int K1 = 2;  //
//const int K2 = 3;   // +
//const int K3 = 4;   // -
//const int K4 = 5;   // save

const int relayDelayInterval = 2500;
unsigned long int rdi = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
   
  pinMode(INPUT1, INPUT_PULLUP);
  pinMode(INPUT2, INPUT);
  pinMode(INPUT3, INPUT);
  pinMode(INPUT4, INPUT);
  
 // Input Micro switches
//  pinMode(K1, INPUT);
//  pinMode(K2, INPUT);
//  pinMode(K3, INPUT);
//  pinMode(K4, INPUT);
}

void loop() {   
  if(digitalRead(INPUT1)==LOW) {
    digitalWrite(led, HIGH); 
    digitalWrite(j1, HIGH);
    rdi  = millis();
  }

      if (millis() > (relayDelayInterval + rdi)) {
        digitalWrite(j1, LOW);
        digitalWrite(led, LOW); 
        rdi  = millis();
    }
  
}
