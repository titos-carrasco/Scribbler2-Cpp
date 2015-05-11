#include <iostream>
#include <sstream>
#include <unistd.h>
#include <iomanip>
#include "Utils.h"

namespace rcr {
namespace utils {

void Utils::pause( unsigned int ms )
{
    usleep( ms * 1000 );
}

std::string Utils::bytesToHex( const uint8_t b[], int len )
{
    std::stringstream ss;
    for(int i = 0; i < len; i++ ) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)b[i];
    }
    return ss.str();
}

void Utils::debug( const std::string& msg )
{
    std::cout << msg << std::endl;
}

void Utils::debug( int n )
{
    std::cout << n << std::endl;
}

void Utils::debug( const uint8_t b[], int len )
{
    std::cout << bytesToHex( b, len ) << std::endl;
}

}}
