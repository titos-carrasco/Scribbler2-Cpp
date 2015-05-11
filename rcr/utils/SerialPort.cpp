#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "SerialPort.h"
#include "Exceptions.h"

namespace rcr {
namespace utils {

SerialPort::SerialPort( const std::string& port, int bauds, int timeout )
{
    // O_NOCTTY=no controlling terminal, O_NDELAY=dont use DCD
    fd = open( port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY );
    if(fd == -1)
        throw CantOpenException( "Error en SerialPort::SerialPort." );

    // FNDELAY=non blocking read, return 0
    fcntl( fd, F_SETFL, FNDELAY );

    // limpia estructura termios
    struct termios options;
    //tcgetattr( fd, &options );
    memset( &options, 0, sizeof( options ) );

    // la velocidad
    speed_t speed;
    switch(bauds) {
    case 110    :
        speed = B110;
        break;
    case 300    :
        speed = B300;
        break;
    case 600    :
        speed = B600;
        break;
    case 1200   :
        speed = B1200;
        break;
    case 2400   :
        speed = B2400;
        break;
    case 4800   :
        speed = B4800;
        break;
    case 9600   :
        speed = B9600;
        break;
    case 19200  :
        speed = B19200;
        break;
    case 38400  :
        speed = B38400;
        break;
    case 57600  :
        speed = B57600;
        break;
    case 115200 :
        speed = B115200;
        break;
    default     :
        throw InvalidParameterException( "Error en SerialPort::SerialPort - Bauds.");
    }
    cfsetispeed(&options, speed);
    cfsetospeed(&options, speed);

    // local mode and enable receiver
    options.c_cflag |= ( CLOCAL | CREAD );

    // 8N1
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    // raw input
    cfmakeraw( &options );

    // ignore parity and break
    options.c_iflag |= ( IGNPAR | IGNBRK );

    // no wait
    options.c_cc[VTIME]=0;
    options.c_cc[VMIN]=0;

    // flush buffers
    tcflush( fd, TCIOFLUSH );

    // los cambios toman efecto desde ahora
    tcsetattr(fd, TCSANOW, &options);

    realTimeOut = 1;
    userTimeOut = timeout;
    maxTries = userTimeOut / realTimeOut;

    // para poll
    fds[0].fd = fd;
    fds[0].events = POLLIN;
}

SerialPort::~SerialPort()
{
    //close();
}

void SerialPort::close()
{
    Lock lock( mutex );
    ::close( fd );
}

int SerialPort::write( const uint8_t b[], int nbytes )
{
    Lock lock( mutex );
    int n = ::write( fd, b, nbytes );
    tcdrain( fd );
    return n;
}

std::string SerialPort::readLine( int maxChars )
{
    Lock lock( mutex );
    uint8_t bytes[maxChars + 1];
    uint8_t b;
    int pos = 0;
    int tries = 0;
    while( pos < maxChars + 1 && tries < maxTries ) {
        int n = 0;
        if( poll(fds, 1, realTimeOut ) == 1 )
            n = ::read( fd, &b, 1);
        if( n <= 0 ) {
            tries++;
            continue;
        }
        // fin de línea detectado
        if( b == 10 ) {
            return std::string( (char*)bytes, 0, pos );
        }
        bytes[ pos++ ] = b;
        tries = 0;
    }
    throw SerialTimeOutException( "Error en Serial::readLine." );
}

void SerialPort::read( uint8_t b[], int nbytes )
{
    Lock lock( mutex );
    int pos = 0;
    int tries = 0;
    uint8_t data;
    while( pos < nbytes && tries < maxTries ) {
        int n = poll(fds, 1, realTimeOut );
        if( n > 0 ) {
            n = ::read( fd, &data, 1 );
        }
        if( n <= 0 ) {
            tries++;
            continue;
        }
        b[ pos++ ] = data;
        tries = 0;
    }
    if( pos < nbytes ) {
        throw SerialTimeOutException( "Error en SerialPort::read." );
    }
}

void SerialPort::flushRead( int time )
{
    Lock lock( mutex );
    double t = (double)time/1000.0;
    time_t t2, t1 = ::time(NULL);
    do {
        try {
            uint8_t b;
            ::read( fd, &b, 1);
        } catch(...) {
        }
        t2 = ::time(NULL);
    } while( difftime( t2, t1 ) <= t );
}

uint8_t SerialPort::readUInt8()
{
    uint8_t b[1] = { 0 };
    read( b, 1 );
    unsigned int n = b[0] & 0xFF;
    return n;
}

uint16_t SerialPort::readUInt16()
{
    uint8_t b[2] = { 0 };
    read( b, 2 );
    unsigned int n = b[0] & 0x000000FF;
    n = ( n<<8 ) | ( b[1] & 0xFF );
    return n;
}

uint32_t SerialPort::readUInt32()
{
    uint8_t b[4] = { 0 };
    read( b, 4 );
    unsigned int n = b[0] & 0x000000FF;
    n = ( n << 8 ) | ( b[1] & 0xFF );
    n = ( n << 8 ) | ( b[2] & 0xFF );
    n = ( n << 8 ) | ( b[3] & 0xFF );
    return n;
}

int32_t SerialPort::readInt32()
{
    int n = readUInt32();
    return n;
}

}}
