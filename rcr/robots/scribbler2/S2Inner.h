#ifndef S2INNER_H
#define S2INNER_H

#include <string>
#include "HS2Sensors.h"
#include "HS2State.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2Inner
{
private:
    Scribbler2 &s2;

public:
    S2Inner( Scribbler2& s2_ );
    ~S2Inner();
    std::string getInfo();
    HS2Sensors getAllSensors();
    std::string getPass();
    std::string getName();
    HS2State getState();
    void getData( uint8_t data[] );
    HS2Sensors setPass( std::string pass );
    HS2Sensors setSingleData( int pos, int data );
    HS2Sensors setData( const uint8_t data[] );
    HS2Sensors setName( std::string name );
};

}}}

#endif // S2INNER_H
