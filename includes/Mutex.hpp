/*
** Mutex.hpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 17:22:27 2017 gastal_r
** Last update	Sat Apr 15 21:12:20 2017 gastal_r
*/

#ifndef         _MUTEX_HPP_
#define         _MUTEX_HPP_

#include        <thread>
#include        "IMutex.hh"

class Mutex : public IMutex
{
public:
  Mutex(void)  { pthread_mutex_init(&_mutex, nullptr); }
  ~Mutex(void) { pthread_mutex_destroy(&_mutex); }

  Mutex(const Mutex& other) = default;
  Mutex(Mutex&& other) = default;
  Mutex& operator=(const Mutex& other) = default;
  Mutex& operator=(Mutex&& other) = default;

  void        lock(void)    { pthread_mutex_lock(&_mutex); }
  void        unlock(void)  { pthread_mutex_unlock(&_mutex); }
  bool        trylock(void) { return (pthread_mutex_trylock(&_mutex)); }

  pthread_mutex_t  &getMutex(void) { return (_mutex); }

private:
  pthread_mutex_t _mutex;
};

#endif /* !_MUTEX_HPP_ */
