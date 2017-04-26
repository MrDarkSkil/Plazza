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

#include      <iostream>
#include      "IThread.hh"
#include      "Mutex.hpp"
#include      "Plazza.hpp"

class         Thread : public IThread
{
public:
  class       Data
  {
  public:
    Data(Mutex &, Status &);

    void    setOrders(const std::pair<std::string, Information> &orders);

    Status  &getStatus(void) { return (_status); }
    Mutex   &getMutex(void)  { return (_mutex); }
    const std::pair<std::string, Information> &getOrders(void) { return (_orders); }

  private:
    Mutex     &_mutex;
    Status    &_status;
    std::pair<std::string, Information>  _orders;
};

public:
  explicit Thread ();
  ~Thread();
  
  void        waitThread(void);
  void        startThread(void *(*func)(void *), const std::pair<std::string, Information> &);

  void        setProcessId(size_t id) { _processId = id; }

  Status      getStatus(void);
  size_t      getProcessId() const { return (_processId); }

private:
  Mutex       _mutex;
  Status      _status;
  Data        _data;
  pthread_t   _thread;
  size_t      _processId;
};

#endif        /* !_THREAD_HPP_ */
