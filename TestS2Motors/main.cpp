#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2Motors s2Motors = robot.getS2Motors();

    std::cout << "getMotorStats: " << s2Motors.getMotorStats() << std::endl;
    std::cout << "getEncoders: " << s2Motors.getEncoders( 1 ) << std::endl;
    std::cout << "getStall: " << (unsigned int)s2Motors.getStall()  << std::endl;
    std::cout << "setMotors 100, -100 : " << s2Motors.setMotors( 100, -100) << std::endl;
    Utils::pause( 3000 );
    std::cout << "setMotors -100, 100 : " << s2Motors.setMotors( -100, 100) << std::endl;
    Utils::pause( 3000 );
    std::cout << "setMotorsOff: " << s2Motors.setMotorsOff() << std::endl;

    robot.close();
}
