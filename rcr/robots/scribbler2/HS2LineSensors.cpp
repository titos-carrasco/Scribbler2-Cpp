#include "HS2LineSensors.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2LineSensors::HS2LineSensors( uint8_t lineLeft_, uint8_t lineRight_ ):
                                lineLeft(lineLeft_), lineRight(lineRight_)
{
}

HS2LineSensors::~HS2LineSensors()
{
}

std::ostream& operator<<( std::ostream& os, const HS2LineSensors& obj )
{
    os << "Line(" << (unsigned int)obj.lineLeft << ", " << (unsigned int)obj.lineRight << ")";
    return os;
}

}}}
