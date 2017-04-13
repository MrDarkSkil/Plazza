/*
** Mutex.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 18:30:17 2017 gastal_r
** Last update	Thu Apr 13 21:53:46 2017 gastal_r
*/

#include      "Mutex.hpp"

Mutex::Mutex(void)
{
  _mutex = PTHREAD_MUTEX_INITIALIZER;
}

Mutex::~Mutex(void)
{}

Mutex::Mutex(Mutex &obj)
{
  _mutex = obj.getMutex();
}

Mutex &Mutex::operator=(Mutex &obj)
{
  _mutex = obj.getMutex();
  return (*this);
}

void        Mutex::lock(void)
{
  pthread_mutex_lock(&_mutex);
}

void        Mutex::unlock(void)
{
  pthread_mutex_unlock(&_mutex);
}

bool        Mutex::trylock(void)
{
  return (pthread_mutex_trylock(&_mutex));
}
