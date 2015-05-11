#ifndef HS2COORDINATES_H
#define HS2COORDINATES_H

#include <iostream>
#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2Coordinates
{
public:
    const int32_t x;
    const int32_t y;

public:
    HS2Coordinates( int32_t x_, int32_t y_ );
    ~HS2Coordinates();
    friend std::ostream& operator<<( std::ostream& os, const HS2Coordinates& obj );
};

}}}

#endif // HS2COORDINATES_H
