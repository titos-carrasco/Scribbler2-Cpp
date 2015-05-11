#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "S2Inner.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2Inner::S2Inner( Scribbler2& s2_ ): s2(s2_)
{
}

S2Inner::~S2Inner()
{
}

std::string S2Inner::getInfo()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 80 };
    s2.sendS2Command( packet, 0 );
    return s2.getLineResponse( 128 );
}

HS2Sensors S2Inner::getAllSensors()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 65 };
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

std::string S2Inner::getPass()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t data[Scribbler2::DATA_LENGTH];
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 50 };
    s2.sendS2Command( packet, 0 );
    s2.getBytesResponse( data, Scribbler2::DATA_LENGTH );
    std::string pass1( (char *)data, Scribbler2::DATA_LENGTH );
    packet[0] = (uint8_t)51;
    s2.sendS2Command( packet, 0 );
    s2.getBytesResponse( data, Scribbler2::DATA_LENGTH );
    std::string pass2( (char *)data, Scribbler2::DATA_LENGTH  );
    return std::string( pass1 + pass2 );
}

std::string S2Inner::getName()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t data[Scribbler2::DATA_LENGTH];
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 78 };
    s2.sendS2Command( packet, 0 );
    s2.getBytesResponse( data, Scribbler2::DATA_LENGTH );
    std::string name1( (char *)data, Scribbler2::DATA_LENGTH );
    packet[0] = (uint8_t)64;
    s2.sendS2Command( packet, 0 );
    s2.getBytesResponse( data, Scribbler2::DATA_LENGTH );
    std::string name2( (char *)data, Scribbler2::DATA_LENGTH );
    return std::string( name1 + name2 );
}

HS2State S2Inner::getState()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 77 };
    s2.sendS2Command( packet, 0 );
    return HS2State( s2.getUInt8Response(), s2.getUInt8Response() );
}

void S2Inner::getData( uint8_t data[Scribbler2::DATA_LENGTH ] )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 81 };
    s2.sendS2Command( packet, 0 );
    s2.getBytesResponse( data, Scribbler2::DATA_LENGTH );
}

HS2Sensors S2Inner::setPass(std::string pass)
{
    rcr::utils::Lock lock( s2.getMutex() );
    int i, j, passLen = pass.length();
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 55 };
    for(i=0; i<passLen && i<Scribbler2::DATA_LENGTH; i++) {
        packet[i+1] = pass[i];
    }
    for(; i<Scribbler2::DATA_LENGTH; i++) {
        packet[i+1] = 32;
    }
    s2.sendS2Command( packet, 0 );
    s2.getS2SensorsResponse();

    packet[0] = (uint8_t)56;
    for(j=0; i<passLen && j<Scribbler2::DATA_LENGTH; i++, j++) {
        packet[j+1] = pass[i];
    }
    for(; j<Scribbler2::DATA_LENGTH; j++) {
        packet[j+1] = 32;
    }
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Inner::setSingleData( int pos, int data )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 96 };
    packet[1] = (uint8_t)(pos & 0x07);
    packet[2] = (uint8_t)(data & 0xFF);
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Inner::setData( const uint8_t data[Scribbler2::DATA_LENGTH] )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 97 };
    for( int i=0; i<Scribbler2::DATA_LENGTH; i++ ) {
        packet[i+1] = data[i];
    }
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

HS2Sensors S2Inner::setName( std::string name )
{
    rcr::utils::Lock lock( s2.getMutex() );
    int i, j, nameLen = name.length();
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 110 };
    for(i=0; i<nameLen && i<Scribbler2::DATA_LENGTH; i++) {
        packet[i+1] = name[i];
    }
    for(; i<Scribbler2::DATA_LENGTH; i++) {
        packet[i+1] = 32;
    }
    s2.sendS2Command( packet, 0 );
    s2.getS2SensorsResponse();

    packet[0] = (uint8_t)119;
    for(j=0; i<nameLen && j<Scribbler2::DATA_LENGTH; i++, j++) {
        packet[j+1] = name[i];
    }
    for(; j<Scribbler2::DATA_LENGTH; j++) {
        packet[j+1] = 32;
    }
    s2.sendS2Command( packet, 0 );
    return s2.getS2SensorsResponse();
}

}}}
