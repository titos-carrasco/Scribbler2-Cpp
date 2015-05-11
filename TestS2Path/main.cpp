#include <iostream>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2Path s2Path = robot.getS2Path();

    std::cout << "beginPath 16: " << s2Path.beginPath( 15 ) << std::endl;
    std::cout << "setPosn -100, -200: " << s2Path.setPosn( -100, -200 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "setPosn 0, 0: " << s2Path.setPosn( 0, 0 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "setAngle -90: " << s2Path.setAngle( -90 ) << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;
    std::cout << "setAngle 90: " << s2Path.setAngle( 90 )  << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;

    std::cout << "moveTo 0, 100: " << s2Path.moveTo( 0, 100 )  << std::endl;
    std::cout << "moveTo 0, -1000: " << s2Path.moveTo( 0, -1000) << std::endl;
    std::cout << "moveTo 0, 1000: " << s2Path.moveTo( 0, 1000 ) << std::endl;

    std::cout << "moveTo 0, 2000: " << s2Path.moveTo( 0, 2000 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;
    std::cout << "moveBy 0, 50: " << s2Path.moveBy( 0, 50 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;
    std::cout << "turnTo 45: " << s2Path.turnTo( 45 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;
    std::cout << "turnBy 45: " << s2Path.turnBy( 45 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;
    std::cout << "arcTo 100, 100, 45: " << s2Path.arcTo( 100, 100, 45 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;
    std::cout << "arcBy 100 : " << s2Path.arcBy( 100, 100, 45 ) << std::endl;
    std::cout << "getPosn: " << s2Path.getPosn() << std::endl;
    std::cout << "getAngle: " << s2Path.getAngle() << std::endl;

    std::cout << "endPath: " << s2Path.endPath() << std::endl;

    robot.close();
}
