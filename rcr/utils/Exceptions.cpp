#include "Exceptions.h"

namespace rcr {
namespace utils {


CantCreateException::CantCreateException( const std::string& arg ): std::runtime_error(arg)
{
}

CantCreateException::~CantCreateException() throw()
{
}

CantOpenException::CantOpenException( const std::string& arg ): std::runtime_error(arg)
{
}

CantOpenException::~CantOpenException() throw()
{
}

InvalidParameterException::InvalidParameterException( const std::string& arg ): std::runtime_error(arg)
{
}

InvalidParameterException::~InvalidParameterException() throw()
{
}

SerialTimeOutException::SerialTimeOutException( const std::string& arg ): std::runtime_error(arg)
{
}

SerialTimeOutException::~SerialTimeOutException() throw()
{
}

PacketMismatchException::PacketMismatchException( const std::string& arg ): std::runtime_error(arg)
{
}

PacketMismatchException::~PacketMismatchException() throw()
{
}
}}
