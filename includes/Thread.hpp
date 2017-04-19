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
#include      "Mutex.hpp"

class         Thread : public IThread
{
public:
  explicit Thread (void);
  ~Thread();
  Thread(const Thread& other) = default;
  Thread(Thread&& other) = default;
  Thread& operator=(const Thread& other) = default;
  Thread& operator=(Thread&& other) = default;

  void        waitThread(void);
  void        startThread(void *(*func)(void *), void *arg);

  Status      getStatus(void);

private:
  Mutex       _mutex;
  Status      _status;
  pthread_t   _thread;
};

#endif        /* !_THREAD_HPP_ */
