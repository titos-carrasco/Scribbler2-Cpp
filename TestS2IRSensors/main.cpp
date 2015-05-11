#include <iostream>
#include <stdint.h>
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2IRSensors s2IRSensors = robot.getS2IRSensors();

    std::cout << "getIRLeft: " << (unsigned int)s2IRSensors.getIRLeft() << std::endl;
    std::cout << "getIRRight: " << (unsigned int)s2IRSensors.getIRRight() << std::endl;
    std::cout << "getAllIR: " << s2IRSensors.getAllIR() << std::endl;
    std::cout << "getIrEx 0, 128: " << (unsigned int)s2IRSensors.getIrEx( 0, 128 ) << std::endl;
    std::cout << "getIrEx 1, 128: " << (unsigned int)s2IRSensors.getIrEx( 1, 128 ) << std::endl;

    robot.close();
}
