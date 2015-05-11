#ifndef HS2INFRARED_H
#define HS2INFRARED_H

#include <stdint.h>
#include <iostream>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2Infrared
{
public:
    const uint8_t irLeft;
    const uint8_t irRight;

    HS2Infrared( uint8_t irLeft_, uint8_t irRight_);
    ~HS2Infrared();
    friend std::ostream& operator<<( std::ostream& os, const HS2Infrared& obj );
};

}}}

#endif // HS2INFRARED_H
