#include <iostream>
#include <stdint.h>
#include "rcr/utils/Utils.h"
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;
using namespace rcr::utils;

int main()
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    S2Inner s2Inner = robot.getS2Inner();

    uint8_t data[Scribbler2::DATA_LENGTH];
    uint8_t data1[Scribbler2::DATA_LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    uint8_t data2[Scribbler2::DATA_LENGTH] = { 8, 7, 6, 5, 4, 3, 2, 1 };

    std::cout << "getInfo: " << s2Inner.getInfo() << std::endl;
    std::cout << "getAllSensors: " << s2Inner.getAllSensors() << std::endl;
    std::cout << "setPass: " << s2Inner.setPass( "1234567898765432" ) << std::endl;
    std::cout << "getPass: " << s2Inner.getPass() << std::endl;
    std::cout << "setPass: " << s2Inner.setPass( "ABCDEFGHIHGFRDCB" ) << std::endl;
    std::cout << "getPass: " << s2Inner.getPass() << std::endl;
    std::cout << "setName: " << s2Inner.setName( "NAME1234" ) << std::endl;
    std::cout << "getName: " << s2Inner.getName() << std::endl;
    std::cout << "setName: " << s2Inner.setName( "LilyBot" ) << std::endl;
    std::cout << "getName: " << s2Inner.getName() << std::endl;
    std::cout << "getState: " << s2Inner.getState() << std::endl;
    std::cout << "setData: " << s2Inner.setData( data1 ) << std::endl;
    s2Inner.getData( data );
    std::cout << "getData: " << Utils::bytesToHex( data, Scribbler2::DATA_LENGTH )<< std::endl;
    std::cout << "setData: " << s2Inner.setData( data2 ) << std::endl;
    s2Inner.getData( data );
    std::cout << "getData: " << Utils::bytesToHex( data, Scribbler2::DATA_LENGTH )<< std::endl;
    std::cout << "setSingleData: " << s2Inner.setSingleData( 4, 44 ) << std::endl;
    s2Inner.getData( data );
    std::cout << "getData: " << Utils::bytesToHex( data, Scribbler2::DATA_LENGTH )<< std::endl;

    robot.close();
}
