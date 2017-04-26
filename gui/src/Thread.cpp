//
// Thread.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 22:05:15 2017 gastal_r
// Last update Wed Apr 26 02:54:31 2017 gastal_r
//

#include      "Thread.hpp"

Thread::Data::Data(Mutex &mutex, Status &status) : _mutex(mutex), _status(status)
{}

void      Thread::Data::setOrders(const std::pair<std::string, Information> &orders)
{
  _orders = orders;
}

Thread::Thread (void) : _mutex(), _status(Status::NOT_STARTED), _data(_mutex, _status)
{}

Thread::~Thread()
{
  _status = Status::DEAD;
  _mutex.unlock();
}

void        Thread::waitThread(void)
{
  pthread_join(_thread, nullptr);
}

void      Thread::startThread(void *(*func)(void *), const std::pair<std::string, Information> &orders)
{
  _data.setOrders(orders);
  if (_mutex.trylock() == true)
  {
    if (pthread_create(&_thread, nullptr, func, &_data) != 0)
    {
      std::cerr << "Thread creation error" << std::endl;
      _mutex.unlock();
    }
    else
      _status = Thread::Status::RUNNING;
  }
  else
    std::cerr << "ERROR LOCKING THREAD"  <<  '\n';
}

Thread::Status      Thread::getStatus(void)
{
  if (_status != Thread::Status::DEAD && _mutex.trylock() != false)
  {
    _status = Thread::Status::NOT_STARTED;
    _mutex.unlock();
  }
  return (_status);
}
