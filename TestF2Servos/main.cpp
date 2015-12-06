#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    F2Servos f2Servos = robot.getF2Servos();

    int id = 0;
    for(int value=0; value<=255; value+=5) {
        std::cout << "setServo(" << id << "," << value << ")" << std::endl;
        f2Servos.setServo(id, value);
        Utils::pause(60);
    }
    robot.close();
}
