#include "HS2Encoders.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2Encoders::HS2Encoders( uint32_t left_, uint32_t right_ ):
                          left(left_), right(right_)
{
}

HS2Encoders::~HS2Encoders()
{
}

std::ostream& operator<<( std::ostream& os, const HS2Encoders& obj )
{
    os << "Encoders(" << obj.left << ", " << obj.right << ")";
    return os;
}

}}}
