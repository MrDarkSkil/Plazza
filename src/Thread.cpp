//
// Thread.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 22:05:15 2017 gastal_r
// Last update Sat Apr 22 12:00:55 2017 gastal_r
//

#include      "Thread.hpp"

Thread::Thread (void) : _status(Status::NOT_STARTED)
{};

Thread::~Thread()
{
  _status = Status::DEAD;
  _mutex.unlock();
}

void        Thread::waitThread(void)
{
  pthread_join(_thread, nullptr);
}

void      Thread::startThread(void *(*func)(void *), void *arg)
{
  _mutex.trylock();
  pthread_create(&_thread, nullptr, func, &_status);
  _status = Thread::Status::RUNNING;
}
#include <iostream>
Thread::Status      Thread::getStatus(void)
{
  if (_mutex.trylock() != false)
  {
    _status = Thread::Status::NOT_STARTED;
  }
  return (_status);
}
