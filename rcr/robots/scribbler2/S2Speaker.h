#ifndef S2SPEAKER_H
#define S2SPEAKER_H

#include "HS2Sensors.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2Speaker
{
private:
    Scribbler2 &s2;

public:
    S2Speaker( Scribbler2& s2_ );
    ~S2Speaker();
    HS2Sensors setQuiet();
    HS2Sensors setLoud();
    HS2Sensors setVolume( int volume );
    HS2Sensors setSpeaker( int duration, int freq1, int freq2 );
};

}}}

#endif // S2SPEAKER_H
