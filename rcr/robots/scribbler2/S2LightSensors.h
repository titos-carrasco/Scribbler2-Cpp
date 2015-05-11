#ifndef S2LIGHTSENSORS_H
#define S2LIGHTSENSORS_H

#include "HS2Lights.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2LightSensors
{
private:
    Scribbler2 &s2;

public:
    S2LightSensors( Scribbler2& s2_ );
    ~S2LightSensors();
    uint16_t getLeftLight();
    uint16_t getCenterLight();
    uint16_t getRightLed();
    HS2Lights getAllLights();
};

}}}

#endif // S2LIGHTSENSORS_H
