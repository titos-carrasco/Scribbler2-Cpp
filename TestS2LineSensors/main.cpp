#include <iostream>
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2LineSensors s2LineSensors = robot.getS2LineSensors();

    for(int i=1; i <= 10; i++ ) {
        std::cout << "getLineEx 0, 128: " << s2LineSensors.getLineEx( 0, 128 ) << std::endl;
        std::cout << "getLineEx 1, 128: " << s2LineSensors.getLineEx( 1, 128 ) << std::endl;
        std::cout << "getAllLines: " << s2LineSensors.getAllLines() << std::endl;
        std::cout << "getLeftLine: " << s2LineSensors.getLeftLine() << std::endl;
        std::cout << "getRightLine: " << s2LineSensors.getRightLine() << std::endl;
    }

    robot.close();
}
