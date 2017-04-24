/*
** ISafeQueue.hh for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Sat Apr 15 21:16:23 2017 gastal_r
** Last update	Sat Apr 15 21:20:09 2017 gastal_r
*/

#ifndef       _ISAFEQUEUE_HH_
#define       _ISAFEQUEUE_HH_

class         ISafeQueue
{
public:
  virtual ~ISafeQueue(void);
  //virtual void push(int value) = 0;
  //virtual bool tryPop(int* value) = 0;
  virtual bool isFinished(void) = 0;
  virtual void setFinished(void) = 0;
};

#endif /* !_ISAFEQUEUE_HH_ */
