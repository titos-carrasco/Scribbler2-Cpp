#ifndef HS2LIGHTS_H
#define HS2LIGHTS_H

#include <stdint.h>
#include <iostream>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2Lights
{
public:
    const uint16_t lightLeft;
    const uint16_t lightCenter;
    const uint16_t lightRight;

public:
    HS2Lights( uint16_t lightLeft_, uint16_t lightCenter_, uint16_t lightRight_ );
    ~HS2Lights();
    friend std::ostream& operator<<( std::ostream& os, const HS2Lights& obj );
};

}}}

#endif // HS2LIGHTS_H
