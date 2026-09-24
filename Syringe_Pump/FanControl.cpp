#include "FanControl.h"

uint8_t FanControl::_pin = 6;
uint8_t FanControl::_oe_pin = 4;
uint8_t FanControl::_duty = 255;

bool FanControl::_active_high = true;
bool FanControl::_oe_active_high = true;
bool FanControl::_is_on = false;
bool FanControl::_begun = false;

void FanControl::begin(
    uint8_t pwm_pin,
    uint8_t default_duty,
    bool pwm_active_high,
    uint8_t oe_pin,
    bool oe_active_high
)
{
    _pin = pwm_pin;
    _oe_pin = oe_pin;
    _duty = default_duty;
    _active_high = pwm_active_high;
    _oe_active_high = oe_active_high;

    pinMode(_oe_pin, OUTPUT);
    pinMode(_pin, OUTPUT);

    _begun = true;

    // Enable the level-shifter / intermediate controller before using PWM.
    enableOutput();

    // Fan starts from OFF state.
    off();
}

void FanControl::enableOutput()
{
    digitalWrite(_oe_pin, _oe_active_high ? HIGH : LOW);

    // Small settling time for OE signal before PWM is applied.
    delayMicroseconds(10);
}

void FanControl::writeDuty(uint8_t duty)
{
    if (!_begun) {
        begin(_pin, _duty, _active_high, _oe_pin, _oe_active_high);
    }

    // OE must be enabled before sending PWM to FAN2_PWM.
    enableOutput();

    uint8_t output_duty = _active_high ? duty : (uint8_t)(255 - duty);
    analogWrite(_pin, output_duty);
}

void FanControl::on(uint8_t duty)
{
    if (duty > 0) {
        _duty = duty;
    }

    writeDuty(_duty);
    _is_on = true;
}

void FanControl::off()
{
    // Important:
    // Do NOT disable OE here, because OE may also enable other translated signals
    // such as SPI, DRV_ENN, FAN1_PWM, FAN2_PWM, etc.
    writeDuty(0);
    _is_on = false;
}

void FanControl::set(bool enabled, uint8_t duty)
{
    if (enabled) {
        on(duty);
    }
    else {
        off();
    }
}

void FanControl::setDuty(uint8_t duty)
{
    _duty = duty;

    if (_is_on) {
        writeDuty(_duty);
    }
}

bool FanControl::isOn()
{
    return _is_on;
}

uint8_t FanControl::duty()
{
    return _duty;
}

uint8_t FanControl::pin()
{
    return _pin;
}

uint8_t FanControl::oePin()
{
    return _oe_pin;
}