#include "rcr/utils/Lock.h"
#include "F2IRSensors.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

    F2IRSensors::F2IRSensors( Scribbler2& s2_ ): s2(s2_)
{
}

F2IRSensors::~F2IRSensors()
{
}

void F2IRSensors::setIRPower( int pwm )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[2];
    packet[0] = 120;
    packet[1] = (uint8_t)(pwm & 0xFF);
    s2.sendF2Command( packet, 2, 100 );
}

uint16_t F2IRSensors::getIR()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = 86;
    s2.sendF2Command( packet, 1, 100 );
    return s2.getUInt16Response();
}

}}}
