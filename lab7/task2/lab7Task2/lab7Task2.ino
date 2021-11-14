int first = 4, second = 5, third = 6, fourth = 7;
const int myDelay = 500;
void setup() {
// put your setup code here, to run once:
DDRD = 0xFF;
PORTD = B11110000;


long myTime = millis();
 while (millis() - myTime < myDelay){}
}

void loop() {

  if(!(PORTD&(1<<0))){
    first--;
    PORTD |= (1 << first);
    
    if(first+1 != second)    {PORTD &= ~(1<<first+1);}
    
}

 else if( PORTD&(1<<0)&& !( PORTD&(1<<1) ))  {
    second--;
    first = second-1;
    
    PORTD &= ~(1<<0);
    
    PORTD |= (1 << second);
    PORTD |= (1 << first);

    if(second + 1 != third){PORTD &= ~(1<<second+1);}   // delete unnecessary bits
    }
  else if((PORTD & 0x03) && !(PORTD & (1<<2))){
    third--;
    second = third - 1;
    first = second - 1;

    PORTD &= ~(1<<0);                                   // delete unnecessary bits
    PORTD &= ~(1<<1);                                   // delete unnecessary bits
    
    PORTD |= (1<<third);
    PORTD |= (1<<second);
    PORTD |= (1<<first);

    if(third + 1 != fourth){PORTD &= ~(1<<third+1);}    // delete unnecessary bits
    }

    else if ((PORTD & 0x07) && !(PORTD & (1<<3)) ){
      fourth--;
      third = fourth - 1;
      second = third -1;
      first = second - 1;

      PORTD &= ~(0x07);     // delete unnecessary bits

      PORTD |= (1<<fourth);
      PORTD |= (1<<third);
      PORTD |= (1<<second);
      PORTD |= (1<<first);

      if(fourth != 7) {PORTD &= ~(1<<fourth +1);}
      }

      else
      {
        first = 4, second = 5, third = 6, fourth = 7;
        PORTD ^= 0xFF;
        }
  


    
        long myTime = millis();
        while (millis() - myTime < myDelay){}
}
