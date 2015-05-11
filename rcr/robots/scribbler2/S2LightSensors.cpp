#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "S2LightSensors.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2LightSensors::S2LightSensors( Scribbler2& s2_ ): s2(s2_)
{
}

S2LightSensors::~S2LightSensors()
{
}

uint16_t S2LightSensors::getLeftLight()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 67 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt16Response();
}

uint16_t S2LightSensors::getCenterLight()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 68 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt16Response();
}

uint16_t S2LightSensors::getRightLed()
 {
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 69 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt16Response();
}

HS2Lights S2LightSensors::getAllLights()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 70 };
    s2.sendS2Command( packet, 0 );
    return HS2Lights( s2.getUInt16Response(), s2.getUInt16Response(), s2.getUInt16Response() );
}

}}}
