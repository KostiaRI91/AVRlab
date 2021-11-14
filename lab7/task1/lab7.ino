byte helloSegments[] = {
  0x76, // H
  0x79, // E
  0x38, // L
  0x38, // L
  0x5C, // o
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
  // нічого
};
const byte number[] = {
  0x3F,
  0x06,
  0x5B,
  0x4F,
  0x66,
  0x6D,
  0x7D,
  0x07,
  0x7F, 
  0x6F,
  0x00};
int len = sizeof(helloSegments);
const long myDelay = 150;
int thousand = 0, hundred = 0, unit = 0, tens = 0, counter = 0;
void myF(int i, int &num)
{


  PORTB |= ~PORTB; //PORTB = B111111; // встановлюємо високий рівень на пінах 8-13 порта В
  PORTB &= ~(1 << num); // встановлюємо низький рівень піна порта В
  int index = i - num >= 0 ? i - num : len - 1;
  index = index < len ? index : len - 1;
  PORTD = helloSegments[index];
  
 
 
  delay(1);
  num = (num + 1) % 4;
}

void setup() {
  DDRD = B11111111; // піни порту D (на платі 0-7 піни) позначаєм вихідними
  DDRB = B111111; // піни порту B (на платі 8-13 піни) позначаєм вихідними

  PORTB = B111111; // встановлюємо високий рівень пінів порта В (на платі 8-13 піни)
}

void loop() {

  
 if(counter<10){
 helloSegments[5] = number [unit];
  }

  
  if ((counter>=10)&(counter<100)){
     helloSegments[5] = number [tens];
     helloSegments[6] = number [unit];
     }

     if ((counter>=100)&(counter<1000)){
     helloSegments[5] = number [hundred];
     helloSegments[6] = number [tens];
     helloSegments[7] = number [unit];
     }


     if ((counter>=1000)&(counter<10000)){
     helloSegments[5] = number [thousand];
     helloSegments[6] = number [hundred];
     helloSegments[7] = number [tens];
     helloSegments[8] = number [unit];
     }
  
  for (int i = 0; i < len + 3; i++)
  {
    
    int num = 0;
    long myTime = millis();
    delay(1);
    while (millis() - myTime < myDelay)
    {
      myF(i, num);
    }                                                                   
  }





    unit++;
     counter++;
    if (unit % 10 == 0) {
      unit = 0;
      tens++;
      if (tens % 10 == 0)
      {                                                                           //count from 0 to 10 000 and then 0
        tens = 0;
        hundred++;
        if (hundred % 10 == 0)
        {
          hundred = 0;
          thousand++;
          if (thousand % 10 == 0)
          {
            unit = 0; thousand = 0; tens = 0; hundred = 0; counter = 0;

          }
        
      }
    }
  }


  
}
