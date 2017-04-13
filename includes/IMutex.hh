/*
** IMutex.hh for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Wed Apr 12 22:21:51 2017 gastal_r
** Last update	Thu Apr 13 21:40:01 2017 gastal_r
*/

#ifndef         _IMUTEX_HH_
#define         _IMUTEX_HH_


class           IMutex
{
public:
  virtual       ~IMutex(void) {};
  virtual void  lock(void) = 0;
  virtual void  unlock(void) = 0;
  virtual bool  trylock(void) = 0;
};


#endif /* !_IMUTEX_HH_ */
