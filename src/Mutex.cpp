/*
** Mutex.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 18:30:17 2017 gastal_r
** Last update	Fri Apr 14 22:13:08 2017 gastal_r
*/

#include      "Mutex.hpp"

Mutex::Mutex(void)
{
  _mutex = PTHREAD_MUTEX_INITIALIZER;
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
