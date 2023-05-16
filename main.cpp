#include "mbed.h"
#include "RotaryEncoder.hpp"
#include "PIDmotor.hpp"

#include <ros.h>
#include <std_msgs/Float32MultiArray.h>

PIDmotor pidMotor(D5, D4);
RotaryEncoder enc(D7, D8);
DigitalOut led(LED1);

float setpoint = 0.0;

ros::NodeHandle nh;
std_msgs::Float32MultiArray motor_vels;

void set_setpoint_motor(const std_msgs::Float32MultiArray &motor_vel){
    setpoint = motor_vel.data[0];
    led = !led;
}

int main() {

    ros::Subscriber<std_msgs::Float32MultiArray> motor_sub("set_setpoint_motor", &set_setpoint_motor);
    ros::Publisher motor_vel_pub("motor_vel", &motor_vels);

    nh.initNode();
    nh.subscribe(motor_sub);
    nh.advertise(motor_vel_pub);

    pidMotor.set_pid_gain(20.0, 0.001, 0.005, 0.0);

    enc.encoder_resolution = 0.000625;
    enc.init();
    pidMotor.init();

    enc.start();
    pidMotor.start();

    motor_vels.data_length = 2;
    motor_vels.data[0] = 0.0;
    motor_vels.data[1] = 0.0;

    while(1) {
        pidMotor.update_current_speed(enc.rpm);
        pidMotor.set_target_speed(setpoint);
        
        motor_vels.data[0] = enc.rpm;

        motor_vel_pub.publish( &motor_vels );

        nh.spinOnce();
        wait_ms(10);
    }
    
}