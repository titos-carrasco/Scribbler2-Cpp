#include "HS2Infrared.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2Infrared::HS2Infrared( uint8_t irLeft_, uint8_t irRight_ ):
                          irLeft(irLeft_), irRight(irRight_)
{
}

HS2Infrared::~HS2Infrared()
{
}

std::ostream& operator<<( std::ostream& os, const HS2Infrared& obj )
{
    os << "IR(" << (unsigned int)obj.irLeft << ", " << (unsigned int)obj.irRight << ")";
    return os;
}

}}}
