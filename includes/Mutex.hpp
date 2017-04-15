/*
** Mutex.hpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 17:22:27 2017 gastal_r
** Last update	Sat Apr 15 11:47:49 2017 gastal_r
*/

#ifndef         _MUTEX_HPP_
#define         _MUTEX_HPP_

#include        <pthread.h>
#include        "IMutex.hh"

class Mutex : public IMutex
{
public:
  Mutex(void);

  void        lock(void);
  void        unlock(void);
  bool        trylock(void);

  const pthread_mutex_t &getMutex() const { return (_mutex); }


private:
  pthread_mutex_t _mutex;
};

#endif /* !_MUTEX_HPP_ */
