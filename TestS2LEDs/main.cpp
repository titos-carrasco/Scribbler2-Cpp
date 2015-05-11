#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2LEDs s2LEDs = robot.getS2LEDs();

    std::cout << "setLeftLed: " << s2LEDs.setLeftLed( true ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setLeftLed: " << s2LEDs.setLeftLed( false ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setCenterLed: " << s2LEDs.setCenterLed( true ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setCenterLed: " << s2LEDs.setCenterLed( false ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setRightLed: " << s2LEDs.setRightLed( true ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setRightLed: " << s2LEDs.setRightLed( false ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setAllLed: " << s2LEDs.setAllLed( 1, 1, 1 ) << std::endl;
    Utils::pause( 2000 );
    std::cout << "setAllLed: " << s2LEDs.setAllLed( 0, 0, 0 ) << std::endl;
    Utils::pause( 2000 );

    robot.close();
}
