/*
** SafeQueue.hpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Sat Apr 15 21:18:33 2017 gastal_r
** Last update	Sat Apr 15 21:19:28 2017 gastal_r
*/

#ifndef         _SAFEQUEUE_HPP_
#define         _SAFEQUEUE_HPP_

#include        "ISafeQueue.hh"

class           SafeQueue : public ISafeQueue
{
public:
  SafeQueue() {};
  ~SafeQueue() = default;
  
  SafeQueue(const SafeQueue& other) = default;
  SafeQueue(SafeQueue&& other) = default;
  SafeQueue& operator=(const SafeQueue& other) = default;
  SafeQueue& operator=(SafeQueue&& other) = default;
};

#endif /* !_SAFEQUEUE_HPP_ */
