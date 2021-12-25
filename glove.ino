#include <SoftwareSerial.h>

SoftwareSerial btSerial(5,6);  //RX, TX

#define pinY A0  //y축 회전

#define pinFLEX1 A7  //엄지 
#define pinFLEX2 A6  //검지
#define pinFLEX3 A5  //중지 
#define pinFLEX4 A4  //약지
#define pinFLEX5 A3  //소지

#define pinLED 12

int i=0;

//variable initializtion
int flexADC1; 
int flexADC2; 
int flexADC3; 
int flexADC4; 
int flexADC5;

int yadc;

void setup(){
  btSerial.begin(9600);
  Serial.begin(9600);

  pinMode(pinFLEX1,INPUT);
  pinMode(pinFLEX2,INPUT);
  pinMode(pinFLEX3,INPUT);
  pinMode(pinFLEX4,INPUT);
  pinMode(pinFLEX5,INPUT);
  
  pinMode(pinY,INPUT);
  
  pinMode(pinLED,OUTPUT);
}

void loop() {
  int Signal;
  Signal=btSerial.read();
  
  flexADC1=analogRead(pinFLEX1); //엄지 데이터
  flexADC2=analogRead(pinFLEX2); //검지 데이터
  flexADC3=analogRead(pinFLEX3); //중지 데이터
  flexADC4=analogRead(pinFLEX4); //약지 데이터
  flexADC5=analogRead(pinFLEX5); //소지 데이터

  yadc = analogRead(pinY); //y축 회전 아날로그 데이터

  if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=400)&&(yadc<=450))){  //A (0 1 1 0 0 1)
    char cp='a';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }

  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5<=730) && ((yadc>=400)&&(yadc<=450))){  //B (1 1 1 0 0 1)
    char cp='b';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }

  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //C (0 1 0 0 1 0)
    char cp='c';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=630) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //D (1 1 1 0 1 1)*
    char cp='d';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
      
  else if((flexADC1>=780) && (flexADC2<=730) && (flexADC3>=720) && (flexADC4<=640) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //E (1 0 1 0 1 0)*
    char cp='e';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2<=730) && (flexADC3>=720) && (flexADC4>=680) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //F (1 0 1 1 1 0)*
    char cp='f';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }

  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=400)&&(yadc<=450))){  //G (0 1 0 0 0 1)
    char cp='g';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
    
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=630) && (flexADC5>=760) && ((yadc>=400)&&(yadc<=450))){  //H (1 1 0 0 1 1)*
    char cp='h';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //I (0 0 0 0 1 0)
    char cp='i';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //J (0 0 0 0 1 1)
    char cp='j';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4>=700) && (flexADC5<=720) && ((yadc>=270)&&(yadc<=320))){  //K (0 1 0 1 0 0)
    char cp='k';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=270)&&(yadc<=320))){  //L (1 1 0 0 0 0)
    char cp='l';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=765) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5<=720) && ((yadc>=400)&&(yadc<=450))){  //M (0 1 1 1 0 1)*
    char cp='m';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=765) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4>=700) && (flexADC5<=780) && ((yadc>=400)&&(yadc<=450))){  //N (0 1 0 1 0 1)*
    char cp='n';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }

  else if((flexADC1<=755) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=400)&&(yadc<=450))){  //O (0 0 0 0 0 1) 
    char cp='o';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=270)&&(yadc<=320))){  //P (1 0 0 0 0 0)
    char cp='p';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=400)&&(yadc<=450))){  //Q (1 0 0 0 0 1)
    char cp='q';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=775) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4>=670) && (flexADC5>=760) && ((yadc>=270)&&(yadc<=320))){  //R (1 1 0 1 1 0)*
    char cp='r';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //S (1 1 1 0 1 0)
    char cp='s';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=400)&&(yadc<=450))){  //T (1 1 0 0 0 1)
    char cp='t';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=760) && (flexADC2<=690) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5<=740) && ((yadc>=270)&&(yadc<=320))){  //U (0 0 1 1 0 0)*
    char cp='u';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //V (0 0 0 1 1 0)
    char cp='v';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=765) && (flexADC2<=690) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5<=740) && ((yadc>=400)&&(yadc<=450))){  //W (0 0 1 1 0 1)*
    char cp='w';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=630) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //X (1 1 0 0 1 0)
    char cp='x';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //Y (1 0 0 0 1 0)
    char cp='y';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //Z (1 0 0 0 1 1)
    char cp='z';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2<=690) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=270)&&(yadc<=320))){  //0 (0 0 0 0 0 0)
    char cp='0';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4<=600) && (flexADC5<=720) && ((yadc>=270)&&(yadc<=320))){  //1 (0 1 0 0 0 0)
    char cp='1';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5<=770) && ((yadc>=270)&&(yadc<=320))){  //2 (0 1 1 0 0 0)
    char cp='2';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5<=770) && ((yadc>=270)&&(yadc<=320))){  //3 (1 1 1 0 0 0)
    char cp='3';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //4 (0 1 1 1 1 0)
    char cp='4';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=770) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //5 (1 1 1 1 1 0)
    char cp='5';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5<=720) && ((yadc>=270)&&(yadc<=320))){  //6 (0 1 1 1 0 0)
    char cp='6';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //7 (0 1 1 0 1 0)
    char cp='7';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //8 (0 1 0 1 1 0)
    char cp='8';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2<=730) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=270)&&(yadc<=320))){  //9 (0 0 1 1 1 0)*
    char cp='9';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //. (0 1 1 1 1 1)
    char cp='.';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1>=780) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //, (1 1 1 1 1 1)
    char cp=',';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3<=650) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //! (0 1 0 1 1 1)
    char cp='!';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2>=790) && (flexADC3>=720) && (flexADC4<=600) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //? (0 1 1 0 1 1)
    char cp='?';
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  
  else if((flexADC1<=755) && (flexADC2<=690) && (flexADC3>=720) && (flexADC4>=700) && (flexADC5>=770) && ((yadc>=400)&&(yadc<=450))){  //' (0 0 1 1 1 1)
    char cp=39;  //작은 따옴표 아스키코드
    digitalWrite(pinLED,LOW);
    if(Signal!=i){
      if(Signal==HIGH){
        btSerial.print(cp);
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  else{
    digitalWrite(pinLED,HIGH);
  }
  btSerial.flush();
  delay(40);
}
