#ifndef F2SERVOS_H
#define F2SERVOS_H

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class F2Servos
{
private:
    Scribbler2 &s2;

public:
    F2Servos( Scribbler2& s2_ );
    ~F2Servos();
    void setServo( int id, int value );
};

}}}

#endif // F2SERVOS_H
