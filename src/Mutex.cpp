//
// Mutex.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 22:44:55 2017 gastal_r
// Last update Wed Apr 19 22:47:35 2017 gastal_r
//

#include      "Mutex.hpp"

Mutex::Mutex(void)
{
  pthread_mutex_init(&_mutex, nullptr);
}

Mutex::~Mutex(void)
{
  pthread_mutex_destroy(&_mutex);
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
  if (pthread_mutex_trylock(&_mutex) == -1)
    return (false);
  return (true);
}
