/*
** ScopedLock.hpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 16:17:37 2017 gastal_r
** Last update	Thu Apr 13 17:32:48 2017 gastal_r
*/

#ifndef       _SCOPED_HPP_
#define       _SCOPED_HPP_

#include      "Mutex.hpp"

class         ScopedLock
{
public:
  explicit    ScopedLock(Mutex &);
  virtual     ~ScopedLock(void);

private:
  Mutex      _mutex;
};

#endif /* !_SCOPED_HPP_ */
