#ifndef S2PATH_H
#define S2PATH_H

#include <stdint.h>
#include "HS2Sensors.h"
#include "HS2Coordinates.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2Path
{
private:
    Scribbler2 &s2;

public:
    S2Path( Scribbler2& s2_ );
    ~S2Path();
    HS2Sensors beginPath( int speed );
    HS2Sensors endPath();
    HS2Coordinates getPosn();
    int32_t getAngle();
    HS2Sensors setPosn( int x, int y );
    HS2Sensors setAngle( int angle );
    HS2Sensors moveTo( int x, int y );
    HS2Sensors moveBy( int x, int y );
    HS2Sensors turnTo( int angle );
    HS2Sensors turnBy( int angle );
    HS2Sensors arcTo( int x, int y, int radius);
    HS2Sensors arcBy( int x, int y, int radius);
};

}}}

#endif // S2PATH_H
