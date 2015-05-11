#include "HS2Coordinates.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2Coordinates::HS2Coordinates( int32_t x_, int32_t y_ ):
                                x(x_), y(y_)
{
}

HS2Coordinates::~HS2Coordinates()
{
}


std::ostream& operator<<( std::ostream& os, const HS2Coordinates& obj )
{
    os << "Coordinates(" << obj.x << ", " << obj.x << ")";
    return os;
}

}}}
