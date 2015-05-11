#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace rcr {
namespace utils {

class CantCreateException : public std::runtime_error
{
public:
    CantCreateException( const std::string& arg );
    virtual ~CantCreateException() throw();
};

class CantOpenException : public std::runtime_error
{
public:
    CantOpenException( const std::string& arg );
    virtual ~CantOpenException() throw();
};

class InvalidParameterException : public std::runtime_error
{
public:
    InvalidParameterException( const std::string& arg );
    virtual ~InvalidParameterException() throw();
};

class SerialTimeOutException : public std::runtime_error
{
public:
    SerialTimeOutException( const std::string& arg );
    virtual ~SerialTimeOutException() throw();
};

class PacketMismatchException : public std::runtime_error
{
public:
    PacketMismatchException( const std::string& arg );
    virtual ~PacketMismatchException() throw();
};

}}

#endif // EXCEPTIONS_H

