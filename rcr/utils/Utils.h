#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <stdint.h>

namespace rcr {
namespace utils {

class Utils
{
public:
    static void pause( unsigned int ms );
    static std::string bytesToHex( const uint8_t b[], int len );
    static void debug( const std::string& msg );
    static void debug( int n );
    static void debug( const uint8_t b[], int len );
};

}}

#endif // UTILS_H
