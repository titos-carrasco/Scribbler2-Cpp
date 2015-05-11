#include "Lock.h"
#include "Exceptions.h"

namespace rcr {
namespace utils {

Mutex::Mutex()
{
    if( pthread_mutex_init( &mutex, NULL ) != 0 ) {
        throw CantCreateException( "Error en Mutex::Mutex." );
    }
}

Mutex::~Mutex()
{
    pthread_mutex_destroy( &mutex );
}

void Mutex::lock()
{
    pthread_mutex_lock( &mutex );
}

void Mutex::unlock()
{
    pthread_mutex_unlock( &mutex );
}


Lock::Lock( Mutex& mutex_ ) : mutex( mutex_ )
{
    mutex.lock();
}

Lock::~Lock()
{
    mutex.unlock();
}

}}
