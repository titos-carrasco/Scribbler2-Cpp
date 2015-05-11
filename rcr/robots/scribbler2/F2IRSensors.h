#ifndef F2IRSENSORS_H
#define F2IRSENSORS_H

#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class F2IRSensors
{
private:
    Scribbler2 &s2;

public:
    F2IRSensors(  Scribbler2& s2_ );
    ~F2IRSensors();
    void setIRPower( int pwm );
    uint16_t getIR();
};

}}}

#endif // F2IRSENSORS_H
