#include "Keyboard.h"

const byte xAxis = A1; //조이스틱 x축 아날로그 핀 번호
const byte yAxis = A0; //조이스틱 y축 아날로그 핀 번호
const byte dAxis = 12; //조이스틱 버튼 핀 번호s
const byte button[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //버튼 입력 핀 번호
const char bt[] = {'n', 'l', 'k', 'j', KEY_RIGHT_SHIFT, KEY_LEFT_SHIFT, 'd', 's', 'a', KEY_ESC}; //버튼 입력키
const char joyArrow[] = {KEY_RETURN, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}; //조이스틱 방향키

void setup() {                                                                                                                                                                                             
  Keyboard.begin();
  for(int i=0; i<10; i++){ //2~11번까지의 디지털 핀 사용 선언
    pinMode(button[i], INPUT_PULLUP);
  }
  pinMode(dAxis, INPUT_PULLUP);
}

void loop() {
  int AXIS_X = analogRead(xAxis);
  int AXIS_Y = analogRead(yAxis);
  int AXIS_D = digitalRead(dAxis);
  joyStick(AXIS_D, joyArrow[0]);
  joyStickXY(AXIS_X, joyArrow[1], joyArrow[2]);
  joyStickXY(AXIS_Y, joyArrow[3], joyArrow[4]);
  for(int i=0; i<10; i++){
    key(button[i], bt[i]);
  }
}

//조이스틱 누름
void joyStick(int joyClick, char direc){
    if(joyClick == 0){
       Keyboard.press(direc);
    }
    else{
       Keyboard.release(direc);
    }
}

//조이스틱 이동
void joyStickXY(int joyXY, char direc1, char direc2){
    if(joyXY<=150){
       Keyboard.press(direc1);
    }
    else if(joyXY>=850){
       Keyboard.press(direc2);
    }
    else{
      Keyboard.release(direc1);
      Keyboard.release(direc2);  
    }
}

//버튼 누름
void key(byte btn, char selct){
  if(!digitalRead(btn)){
    Keyboard.press(selct); //키보드가 눌렸다.
  } else{
    Keyboard.release(selct); //키보드가 떨어졌다.
  }
}
