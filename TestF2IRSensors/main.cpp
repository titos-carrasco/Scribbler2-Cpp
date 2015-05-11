#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    F2IRSensors f2IRSensors = robot.getF2IRSensors();

    std::cout << "setIRPower: " << std::endl;
    f2IRSensors.setIRPower( 255 );

    for(int i = 0; i < 20; i++ ){
        std::cout << "getIR: " << f2IRSensors.getIR() << std::endl;
    }

    robot.close();
}
