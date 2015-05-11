#include "rcr/utils/Lock.h"
#include "S2Microphone.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

S2Microphone::S2Microphone( Scribbler2& s2_ ): s2(s2_)
{
}

S2Microphone::~S2Microphone()
{
}

uint32_t S2Microphone::getMicEnv()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[Scribbler2::PACKET_LENGTH] = { 169 };
    s2.sendS2Command( packet, 0 );
    return s2.getUInt32Response();
}

}}}
