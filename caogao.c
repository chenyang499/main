



//  x = 0.078*sin(temp*2*pi/n);
//  y = -0.065-0.078*cos(temp*2*pi/n);
//  z = 0.0513;
//  move_cat.go_to_r(x,y,z,0);
//  temp+=1;

     
//        move_cat.SetServoAngle_1(1, motors_pos[1]);
//        move_cat.SetServoAngle_2(2, motors_pos[2]);
//        move_cat.SetServoAngle_0(0, motors_pos[0]);
//
//        move_cat.SetServoAngle_left_1(4, motors_pos[4]);
//        move_cat.SetServoAngle_left_2(5, motors_pos[5]);
//        move_cat.SetServoAngle_left_0(3, motors_pos[3]);
//        
//
//        move_cat.SetServoAngle_1(7, motors_pos[7]);
//        move_cat.SetServoAngle_2(8, motors_pos[8]);
//        move_cat.SetServoAngle_0(6,motors_pos[6]);
//
//        move_cat.SetServoAngle_left_1(10, motors_pos[10]);
//        move_cat.SetServoAngle_left_2(11, motors_pos[11]);
//        move_cat.SetServoAngle_left_0(9, motors_pos[9]);


//
//
//
//// if(order_move == 3) 
////    {
////        move_cat.SetServoAngle(1, 0);
////        move_cat.SetServoAngle_2(2, order*10);
////        move_cat.SetServoAngle_1(0, order*10);
////
////        move_cat.SetServoAngle_left(4, order*10);
////        move_cat.SetServoAngle_left_2(5, order*10);
////        move_cat.SetServoAngle_left_1(3, order*10);
//        
////
////        move_cat.SetServoAngle(7, order*10);
////        move_cat.SetServoAngle_2(8, order*10);
////        move_cat.SetServoAngle_1(6, order*10);
////
////        move_cat.SetServoAngle_left(10, order*10);
////        move_cat.SetServoAngle_left_2(11, order*10);
////        move_cat.SetServoAngle_left_1(9, order*10);
//        
////    }
////    if(order_move == 0)
////    {
////      if(angle >= 115)
////      {
////        steps  = -0.2;
////      }
////      if(angle <=0) 
////      {
////        steps = 0.2;
////      }
////      angle += steps;
////      move_cat.SetServoAngle(1, angle);
////      move_cat.SetServoAngle(2, angle);
////      move_cat.SetServoAngle_1(0, angle);
////
////      move_cat.SetServoAngle(7, angle);
////      move_cat.SetServoAngle(8, angle);
////      move_cat.SetServoAngle_1(6, angle);
//
//
////
////      move_cat.SetServoAngle_left(4, angle);
////        move_cat.SetServoAngle_left(5, angle);
////        move_cat.SetServoAngle_left_1(3, angle);
//        
////        move_cat.SetServoAngle_left(10, angle);
////        move_cat.SetServoAngle_left(11, angle);
////        move_cat.SetServoAngle_left_1(9, angle);
//      
//    }
//
//    
//  // put your main code here, to run repeatedly:
////  move_cat.SetServoAngle(0, 0);
////  move_cat.SetServoAngle(0, 120);
////  if(irrecv.decode(&results))
////  {
////    Serial.println(results.value);
////    if(results.value == 16750695) move_cat.SetServoAngle(0, 0);
////    if(results.value == 16753245) move_cat.SetServoAngle(0, 10);
////    if(results.value == 16736925) move_cat.SetServoAngle(0, 20);
////    if(results.value == 16769565) move_cat.SetServoAngle(0, 30);
////    if(results.value == 16720605) move_cat.SetServoAngle(0, 40);
////    if(results.value == 16712445) move_cat.SetServoAngle(0, 50);
////    if(results.value == 16761405) move_cat.SetServoAngle(0, 60);
////    if(results.value == 16769055) move_cat.SetServoAngle(0, 70);
////    if(results.value == 16754775) move_cat.SetServoAngle(0, 80);
////    if(results.value == 16748655) move_cat.SetServoAngle(0, 90);
////    if(results.value == 16738455) move_cat.SetServoAngle(0, 100);
////    if(results.value == 16756815) move_cat.SetServoAngle(0, 110);
////    if(results.value == 16726215) move_cat.SetServoAngle(0, 120);
////    irrecv.resume();
////  }
