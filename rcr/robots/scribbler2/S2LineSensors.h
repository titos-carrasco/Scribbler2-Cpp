#ifndef S2LINESENSORS_H
#define S2LINESENSORS_H

#include "HS2LineSensors.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class S2LineSensors
{
private:
    Scribbler2 &s2;

public:
    S2LineSensors( Scribbler2& s2_ );
    ~S2LineSensors();
    uint8_t getLeftLine();
    uint8_t getRightLine();
    HS2LineSensors getAllLines();
    uint8_t getLineEx( int side, int thres );
};

}}}

#endif // S2LINESENSORS_H
