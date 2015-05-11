#include <iostream>
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2Speaker s2Speaker = robot.getS2Speaker();

    std::cout << "setQuiet: " << s2Speaker.setQuiet() << std::endl;
    std::cout << "setLoud: " << s2Speaker.setLoud() << std::endl;
    std::cout << "setVolume: " << s2Speaker.setVolume( 50 ) << std::endl;
    std::cout << "setSpeaker: " << s2Speaker.setSpeaker( 2000, 440, 880 ) << std::endl;
    std::cout << "setSpeaker: " << s2Speaker.setSpeaker( 2000, 650, 0 ) << std::endl;

    robot.close();
}
