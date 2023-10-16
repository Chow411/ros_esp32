#include "Encoder.hpp"

Encoder::Encoder(){
    
}


void Encoder::init_pins(){
    pinMode(this->left_for_A,INPUT);
    pinMode(this->left_for_B,INPUT);
    pinMode(this->letf_bac_A,INPUT);
    pinMode(this->left_bac_B,INPUT);
    pinMode(this->right_for_A,INPUT);
    pinMode(this->right_for_B,INPUT);
    pinMode(this->right_bac_A,INPUT);
    pinMode(this->right_bac_B,INPUT);
}



void Encoder::get_current_vel(double *linear,double *angular){
    long right_now = millis();
    long past_time = right_now - start_time;
    if(past_time > interval_time){
        noInterrupts(); // stop interrupts
        double left_avg_vel = ((double)left_for_count + (double)left_bac_count) /2;
        double right_avg_vel = ((double)right_for_count + (double)right_bac_count) /2;
        int per_round = pluse * reducation * 4;
        left_current_vel =  left_avg_vel/ per_round / past_time * 1000 * 60;
        left_current_vel =  left_avg_vel/ per_round / past_time * 1000 * 60;

        left_vel = left_current_vel * 3.14 * wheel_radius * 2 /60;
        right_vel = left_current_vel * 3.14 * wheel_radius * 2 /60;
        *linear = (left_vel + right_vel) / 2;
        *angular = (right_vel - left_vel) / 2;
        // reset time and encoder count
        start_time = right_now; 
        this->left_for_count = 0;
        this->left_bac_count = 0;
        this->right_for_count = 0;
        this->right_bac_count = 0;
        interrupts(); // reset interrupts
    }
}

Encoder::~Encoder(){
    
}