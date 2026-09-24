#ifndef FAN_CONTROL_H
#define FAN_CONTROL_H

#include <Arduino.h>

class FanControl {
public:
    static constexpr uint8_t DEFAULT_PWM_PIN = 6;   // Arduino D6 / FAN2_PWM
    static constexpr uint8_t DEFAULT_OE_PIN  = 4;   // Arduino D4 / OE

    static void begin(
        uint8_t pwm_pin = DEFAULT_PWM_PIN,
        uint8_t default_duty = 255,
        bool pwm_active_high = true,
        uint8_t oe_pin = DEFAULT_OE_PIN,
        bool oe_active_high = true
    );

    static void on(uint8_t duty = 255);
    static void off();
    static void set(bool enabled, uint8_t duty = 255);
    static void setDuty(uint8_t duty);

    static bool isOn();
    static uint8_t duty();
    static uint8_t pin();
    static uint8_t oePin();

private:
    static void enableOutput();
    static void writeDuty(uint8_t duty);

    static uint8_t _pin;
    static uint8_t _oe_pin;
    static uint8_t _duty;

    static bool _active_high;
    static bool _oe_active_high;
    static bool _is_on;
    static bool _begun;
};

#endif