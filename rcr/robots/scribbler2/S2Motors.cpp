#include "rcr/utils/Lock.h"
#include "S2Motors.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2Motors::S2Motors( Scribbler2& s2_ ): s2(s2_)
{
}

S2Motors::~S2Motors()
{
}

HS2MotorStats S2Motors::getMotorStats()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 170 };
    s2.sendS2Command( packet, 0 );
    uint32_t p1 = s2.getUInt32Response();
    uint8_t  p2 = s2.getUInt8Response();
    return HS2MotorStats( p1, p2 );
}

HS2Encoders S2Motors::getEncoders( int preserve )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 171 };
    packet[1] = (uint8_t)(preserve & 0x01);
    s2.sendS2Command( packet, 0 );
    uint32_t p1 = s2.getUInt32Response();
    uint32_t p2 = s2.getUInt32Response();
    return HS2Encoders( p1, p2 );
}

uint8_t S2Motors::getStall()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 79 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt8Response();
}

HS2Sensors S2Motors::setMotorsOff()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 108 };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Motors::setMotors(int left, int right)
{
    rcr::utils::Lock lock( s2.getMutex() );
    if(left>100) {
        left = 100;
    } else if(left<-100) {
        left = -100;
    }
    left = left + 100;

    if(right>100) {
        right = 100;
    } else if(right<-100) {
        right = -100;
    }
    right = right + 100;

    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 109 };
    packet[1] = (uint8_t)right;
    packet[2] = (uint8_t)left;
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

}}}
