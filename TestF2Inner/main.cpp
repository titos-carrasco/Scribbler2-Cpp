#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    F2Inner f2Inner = robot.getF2Inner();

    std::cout << "getVersion: " << f2Inner.getVersion() << std::endl;
    std::cout << "identifyRobot: " << f2Inner.identifyRobot() << std::endl;
    std::cout << "getBattery: " << f2Inner.getBattery() << std::endl;
    std::cout << "setForwardness SCRIBBLER_FORWARD " <<  std::endl;
    f2Inner.setForwardness( f2Inner.SCRIBBLER_FORWARD );
    std::cout << "setForwardness FLUKE_FORWARD " << std::endl;
    f2Inner.setForwardness( f2Inner.FLUKE_FORWARD );
    std::cout << "setForwardness SCRIBBLER_FORWARD " << std::endl;
    f2Inner.setForwardness( f2Inner.SCRIBBLER_FORWARD );
    std::cout << "getErrors: " << f2Inner.getErrors() << std::endl;

    robot.close();
}
