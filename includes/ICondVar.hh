//
// ICondVar.hh for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Sat Apr 15 21:45:57 2017 gastal_r
// Last update Sat Apr 15 21:48:07 2017 gastal_r
//

#ifndef       _ICONDVAR_HH_
#define       _ICONDVAR_HH_

class         ICondVar
{
public:
  virtual void wait(void) = 0;
  virtual void signal(void) = 0;
  virtual void broadcast(void) = 0;
};

#endif /* !_ICONDVAR_HH_ */
