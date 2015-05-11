#ifndef HS2LINESENSORS_H
#define HS2LINESENSORS_H

#include <stdint.h>
#include <iostream>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2LineSensors
{
public:
    const uint8_t lineLeft;
    const uint8_t lineRight;

public:
    HS2LineSensors( uint8_t lineLeft_, uint8_t lineRight_ );
    ~HS2LineSensors();
    friend std::ostream& operator<<( std::ostream& os, const HS2LineSensors& obj );
};

}}}

#endif // HS2LINESENSORS_H
