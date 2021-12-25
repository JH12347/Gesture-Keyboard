#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<SoftwareSerial.h>

SoftwareSerial btSerial(9,8);    //시리얼 통신 이름, 포트 설정
LiquidCrystal_I2C lcd(0x27,16,2);  //lcd 설정

#define RowBtn 2  //행 바꿈 버튼
#define ColumnBtn 3  //열 바꿈 버튼(공백)
#define ResetBtn 4  //초기화 버튼
#define UndoBtn 5  //정정
#define ShiftBtn 6  //대소문자 변경 버튼(쉬프트)
#define InputBtn 7  //입력 제어 버튼

volatile int Row=0;
volatile int Column=0;
int i=0;

//행 변환 인터럽트 함수
void RowChange(){
  Row=!Row;
}

//열 변환 인터럽트 함수
void ColumnChange(){
  Column++;
  if(Column>15){
    Column=0;
  }
}

void setup(){
  //블루투스 통신 설정
  btSerial.begin(9600);
  Serial.begin(9600);

  //버튼 입력 설정
  pinMode(RowBtn,INPUT);
  pinMode(ColumnBtn,INPUT);
  pinMode(ResetBtn,INPUT);
  pinMode(ShiftBtn,INPUT);
  pinMode(InputBtn,INPUT);
  pinMode(UndoBtn,INPUT);

  //lcd 기본 설정+
  lcd.init();
  lcd.backlight();
  lcd.blink();

  attachInterrupt(0,RowChange,RISING);  //행 변환 인터럽트
  attachInterrupt(1,ColumnChange,RISING);  //열 변환 인터럽트
}



void loop(){
  for(Column=0;Column<16;){
    lcd.setCursor(Column,Row);
    delay(38);
    int Input=digitalRead(InputBtn);  //입력 버튼
    btSerial.write(Input);
    
    int Shift=digitalRead(ShiftBtn);  //대소문자 버튼
    
    if(btSerial.available()!=0){
      char inputStr = btSerial.read();
        
      if(Shift==LOW){
        lcd.print(inputStr);
      }

      else{
        switch(inputStr){
          case 'a':
              lcd.print('A');
              break;
          case 'b':
              lcd.print('B');
              break;
          case 'c':
              lcd.print('C');
              break;
          case 'd':
              lcd.print('D');
              break;
          case 'e':
              lcd.print('E');
              break;
          case 'f':
              lcd.print('F');
              break;
          case 'g':
              lcd.print('G');
              break;
          case 'h':
              lcd.print('H');
              break;
          case 'i':
              lcd.print('I');
              break;
          case 'j':
              lcd.print('J');
              break;
          case 'k':
              lcd.print('K');
              break;
          case 'l':
              lcd.print('L');
              break;
          case 'm':
              lcd.print('M');
              break;
          case 'n':
              lcd.print('N');
              break;
          case 'o':
              lcd.print('O');
              break;
          case 'p':
              lcd.print('P');
              break;
          case 'q':
              lcd.print('Q');
              break;
          case 'r':
              lcd.print('R');
              break;
          case 's':
              lcd.print('S');
              break;
          case 't':
              lcd.print('T');
              break;
          case 'u':
              lcd.print('U');
              break;
          case 'v':
              lcd.print('V');
              break;
          case 'w':
              lcd.print('W');
              break;
          case 'x':
              lcd.print('X');
              break;
          case 'y':
              lcd.print('Y');
              break;
          case 'z':
              lcd.print('Z');
              break;
          default:
              lcd.print(inputStr);
              break;
        }
      }
      Column++;
    }

    int Reset;
    Reset=digitalRead(ResetBtn);  //리셋 버튼

    if(Reset==HIGH){
      lcd.clear();
      Column=0;
      Row=0;
    }

    int Undo;
    Undo=digitalRead(UndoBtn);

    if(Undo!=i){
      if(Undo==HIGH){
        if(Column>=0){
          Column--;
          lcd.setCursor(Column,Row);
          lcd.print(' ');
        }
        i=1;
      }
      else{
        i=0;
      }
    }
  }
  btSerial.flush();
  delay(1000);
}
