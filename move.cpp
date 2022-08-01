#include"move.h"

void move::Init()
{
    pwm.begin();
    pwm.setPWMFreq(SERVO_FREQ);           // Analog servos run at ~50 Hz updates
}

void move::SetServoPulse(uint8_t n, int pluse)
{
    int i;
    if (pluse > SERVOMAX)       i = SERVOMAX / 4.88;
    else if (pluse < SERVOMIN)  i = SERVOMIN / 4.88;
    else                        i = pluse    / 4.88;
    pwm.setPWM(n, 0, i);
}

void move::SetServoAngle(uint8_t n,double angle)
{
  switch(n)
  {
    case 0:SetServoAngle_0(0, motors_pos[0]);
    case 1:SetServoAngle_1(1, motors_pos[1]);
    case 2:SetServoAngle_2(2, motors_pos[2]);

    case 3:SetServoAngle_left_0(3, motors_pos[3]);
    case 4:SetServoAngle_left_1(4, motors_pos[4]);
    case 5:SetServoAngle_left_2(5, motors_pos[5]);

    case 6:SetServoAngle_0(6,motors_pos[6]);
    case 7:SetServoAngle_1(7, motors_pos[7]);
    case 8:SetServoAngle_2(8, motors_pos[8]);

    case 9:SetServoAngle_left_0(9, motors_pos[9]);
    case 10:SetServoAngle_left_1(10, motors_pos[10]);
    case 11:SetServoAngle_left_2(11, motors_pos[11]);
    default:  ;
  }
}

void move::SetServoAngle_1(uint8_t n, double angle)
{
    angle = 55 + angle;   
    SetServoPulse(n, int(angle * ServoFactor) + SERVOMIN);

}

void move::SetServoAngle_0(uint8_t n, double angle)
{
  if(angle<=110 && angle >= 80) 
  {
    SetServoPulse(n, int(angle * ServoFactor) + SERVOMIN);
  }
}

void move::SetServoAngle_2(uint8_t n, double angle)
{
  angle = 100 - angle;
  SetServoPulse(n, int(angle * ServoFactor_left) + SERVOMIN);
}

void move::SetServoAngle_left_1(uint8_t n, double angle)
{
  angle = 75 - angle;
  SetServoPulse(n, int(angle * ServoFactor_left) + SERVOMIN);
}

void move::SetServoAngle_left_2(uint8_t n, double angle)
{
  angle = angle+15;
  SetServoPulse(n, int(angle * ServoFactor_left) + SERVOMIN);
}

void move::SetServoAngle_left_0(uint8_t n, double angle)
{
  angle = 140 - angle;
  if(angle<=60 && angle >= 30) 
  {
    SetServoPulse(n, int(angle * ServoFactor_left) + SERVOMIN);
  }
}
int move::get_pluse_serial()
{
  char c;
  int pluse = 0;
   while(Serial.available()){
 
           c = char(Serial.read());
           if(c!='\n')
           {
              pluse  = pluse*10+c-'0';
           }
           delay(2);
 
      }
      if(pluse!=0)
      {
        Serial.print(pluse);
        Serial.print("\n");
      }
      return pluse;    
}


double move::sgn(double x)
{
  if(x>=0) return 1;
  return -1;
}

double move::deal_theta(double angle)
{
  if(angle > pi)
  {
    angle -= pi;
    return deal_theta(angle);
  }
  else return angle;
}

double move::deal_angle(double angle, int index)
{
  if(index == 0)
  {
    if(angle <90)
      return 90;
    else if(angle>180)
      return angle - 180;
    else return angle;
  }
  if(index == 1)
  {
    if(angle <0)
      return angle+180;
    else if(angle>180)
      return angle - 180;
    else return angle;
  }
  
  if(index == 2)
  {
    if(angle <70)
      return 70;
    else if(angle>180)
      return angle - 180;
    else return angle;
  }
}

void move::go_to_r(double x, double y, double z, int index)
{
    
    double z0 = abs(z)-L1;
    double theta1,theta2,theta3;
    double angle1, angle2, angle3;
    theta3 = -acos((z0*z0+x*x+y*y-L3*L3-L2*L2-h2*h2)/(2*L2*L3));
    theta1 = atan2((L2+L3*cos(theta3)), h2) - atan2(sqrt(x*x+y*y - L3*L3*sin(theta3)*sin(theta3)), z0);
    theta2 = atan2(x, y) - atan2(L3*sin(theta3), sqrt(x*x+y*y-L3*L3*sin(theta3)*sin(theta3)));
    
    angle1 = ((deal_theta(theta1)*180)/pi);
    angle2 = ((deal_theta(theta2)*180)/pi);
    angle3 = 180+((theta3*180)/pi);
    
    Serial.print(angle1);Serial.print("  ");
    Serial.print(angle2);Serial.print("  ");Serial.print(deal_angle(angle2,1));Serial.print("  ");
    Serial.print(angle3);Serial.print("  ");Serial.print(deal_angle(angle3, 2));Serial.print("  ");
    Serial.print("\n");
    
//    SetServoAngle_1(0+6*index, deal_angle(angle1,0));
//    SetServoAngle(1+6*index, deal_angle(angle2,1));
//    SetServoAngle_2(2+6*index, deal_angle(angle3, 2));
}

void move::go_to_l(double x, double y, double z, int index)
{
    
    double z0 = abs(z)-L1;
    double theta1,theta2,theta3;
    double angle1, angle2, angle3;
    theta3 = -acos((z0*z0+x*x+y*y-L3*L3-L2*L2-h2*h2)/(2*L2*L3));
    theta1 = atan2((L2+L3*cos(theta3)), h2) - atan2(sqrt(x*x+y*y - L3*L3*sin(theta3)*sin(theta3)), z0);
    theta2 = atan2(x, y) - atan2(L3*sin(theta3), sqrt(x*x+y*y-L3*L3*sin(theta3)*sin(theta3)));
    
    angle1 = 100 + ((deal_theta(theta1)*180)/pi);
    angle2 = 90-((deal_theta(theta2)*180)/pi)+ 8*index;
    angle3 = -((theta3*180)/pi);
    
    Serial.print(angle1);Serial.print("  ");
    Serial.print(deal_angle(angle2,1));Serial.print("  ");
    Serial.print(angle3);Serial.print("  ");
    Serial.print("\n");
    
    SetServoAngle(3+6*index, deal_angle(angle1,0));
    SetServoAngle(4+6*index, deal_angle(angle2,1));
    SetServoAngle(5+6*index, angle3);
}

void move::cycloid_r(double s, double h, int n_steps, int index)
{

  for(int i = 0; i<2*n_steps;i++)
  {
    if(i<n_steps)
    {
      position_p[index][0] = s*((i*1.0)/(1.0*n_steps)-0.5*sin((2*pi*i*1.0)/(n_steps*1.0))/pi)- ready_walk_x;
      position_p[index][1] = h*(sgn(0.5 - (i*1.0)/n_steps)*(2*((i*1.0)/n_steps - 0.25*sin((4*pi*i)/n_steps)/pi)-1)+1)-ready_walk_h;
      position_p[index][2] = -0.07;
      go_to_r(position_p[index][0], position_p[index][1],position_p[index][2], index);
    }
    else
    {
      position_p[index][1] = -ready_walk_h;
      position_p[index][2] = -0.07;
      position_p[index][0] = s*(2-(i*1.0)/(1.0*n_steps)+0.5*sin((2*pi*i)/n_steps)/pi) - ready_walk_x;
      go_to_r(position_p[index][0], position_p[index][1],position_p[index][2], index);
    }
  }

}


void move::cycloid_l(double s, double h, int n_steps, int index)
{
  for(int i = 0; i<2*n_steps;i++)
  {
    if(i<n_steps)
    {
      position_p[index][0] = s*((i*1.0)/(1.0*n_steps)-0.5*sin((2*pi*i*1.0)/(n_steps*1.0))/pi) - ready_walk_x;
      position_p[index][1] = h*(sgn(0.5 - (i*1.0)/n_steps)*(2*((i*1.0)/n_steps - 0.25*sin((4*pi*i)/n_steps)/pi)-1)+1)-ready_walk_h;
      position_p[index][2] = -0.07;
      go_to_l(position_p[index][0], position_p[index][1],position_p[index][2], index);
    }
    else
    {
      position_p[index][1] = -ready_walk_h;
      position_p[index][2] = -0.07;
      position_p[index][0] = s*(2-(i*1.0)/(1.0*n_steps)+0.5*sin((2*pi*i)/n_steps)/pi) - ready_walk_x;
      go_to_l(position_p[index][0], position_p[index][1],position_p[index][2], index);
    }
  }

}


void move::move_run(double s, double h, int t, int index)
{
  double h_leg[4] = {0.15,0.15,0.15,0.15};
  double t_index = t*1.0 - walk_offset[index]*T;
  if(t_index<0) t_index+=T;
  if(t_index<Tm)
    {
      position_p[index][0] = s*((t_index*1.0)/(1.0*Tm)-0.5*sin((2*pi*t_index*1.0)/(Tm*1.0))/pi) - 0.5*s-0.01;
      position_p[index][1] = h*(sgn(0.5 - (t_index*1.0)/Tm)*(2*((t_index*1.0)/Tm - 0.25*sin((4*pi*t_index)/Tm)/pi)-1)+1)-h_leg[index];
      position_p[index][2] = -0.06;
      if(index == 0 || index == 1)
      {
        go_to_r(position_p[index][0], position_p[index][1],position_p[index][2],index);
      }
      else{
        go_to_l(position_p[index][0], position_p[index][1],position_p[index][2],index-2);
      }
    }
    else
    {
    position_p[index][1] = -h_leg[index];
    position_p[index][2] = -0.061;
    position_p[index][0] = s*(1-((t_index-Tm)*1.0)/(1.0*Ts)+0.5*sin((2*pi*(t_index-Tm))/Ts)/pi) - 0.5*s-0.01;
    if(index == 0 || index == 1)
      {
        go_to_r(position_p[index][0], position_p[index][1],position_p[index][2],index);
      }
      else{
        go_to_l(position_p[index][0], position_p[index][1],position_p[index][2],index-2);
      }
    }
}

void move::walk(double s, double h,int m)
{
  Tm = m;
  Ts = 3*Tm;
  T =Tm+Ts;
  t++;
  if(t>=T) t = 0;
  for(int i = 0;i<4;i++)
  {
    move_run(s,h,t, i);
  }
}


void move::movement_decomposition(move move_cat, double *target, int n_steps_to_achieve_target) {

  double step_difference[12];

  for (int i = 0; i < 12; ++i) {
    step_difference[i] = (target[i] - motors_pos[i]) / n_steps_to_achieve_target;
  }

  for (int i = 0; i < n_steps_to_achieve_target; ++i) {
    for (int j = 0; j < 12; ++j) {
      motors_pos[j] += step_difference[j];
    }

    for (int j = 0; j < 12; ++j) {
      move_cat.SetServoAngle(j, motors_pos[j]);
    }
  }
}


void move::lie_down(move move_cat, double duration) {
  double motors_target_pos[12] = {90, 60, 80,   // Front left leg
                                        90, 60, 80,    // Front right leg
                                        90, 60, 80,    // Rear left leg
                                        90, 60, 80};  // Rear right leg
  movement_decomposition(move_cat,motors_target_pos, duration);
}


void move::stand_up(move move_cat, double duration) {
  double motors_target_pos[12] = {110, 0, 0,   // Front left leg
                                                      110, 0, 0,    // Front right leg
                                                      110, 0, 0,    // Rear left leg
                                                         110, 0, 0};  // Rear right leg

  movement_decomposition(move_cat,motors_target_pos, duration);
}
