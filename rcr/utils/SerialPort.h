#ifndef SERIAL_H
#define SERIAL_H

#include <string>
#include <poll.h>
#include <stdint.h>
#include "Lock.h"

namespace rcr {
namespace utils {

class SerialPort
{
private:
    int fd;
    int realTimeOut;
    int userTimeOut;
    int maxTries;
    Mutex mutex;
    struct pollfd fds[1];

public:
    SerialPort( const std::string& port, int bauds, int timeout );
    ~SerialPort();
    void close();
    int write( const uint8_t b[], int nbytes );
    std::string readLine( int maxChars );
    void read( uint8_t b[], int nbytes );
    void flushRead( int time );
    uint8_t readUInt8();
    uint16_t readUInt16();
    uint32_t readUInt32();
    int32_t readInt32();
};

}}

#endif // SERIAL_H
