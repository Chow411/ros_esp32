#ifndef LIB_ENCODER_ENCODER_HPP
#define LIB_ENCODER_ENCODER_HPP
#include <Arduino.h>

class Encoder{
    public:
        Encoder();
        ~Encoder();
        void get_current_vel(double *linear,double *angular);
        void init_pins();

    private:
        int left_for_count = 0;
        int left_bac_count = 0;
        int right_for_count = 0;
        int right_bac_count = 0;
        double left_current_vel;
        double right_current_vel;
        double left_vel;
        double right_vel;
        long start_time = millis();
        // init wheel base wheel radius interval time pluse(pre round)
        const int pluse = 13;
        const int reducation = 30;
        const long interval_time = 50;
        const double wheel_base = 0.08;
        const double wheel_radius = 0.05;

        // encoder pins
        const int left_for_A = 35;
        const int left_for_B = 34;
        const int letf_bac_A = 33;
        const int left_bac_B = 32;
        const int right_for_A = 19;
        const int right_for_B = 18;
        const int right_bac_A = 14;
        const int right_bac_B = 27;
};

#endif // LIB_ENCODER_ENCODER_HPP