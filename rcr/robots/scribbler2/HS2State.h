#ifndef HS2STATE_H
#define HS2STATE_H

#include <iostream>
#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2State
{
public:
    const uint8_t inPins;
    const uint8_t outPins;

public:
    HS2State( uint8_t inPins_, uint8_t outPins_ );
    ~HS2State();
    friend std::ostream& operator<<( std::ostream& os, const HS2State& obj );
};

}}}

#endif // HS2STATE_H
