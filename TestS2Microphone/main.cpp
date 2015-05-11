#include <iostream>
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main(int argc, char **argv)
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2Microphone s2Microphone = robot.getS2Microphone();

    for(int i=1; i <= 50; i++ ) {
        std::cout << "getMicEnv: " << s2Microphone.getMicEnv() << std::endl;
    }

    robot.close();
}
