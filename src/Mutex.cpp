/*
** Mutex.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 18:30:17 2017 gastal_r
** Last update	Sat Apr 15 13:50:59 2017 gastal_r
*/

#include      "Mutex.hpp"

Mutex::Mutex(void)
{
  pthread_mutex_init(&_mutex, nullptr);
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
