#include "HS2Sensors.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2Sensors::HS2Sensors( uint8_t irLeft_, uint8_t irRight_,
                        uint16_t lightLeft_, uint16_t lightCenter_, uint16_t lightRight_,
                        uint8_t lineLeft_, uint8_t lineRight_,
                        uint8_t stall_ ):
    irLeft(irLeft_), irRight(irRight_),
    lightLeft(lightLeft_), lightCenter(lightCenter_), lightRight(lightRight_),
    lineLeft(lineLeft_), lineRight(lineRight_),
    stall(stall_)
{
}

HS2Sensors::~HS2Sensors()
{
}

std::ostream& operator<<( std::ostream& os, const HS2Sensors& obj )
{
    os << "IR(" << (unsigned int)obj.irLeft << ", " << (unsigned int)obj.irRight << "), ";
    os << "Light(" << obj.lightLeft << ", " << obj.lightCenter << ", " << obj.lightRight << "), ";
    os << "Line(" << (unsigned int)obj.lineLeft << ", " << (unsigned int)obj.lineRight << "), ";
    os << "Stall(" << (unsigned int)obj.stall << ")";
    return os;
}

}}}
