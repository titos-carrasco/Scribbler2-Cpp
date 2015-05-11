#ifndef HS2ENCODERS_H
#define HS2ENCODERS_H

#include <iostream>
#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HS2Encoders
{
public:
    const uint32_t left;
    const uint32_t right;

public:
    HS2Encoders( uint32_t left_, uint32_t right_ );
    ~HS2Encoders();
    friend std::ostream& operator<<( std::ostream& os, const HS2Encoders& obj );
};

}}}

#endif // HS2ENCODERS_H
