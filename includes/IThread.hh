/*
** IThread.hh for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 16:45:01 2017 gastal_r
** Last update	Sat Apr 15 14:09:44 2017 gastal_r
*/

#ifndef       _ITHREAD_HH_
#define       _ITHREAD_HH_

#include      <thread>
#include      <string>
#include      <vector>
#include      "Orders.hpp"

class         IThread
{
public:
  enum class  Status
  {
    NOT_STARTED,
    RUNNING,
    DEAD
  };

public:
  virtual         ~IThread() {};

  virtual Status  getStatus() = 0;
  virtual void    waitThread() = 0;
  virtual void    startThread(void *(*)(void*), const std::pair<std::string, Information> &) = 0;
};

#endif        /* !_ITHREAD_HH_ */
