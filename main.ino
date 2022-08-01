#include"main.h"

void setup() {
  move_cat.Init();
  Serial.begin(9600);
  irrecv.enableIRIn();
}
     

void loop() {
  order = read_up();
  if(order == 0)
  {
    move_cat.stand_up(move_cat,100);
    delay(1000);
  }
  else if(order == 1)
  {
    move_cat.lie_down(move_cat, 100);
    delay(1000);
  }
}
