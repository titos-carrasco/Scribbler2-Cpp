#ifndef F2INNER_H
#define F2INNER_H

#include <string>

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class F2Inner
{
public:
    enum Forwardness { FLUKE_FORWARD = 1, SCRIBBLER_FORWARD = 2 };

private:
    Scribbler2 &s2;

public:
    F2Inner( Scribbler2& s2_ );
    ~F2Inner();
    std::string getVersion();
    std::string identifyRobot();
    double getBattery();
    void setForwardness( F2Inner::Forwardness forwardness );
    std::string getErrors();
    void resetScribbler();
};

}}}

#endif // F2INNER_H
