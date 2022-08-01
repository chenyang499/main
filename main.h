#include "move.h"

#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

move move_cat;

int order = 0;

double angle =0;
double steps = 0.1;
double angle_1 = 60;
double angle_2 = 0;
double steps_1 = 0.2;
double steps_2 = 0.2;
int keep[3] = {0,110,0};
double temp = 0;
int n = 200;
double x,y,z;

int read_up()
{
  int order = -1;
   if(irrecv.decode(&results))
  {
    Serial.println(results.value);
    if(results.value == 16750695) order = 0;
    if(results.value == 16753245) order=  1;
    if(results.value == 16736925) order =  2;
    if(results.value == 16769565) order =  3;
    if(results.value == 16720605) order =  4;
    if(results.value == 16712445) order =  5;
    if(results.value == 16761405) order = 6;
    if(results.value == 16769055) order = 7;
    if(results.value == 16754775) order = 8;
    if(results.value == 16748655) order = 9;
    if(results.value == 16738455) order = 10;
    if(results.value == 16756815) order = 11;
    if(results.value == 16726215) order = 12;
    if(results.value == 16718055) order = 13;
    if(results.value == 16734885) order = 14;
    if(results.value == 16730805) order = 15;
    if(results.value == 16716015) order = 16;
    irrecv.resume();
  }
  return order; 
}
 
