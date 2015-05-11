#ifndef S2MOTORS_H
#define S2MOTORS_H

#include <stdint.h>
#include "HS2MotorStats.h"
#include "HS2Encoders.h"
#include "HS2Sensors.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2Motors
{
private:
    Scribbler2 &s2;

public:
    S2Motors( Scribbler2& s2_ );
    ~S2Motors();
    HS2MotorStats getMotorStats();
    HS2Encoders getEncoders( int preserve );
    uint8_t getStall();
    HS2Sensors setMotorsOff();
    HS2Sensors setMotors(int left, int right);
};

}}}

#endif // S2MOTORS_H
