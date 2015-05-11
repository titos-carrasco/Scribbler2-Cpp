#include "HS2MotorStats.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HS2MotorStats::HS2MotorStats( uint32_t stat_, uint8_t moveReady_ ):
                              stat(stat_), moveReady(moveReady_)
{
}

HS2MotorStats::~HS2MotorStats()
{
}

std::ostream& operator<<( std::ostream& os, const HS2MotorStats& obj )
{
    os << "MotorStats(" << obj.stat << ", " << (unsigned int)obj.moveReady << ")";
    return os;
}

}}}
