const byte ledPin = 13;
volatile byte state = LOW;
 
void setup(){
   pinMode(ledPin, OUTPUT);
   pinMode(A0, INPUT_PULLUP);
   Serial.begin(9600);


   PCMSK0 = B00001111; //enable pins d8 to d13
   PCMSK1 = B01111111; //enable all analog pins
   PCMSK2 = B11111101; //enable pins d0 to d7
   
   PCIFR = B11111111; // clear all interrupt flags
   PCICR = B00000111; // enable PCIE1 group
   
   while(1){}
}
 
void loop(){
   
}
 
  ISR(PCINT0_vect){
   state = !state;
  Serial.println("ISR " + String(state));
   digitalWrite(ledPin, state);
}


ISR(PCINT1_vect) {
   state = !state;
  Serial.println("ISR " + String(state));
   digitalWrite(ledPin, state);
}
ISR(PCINT2_vect){
  state = !state;
  Serial.println("ISR " + String(state));
   digitalWrite(ledPin, state);
}
