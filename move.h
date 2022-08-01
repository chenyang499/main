#ifndef MOVE_H
#define MOVE_H

#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>



#define SERVOMIN 900      // This is the 'minimum' pulse length count
#define SERVOMAX 2100     // This is the 'maximum' pulse length count
#define SERVO_FREQ 50     // Analog servos run at ~50 Hz updates

#define DIVIDE_COEF 10 // divide coefficient

#define Servo 120
#define ServoFactor 8.7
#define ServoFactor_left 8.7

#define L1 0.0343
#define L2 0.065
#define L3 0.078
#define h2 0.017
#define pi 3.1415926
#define ready_walk_h 0.14;
#define ready_walk_x 0.06;


class move{
  public: 
    double walk_offset[4] = {0,0.75,0.5,0.25};
    int t = 0;//当前时刻的时间
    int Tm;//摆动相的周期
    int Ts;//支撑相周期
    int T;//总周期
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
    
    double position_p[4][3] = {{0,-0.175,-0.061}, 
                          {0,-0.175,-0.061},
                          {0,-0.175,-0.061},
                            {0,-0.175,-0.061}};
                             
    double position_base[4][3] = {{0,-0.175,-0.061}, 
                              {0,-0.175,-0.061},
                              {0,-0.175,-0.061},
                                {0,-0.175,-0.061}};

     double motors_pos[12] = {110, 0, 0,   // Front left leg
                                110, 0, 0,    // Front right leg
                                110, 0, 0,    // Rear left leg
                                110, 0, 0};  // Rear right leg
                                
     void Init();
     void SetServoPulse(uint8_t n, int pluse);
     void SetServoAngle_1(uint8_t n, double angle);
     void SetServoAngle_0(uint8_t n, double angle);
     void SetServoAngle_2(uint8_t n, double angle);
     void SetServoAngle_left_1(uint8_t n, double angle);
     void SetServoAngle_left_2(uint8_t n, double angle);
     void SetServoAngle_left_0(uint8_t n, double angle);
     void SetServoAngle(uint8_t n,double angle);
     
     int get_pluse_serial();
     double sgn(double x);
     double deal_theta(double angle);
     double deal_angle(double angle, int index);
     
     void go_to_r(double x, double y, double z, int index);
     void go_to_l(double x, double y, double z, int index);
     void cycloid_r(double s, double h, int n_steps, int index);
     void cycloid_l(double s, double h, int n_steps, int index);
     void move_run(double s, double h, int t, int index);
     void walk(double s, double h,int m); 
     
     void movement_decomposition(move move_cat, double *target, int n_steps_to_achieve_target);
     void lie_down(move move_cat, double duration);
     void stand_up(move move_cat, double duration);
                                  
    
};




#endif
