#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "S2LineSensors.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2LineSensors::S2LineSensors( Scribbler2& s2_ ): s2(s2_)
{
}

S2LineSensors::~S2LineSensors()
{
}

uint8_t S2LineSensors::getLeftLine()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 74 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

uint8_t S2LineSensors::getRightLine()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 75 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

HS2LineSensors S2LineSensors::getAllLines()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 76 };
    s2.sendS2Command( packet, 0 );
    return HS2LineSensors( s2.getUInt8Response(), s2.getUInt8Response() );
}

uint8_t S2LineSensors::getLineEx( int side, int thres )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 173 };
    packet[1] = (uint8_t)(side & 0x01);
    packet[2] = 0;
    packet[3] = (uint8_t)(thres & 0xFF);
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

}}}

