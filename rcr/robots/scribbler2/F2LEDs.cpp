#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "F2LEDs.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

F2LEDs::F2LEDs( Scribbler2& s2_ ): s2(s2_)
{
}

F2LEDs::~F2LEDs()
{
}

void F2LEDs::setBrightLed( int pwm )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[2];
    packet[0] = 126;
    packet[1] = (uint8_t)(pwm & 0xFF);
    s2.sendF2Command( packet, 2, 100 );
}

}}}
