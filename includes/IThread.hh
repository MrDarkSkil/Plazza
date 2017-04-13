/*
** IThread.hh for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Thu Apr 13 16:45:01 2017 gastal_r
** Last update	Thu Apr 13 16:55:27 2017 gastal_r
*/

#ifndef       _ITHREAD_HH_
#define       _ITHREAD_HH_

class         IThread
{
  enum        Status
  {
    NOT_STARTED,
    RUNNING,
    DEAD
  };

public:
  virtual         ~IThread ();
  virtual Status  getStatus() const = 0;
  virtual void    waitThread() = 0;
};

#endif        /* !_ITHREAD_HH_ */
