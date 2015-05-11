#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "S2LEDs.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2LEDs::S2LEDs( Scribbler2& s2_ ): s2(s2_)
{
}

S2LEDs::~S2LEDs()
{
}

HS2Sensors S2LEDs::setLeftLed( bool encender )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t cmd = 100;
    if( encender ) {
        cmd = 99;
    }
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { cmd };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2LEDs::setCenterLed( bool encender )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t cmd = 102;
    if( encender ) {
        cmd = 101;
    }
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { cmd };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2LEDs::setRightLed( bool encender )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t cmd = 104;
    if( encender ) {
        cmd = 103;
    }
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { cmd };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2LEDs::setAllLed( int left, int center, int right )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 107 };
    packet[1] = (uint8_t)(left & 0x01);
    packet[2] = (uint8_t)(center & 0x01);
    packet[3] = (uint8_t)(right & 0x01);
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

}}}
