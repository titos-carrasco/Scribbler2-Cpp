#ifndef S2LEDS_H
#define S2LEDS_H

#include "HS2Sensors.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2LEDs
{
private:
    Scribbler2 &s2;

public:
    S2LEDs( Scribbler2& s2_ );
    ~S2LEDs();
    HS2Sensors setLeftLed( bool encender );
    HS2Sensors setCenterLed( bool encender );
    HS2Sensors setRightLed( bool encender );
    HS2Sensors setAllLed( int left, int center, int right );
};

}}}

#endif // S2LEDS_H
