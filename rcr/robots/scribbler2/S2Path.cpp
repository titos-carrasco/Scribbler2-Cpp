#include "rcr/utils/Lock.h"
#include "S2Path.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2Path::S2Path( Scribbler2& s2_ ): s2(s2_)
{
}

S2Path::~S2Path()
{
}

HS2Sensors S2Path::beginPath( int speed )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 161 };
    packet[1] = 1;
    packet[2] = 0;
    packet[3] = (uint8_t)(speed & 0x0F);
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::endPath()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 161 };
    packet[1] = 0;
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

HS2Coordinates S2Path::getPosn()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 165 };
    s2.sendS2Command( packet, 0 );
    return HS2Coordinates( s2.getInt32Response(), s2.getInt32Response() );
}

int32_t S2Path::getAngle()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 167 };
    s2.sendS2Command( packet, 0 );
    return s2.getInt32Response();
}

HS2Sensors S2Path::setPosn( int x, int y )
 {
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 166 };
    packet[1] = (uint8_t)((x >> 24) & 0xFF);
    packet[2] = (uint8_t)((x >> 16) & 0xFF);
    packet[3] = (uint8_t)((x >> 8) & 0xFF);
    packet[4] = (uint8_t)(x & 0xFF);
    packet[5] = (uint8_t)((y >> 24) & 0xFF);
    packet[6] = (uint8_t)((y >> 16) & 0xFF);
    packet[7] = (uint8_t)((y >> 8) & 0xFF);
    packet[8] = (uint8_t)(y & 0xFF);
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::setAngle( int angle )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 168 };
    packet[1] = (uint8_t)((angle >> 24) & 0xFF);
    packet[2] = (uint8_t)((angle >> 16) & 0xFF);
    packet[3] = (uint8_t)((angle >> 8) & 0xFF);
    packet[4] = (uint8_t)(angle & 0xFF);
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::moveTo( int x, int y )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 162 };
    packet[1] = 2 + 1;
    packet[2] = (uint8_t)((x >> 8) & 0xFF);
    packet[3] = (uint8_t)(x & 0xFF);
    packet[4] = (uint8_t)((y >> 8) & 0xFF);
    packet[5] = (uint8_t)(y & 0xFF);
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::moveBy( int x, int y )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 162 };
    packet[1] = 4 + 1;
    packet[2] = (uint8_t)((x >> 8) & 0xFF);
    packet[3] = (uint8_t)(x & 0xFF);
    packet[4] = (uint8_t)((y >> 8) & 0xFF);
    packet[5] = (uint8_t)(y & 0xFF);
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::turnTo( int angle )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 164 };
    packet[1] = 2 + 1;
    packet[2] = (uint8_t)((angle >> 8) & 0xFF);
    packet[3] = (uint8_t)(angle & 0xFF);
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::turnBy( int angle )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 164 };
    packet[1] = 4 + 1;
    packet[2] = (uint8_t)((angle >> 8) & 0xFF);
    packet[3] = (uint8_t)(angle & 0xFF);
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::arcTo( int x, int y, int radius)
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 163 };
    packet[1] = 2 + 1;
    packet[2] = (uint8_t)((x >> 8) & 0xFF);
    packet[3] = (uint8_t)(x & 0xFF);
    packet[4] = (uint8_t)((y >> 8) & 0xFF);
    packet[5] = (uint8_t)(y & 0xFF);
    packet[6] = (uint8_t)((radius >> 8) & 0xFF);
    packet[7] = (uint8_t)(radius & 0xFF);
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Path::arcBy( int x, int y, int radius)
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 163 };
    packet[1] = 4 + 1;
    packet[2] = (uint8_t)((x >> 8) & 0xFF);
    packet[3] = (uint8_t)(x & 0xFF);
    packet[4] = (uint8_t)((y >> 8) & 0xFF);
    packet[5] = (uint8_t)(y & 0xFF);
    packet[6] = (uint8_t)((radius >> 8) & 0xFF);
    packet[7] = (uint8_t)(radius & 0xFF);
    s2.sendS2PathCommand( packet );
    return s2.getS2SensorsResponse();
}

}}}
