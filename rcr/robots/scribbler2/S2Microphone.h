#ifndef S2MICROPHONE_H
#define S2MICROPHONE_H

#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2Microphone
{
private:
    Scribbler2 &s2;

public:
    S2Microphone( Scribbler2& s2_ );
    ~S2Microphone();
    uint32_t getMicEnv();
};

}}}

#endif // S2MICROPHONE_H
