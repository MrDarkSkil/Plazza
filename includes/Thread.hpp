/*
** Thread.hpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Sat Apr 15 13:15:29 2017 gastal_r
** Last update	Sat Apr 15 14:09:09 2017 gastal_r
*/

#ifndef       _THREAD_HPP_
#define       _THREAD_HPP_

#include      "IThread.hh"

class         Thread : public IThread
{
public:
  explicit Thread (void) : _status(Status::NOT_STARTED) {};

  Status      getStatus(void) const             { return (_status); }
  void        waitThread(void)                  { pthread_join(_thread, nullptr); }
  void        startThread(void *(*func)(void*)) { pthread_create(&_thread, nullptr, func, nullptr); }

private:
  Status      _status;
  pthread_t   _thread;
};

#endif        /* !_THREAD_HPP_ */
