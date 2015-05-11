#ifndef HS2MOTORS_H
#define HS2MOTORS_H

#include <iostream>
#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2MotorStats
{
public:
    const uint32_t stat;
    const uint8_t moveReady;

public:
    HS2MotorStats( uint32_t stat_, uint8_t moveReady_ );
    ~HS2MotorStats();
    friend std::ostream& operator<<( std::ostream& os, const HS2MotorStats& obj );
};

}}}

#endif // HS2MOTORS_H
