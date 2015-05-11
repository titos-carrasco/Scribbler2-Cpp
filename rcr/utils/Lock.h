#ifndef LOCK_H
#define LOCK_H

#include <pthread.h>

namespace rcr {
namespace utils {

class Mutex
{
private:
    pthread_mutex_t mutex;

public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
};

class Lock
{
private:
    Mutex& mutex;

public:
    Lock( Mutex& mutex_ );
    ~Lock();
};

}}

#endif // LOCK_H
