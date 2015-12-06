#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "F2Servos.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

F2Servos::F2Servos( Scribbler2& s2_ ): s2(s2_)
{
}

F2Servos::~F2Servos()
{
}

void F2Servos::setServo( int id, int value )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[3];
    packet[0] = 12;
    packet[1] = (uint8_t)(id & 0x03);
    packet[2] = (uint8_t)(value & 0xFF);
    s2.sendF2Command( packet, 3, 100 );
}

}}}
