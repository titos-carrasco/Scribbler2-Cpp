#include <iostream>
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2LightSensors s2LightSensors = robot.getS2LightSensors();

    for(int i=1; i <= 10; i++ ) {
        std::cout << "getLeftLight: " << s2LightSensors.getLeftLight() << std::endl;
        std::cout << "getCenterLight: " << s2LightSensors.getCenterLight() << std::endl;
        std::cout << "getRightLed: " << s2LightSensors.getRightLed() << std::endl;
        std::cout << "getAllLights: " << s2LightSensors.getAllLights() << std::endl;
    }

    robot.close();
}
