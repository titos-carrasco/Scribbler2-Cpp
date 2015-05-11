#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    F2LEDs f2LEDs = robot.getF2LEDs();

    std::cout << "setBrightLed: " << std::endl;
    f2LEDs.setBrightLed( 255 );
    Utils::pause( 2000 );
    std::cout << "setBrightLed: " << std::endl;
    f2LEDs.setBrightLed( 128 );
    Utils::pause( 2000 );
    std::cout << "setBrightLed: " << std::endl;
    f2LEDs.setBrightLed( 0 );

    robot.close();
}
