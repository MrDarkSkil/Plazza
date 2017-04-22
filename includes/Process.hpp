//
// Process.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:48:04 2017 gastal_r
// Last update Thu Apr 20 16:45:09 2017 gastal_r
//

#ifndef       _PROCESS_HPP_
#define       _PROCESS_HPP_

#include      <chrono>
#include      <thread>
#include      <vector>
#include      <sys/types.h>
#include      <sys/wait.h>
#include      <unistd.h>
#include      "Orders.hpp"
#include      "Thread.hpp"

class         Process
{
public:
  Process(const std::vector<std::pair<std::string, Information>>	&, int);

  int      checkThreadSlot();

  void        start();

private:
  std::vector<std::pair<std::string, Information>>   _orders;
  std::vector<Thread>   _thread;
  int                   _nbThreads;
};

#endif /* end of include guard: _PROCESS_HPP_ */
