#include "HS2Lights.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2Lights::HS2Lights( uint16_t lightLeft_, uint16_t lightCenter_, uint16_t lightRight_ ):
                      lightLeft(lightLeft_), lightCenter(lightCenter_), lightRight(lightRight_)
{
}

HS2Lights::~HS2Lights()
{
}

std::ostream& operator<<( std::ostream& os, const HS2Lights& obj )
{
    os << "Light(" << obj.lightLeft << ", " << obj.lightCenter << ", " << obj.lightRight << ")";
    return os;
}

}}}
