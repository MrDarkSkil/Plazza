//
// Condvar.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Sat Apr 15 23:32:01 2017 gastal_r
// Last update Sat Apr 22 13:50:51 2017 gastal_r
//

#ifndef         _CONDVAR_HPP_
#define         _CONDVAR_HPP_

#include        "ICondVar.hh"

class CondVar : public ICondVar
{
public:
  CondVar()   { pthread_cond_init(&_cond, nullptr); }
  ~CondVar()  { pthread_cond_destroy(&_cond); }

  CondVar(const CondVar& other) = default;
  CondVar(CondVar&& other) = default;
  CondVar& operator=(const CondVar& other) = default;
  CondVar& operator=(CondVar&& other) = default;

  void wait(pthread_mutex_t *mutex) { pthread_cond_wait(&_cond, mutex); }
  void broadcast(void)              { pthread_cond_broadcast(&_cond); }
  void signal(void)                 { pthread_cond_signal(&_cond); }

private:
  pthread_cond_t  _cond;
};

#endif /* !_CONDVAR_HPP_ */
