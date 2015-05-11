#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "S2IRSensors.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2IRSensors::S2IRSensors( Scribbler2& s2_ ): s2(s2_)
{
}

S2IRSensors::~S2IRSensors()
{
}

uint8_t S2IRSensors::getIRLeft()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 71 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

uint8_t S2IRSensors::getIRRight()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 72 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

HS2Infrared S2IRSensors::getAllIR()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 73 };
    s2.sendS2Command( packet, 0 );
    return HS2Infrared( s2.getUInt8Response(), s2.getUInt8Response() );
}

uint8_t S2IRSensors::getIrEx( int side, int thres )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 172 };
    packet[1] = (uint8_t)(side & 0x01);
    packet[2] = 0;
    packet[3] = (uint8_t)(thres & 0xFF);
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

uint8_t S2IRSensors::getDistanceEx( int side )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 175 };
    packet[1] = (uint8_t)(side & 0x01);
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

}}}
