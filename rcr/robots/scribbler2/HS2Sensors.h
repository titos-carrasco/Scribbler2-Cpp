#ifndef HS2SENSORS_H
#define HS2SENSORS_H

#include <stdint.h>
#include <iostream>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2Sensors
{
public:
    const uint8_t irLeft;
    const uint8_t irRight;
    const uint16_t lightLeft;
    const uint16_t lightCenter;
    const uint16_t lightRight;
    const uint8_t lineLeft;
    const uint8_t lineRight;
    const uint8_t stall;

public:
    HS2Sensors( uint8_t irLeft_, uint8_t irRight_,
                uint16_t lightLeft_, uint16_t lightCenter_, uint16_t lightRight_,
                uint8_t lineLeft_, uint8_t lineRight_,
                uint8_t stall);
    ~HS2Sensors();
    friend std::ostream& operator<<( std::ostream& os, const HS2Sensors& obj );
};

}}}

#endif // HS2SENSORS_H
