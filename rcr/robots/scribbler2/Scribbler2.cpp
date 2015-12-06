#include <stdexcept>
#include <cstring>
#include <time.h>
#include "rcr/utils/Utils.h"
#include "rcr/utils/Exceptions.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

Scribbler2::Scribbler2( const std::string& port, int timeout ):
    serial( port, 9600, timeout ),
    s2Inner( *this ),
    s2IRSensors( *this ),
    s2LEDs( *this ),
    s2LightSensors( *this ),
    s2LineSensors( *this ),
    s2Microphone( *this ),
    s2Motors( *this ),
    s2Speaker( *this ),
    s2Path( *this ),
    f2Camera( * this ),
    f2Inner( *this ),
    f2IRSensors( *this ),
    f2LEDs( *this ),
    f2Servos( *this )
{
    rcr::utils::Utils::pause( 1000 );
    serial.flushRead( 1000 );
}

Scribbler2::~Scribbler2()
{
    // seria.close();
}

void Scribbler2::close()
{
    serial.close();
}

rcr::utils::Mutex& Scribbler2::getMutex()
{
    return mutex;
}

S2Inner& Scribbler2::getS2Inner() {
    return s2Inner;
}

S2IRSensors& Scribbler2::getS2IRSensors() {
    return s2IRSensors;
}

S2LEDs& Scribbler2::getS2LEDs() {
    return s2LEDs;
}

S2LightSensors& Scribbler2::getS2LightSensors() {
    return s2LightSensors;
}

S2LineSensors& Scribbler2:: getS2LineSensors() {
    return s2LineSensors;
}

S2Microphone& Scribbler2::getS2Microphone() {
    return s2Microphone;
}

S2Motors& Scribbler2::getS2Motors() {
    return s2Motors;
}

S2Speaker& Scribbler2::getS2Speaker()
{
    return s2Speaker;
}

S2Path& Scribbler2::getS2Path() {
    return s2Path;
}

F2Camera& Scribbler2::getF2Camera() {
    return f2Camera;
}

F2Inner& Scribbler2::getF2Inner() {
    return f2Inner;
}

F2IRSensors& Scribbler2::getF2IRSensors() {
    return f2IRSensors;
}

F2LEDs& Scribbler2::getF2LEDs() {
    return f2LEDs;
}

F2Servos& Scribbler2::getF2Servos() {
    return f2Servos;
}

bool Scribbler2::sendS2Command( const uint8_t packet[PACKET_LENGTH], int pause )
{
    serial.write( packet, PACKET_LENGTH );
    if( pause > 0 ) {
        rcr::utils::Utils::pause( pause );
    }
    if( packet[0] != 0x50 ) {
        uint8_t b[PACKET_LENGTH] = { 0 };
        serial.read( b, PACKET_LENGTH );
        if( std::memcmp( packet, b, PACKET_LENGTH )!=0 ) {
            rcr::utils::Utils::debug( "Packet Mismatch:" );
            rcr::utils::Utils::debug( packet, PACKET_LENGTH );
            rcr::utils::Utils::debug( b, PACKET_LENGTH );
            return false;
        }
    }
    return true;
}

void Scribbler2::sendS2PathCommand( const uint8_t packet[PACKET_LENGTH] )
{
    serial.write( packet, PACKET_LENGTH );
    time_t t = time(NULL);
    while( difftime( time(NULL), t ) < 3.5) {
        try {
            uint8_t b[PACKET_LENGTH] = { 0 };
            serial.read( b, PACKET_LENGTH );
            if( std::memcmp( packet, b, PACKET_LENGTH )!=0 ) {
                rcr::utils::Utils::debug( "Packet Mismatch (path):" );
                rcr::utils::Utils::debug( packet, PACKET_LENGTH );
                rcr::utils::Utils::debug( b, PACKET_LENGTH );
                throw rcr::utils::PacketMismatchException( "Error en Scribbler2::sendS2PathCommand." );
            }
            return;
        } catch( const rcr::utils::SerialTimeOutException &e ) {
        }
    }

    uint8_t packet_[Scribbler2::PACKET_LENGTH] = { 65 };
    while( true ) {
        serial.write( packet_, PACKET_LENGTH );
        try {
            uint8_t b[11] = { 0 };
            serial.read( b, 11 );
            serial.read( b, PACKET_LENGTH );
            break;
        } catch( const rcr::utils::SerialTimeOutException &e ) {
        }
    }

    sendS2Command( packet_, 0 );
}

void Scribbler2::sendF2Command( const uint8_t packet[], int len, int pause )
{
    serial.write( packet, len );
    if( pause > 0 ) {
        rcr::utils::Utils::pause( pause );
    }
}

HS2Sensors Scribbler2::getS2SensorsResponse()
{
    uint8_t  p1 = getUInt8Response();
    uint8_t  p2 = getUInt8Response();
    uint16_t p3 = getUInt16Response();
    uint16_t p4 = getUInt16Response();
    uint16_t p5 = getUInt16Response();
    uint8_t  p6 = getUInt8Response();
    uint8_t  p7 = getUInt8Response();
    uint8_t  p8 = getUInt8Response();
    return HS2Sensors( p1, p2, p3, p4, p5, p6, p7, p8 );
}

std::string Scribbler2::getLineResponse( int maxChars )
{
    return serial.readLine( maxChars );
}

uint8_t Scribbler2::getUInt8Response()
{
    return serial.readUInt8();
}

uint16_t Scribbler2::getUInt16Response()
{
    return serial.readUInt16();
}

uint32_t Scribbler2::getUInt32Response()
{
    return serial.readUInt32();
}

int32_t Scribbler2::getInt32Response()
{
    return serial.readInt32();
}

void Scribbler2::getBytesResponse( uint8_t b[], int nbytes )
{
    serial.read( b, nbytes );
}

}}}
