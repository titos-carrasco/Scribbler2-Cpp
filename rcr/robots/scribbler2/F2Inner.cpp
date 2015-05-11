#include <stdint.h>
#include "rcr/utils/Utils.h"
#include "rcr/utils/Lock.h"
#include "F2Inner.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

F2Inner::F2Inner( Scribbler2& s2_ ): s2(s2_)
{
}

F2Inner::~F2Inner()
{
}

std::string F2Inner::getVersion()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = (uint8_t)142;
    s2.sendF2Command( packet, 1, 100 );
    return s2.getLineResponse( 128 );
}

std::string F2Inner::identifyRobot()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = (uint8_t)156;
    s2.sendF2Command( packet, 1, 100 );
    std::string id = s2.getLineResponse( 128 );
    rcr::utils::Utils::pause( 4000 );
    return id;
}

double F2Inner::getBattery()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = 89;
    s2.sendF2Command( packet, 1, 100 );
    return s2.getUInt16Response() / 20.9813;
}

void F2Inner::setForwardness( F2Inner::Forwardness forwardness )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t f;
    if( forwardness == FLUKE_FORWARD) {
        f = 0;
    }
    else { // if( forwardness == SCRIBBLER_FORWARD )
        f = 1;
    }
    uint8_t packet[2];
    packet[0] = (uint8_t)128;
    packet[1] = f;
    s2.sendF2Command( packet, 2, 100 );
}

std::string F2Inner::getErrors()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = 10;
    s2.sendF2Command( packet, 1, 100 );
    uint16_t n = s2.getUInt16Response();
    uint8_t* b = new uint8_t[ n ];
    s2.getBytesResponse( b, n );
    std::string errors( (char *)b, n );
    delete[] b;
    return std::string( errors );
}

void F2Inner::resetScribbler()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = 124;
    s2.sendF2Command( packet, 1, 100 );
    rcr::utils::Utils::pause( 4000 );
}

}}}
