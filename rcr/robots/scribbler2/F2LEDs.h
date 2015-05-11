#ifndef F2LEDS_H
#define F2LEDS_H

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class F2LEDs
{
private:
    Scribbler2 &s2;

public:
    F2LEDs( Scribbler2& s2_ );
    ~F2LEDs();
    void setBrightLed( int pwm );
};

}}}

#endif // F2LEDS_H
