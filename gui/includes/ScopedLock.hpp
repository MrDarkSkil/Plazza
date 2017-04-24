/*
** ScopedLock.hpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 16:17:37 2017 gastal_r
** Last update	Sat Apr 15 14:48:00 2017 gastal_r
*/

#ifndef       _SCOPED_HPP_
#define       _SCOPED_HPP_

#include      "Mutex.hpp"

class         ScopedLock
{
public:
  explicit    ScopedLock(Mutex &mutex) : _mutex(mutex) { _mutex.lock(); }
  virtual     ~ScopedLock(void) { _mutex.unlock(); }

  ScopedLock(const ScopedLock &) = default;
  ScopedLock(ScopedLock &&) = default;
  ScopedLock &operator=(const ScopedLock &) = default;
  ScopedLock &operator=(ScopedLock &&) = default;

private:
  Mutex      _mutex;
};

#endif /* !_SCOPED_HPP_ */
