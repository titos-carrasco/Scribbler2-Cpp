#ifndef S2IRSENSORS_H
#define S2IRSENSORS_H

#include <stdint.h>
#include "HS2Infrared.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2IRSensors
{
private:
    Scribbler2 &s2;

public:
    S2IRSensors( Scribbler2& s2_ );
    ~S2IRSensors();
    uint8_t getIRLeft();
    uint8_t getIRRight();
    HS2Infrared getAllIR();
    uint8_t getIrEx( int side, int thres );
    uint8_t getDistanceEx( int side );
};

}}}

#endif // S2IRSENSORS_H
