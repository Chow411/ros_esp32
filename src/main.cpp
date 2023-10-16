#include <memory>

#include <Arduino.h>

#include <geometry_msgs/Twist.h>
#include <ros.h>
#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>

#include <Control.hpp>
#include <Encoder.hpp>

void vel_callback(const geometry_msgs::Twist &msg);

ros::NodeHandle nh;
float x;
float z;

// init pub & sub velocity of car
ros::Subscriber<geometry_msgs::Twist> vel_sub("cmd_vel",&vel_callback);
geometry_msgs::Vector3 car_vel;
ros::Publisher vel_pub("car_vel",&car_vel);

// velocity callback func recv velocity msg from ros and give controller to control wheels move
void vel_callback(const geometry_msgs::Twist &msg){
  x = msg.linear.x;
  z = msg.angular.z;
  nh.loginfo("--------recv--------");
}

// read encoders data and convert to pose msg which is ros standard msg of geometry
void changeVel(){
  car_vel.x = 0.0;
  car_vel.z = 1.0;
}

void setup()
{
  Serial.begin(57600);
  nh.initNode();
  nh.advertise(vel_pub);
  nh.subscribe(vel_sub);
}

void loop()
{
  delay(100);
  changeVel();
  vel_pub.publish(&car_vel);
  nh.spinOnce();
}