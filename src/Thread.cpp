/*
** Thread.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Sat Apr 15 13:17:08 2017 gastal_r
** Last update	Sat Apr 15 14:09:30 2017 gastal_r
*/

#include      "Thread.hpp"

Thread::Status        Thread::getStatus(void) const
{
  return (_status);
}

void          Thread::waitThread(void)
{
  pthread_join(_thread, nullptr);
}

void          Thread::startThread(void *(*func)(void *))
{
  pthread_create(&_thread, nullptr, func, nullptr);
}
