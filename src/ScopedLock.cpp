/*
** ScopedLock.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 16:34:50 2017 gastal_r
** Last update	Thu Apr 13 21:57:09 2017 gastal_r
*/

#include        "ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &mutex)
{
  _mutex = mutex;
  _mutex.lock();
}

ScopedLock::~ScopedLock(void)
{
  _mutex.unlock();
}
