#include "HS2State.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2State::HS2State( uint8_t inPins_, uint8_t outPins_ ):
                    inPins(inPins_), outPins(outPins_)
{
}

HS2State::~HS2State()
{
}

std::ostream& operator<<( std::ostream& os, const HS2State& obj )
{
    os << "State(" << (unsigned int)obj.inPins << ", " << (unsigned int)obj.outPins << ")";
    return os;
}

}}}
