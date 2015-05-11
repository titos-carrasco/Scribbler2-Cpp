#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "S2Speaker.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2Speaker::S2Speaker( Scribbler2& s2_ ): s2(s2_)
{
}

S2Speaker::~S2Speaker()
{
}

HS2Sensors S2Speaker::setQuiet()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 112 };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Speaker::setLoud()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 111 };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Speaker::setVolume(int volume)
{
    rcr::utils::Lock lock( s2.getMutex() );
    volume = volume & 0xFF;
    if( volume > 100 ) {
        volume= 100;
    }
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 160 };
    packet[1] = (uint8_t)volume;
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Speaker::setSpeaker(int duration, int freq1, int freq2)
{
    rcr::utils::Lock lock( s2.getMutex() );
    duration = duration & 0xFFFF;
    if( duration > 2500 ) {
        duration = 2500;
    }
    freq1 = freq1 & 0xFFFF;
    freq2 = freq2 & 0xFFFF;
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 114 };
    packet[1] = (uint8_t)((duration >>8) & 0xFF);
    packet[2] = (uint8_t)(duration & 0xFF);
    packet[3] = (uint8_t)((freq1 >> 8) & 0xFF);
    packet[4] = (uint8_t)(freq1 & 0xFF);
    packet[5] = (uint8_t)((freq2 >> 8) & 0xFF);
    packet[6] = (uint8_t)(freq2 & 0xFF);
    s2.sendS2Command( packet, duration );
    return s2.getS2SensorsResponse();
}

}}}
