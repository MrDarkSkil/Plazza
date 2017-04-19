//
// Process.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:48:04 2017 gastal_r
// Last update Wed Apr 19 22:35:05 2017 gastal_r
//

#ifndef       _PROCESS_HPP_
#define       _PROCESS_HPP_

#include      <chrono>
#include      <thread>
#include      <vector>
#include      "Orders.hpp"
#include      "Thread.hpp"

class         Process
{
public:
  Process(const std::vector<Orders>	&, int nbThreads);

  int      checkThreadSlot();

  void        start();

private:
  std::vector<Orders>   _orders;
  std::vector<Thread>   _thread;
  int                   _nbThreads;
};

#endif /* end of include guard: _PROCESS_HPP_ */
