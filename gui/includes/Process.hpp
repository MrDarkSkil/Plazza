//
// Process.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:48:04 2017 gastal_r
// Last update Thu Apr 27 13:43:55 2017 gastal_r
//

#ifndef       _PROCESS_HPP_
#define       _PROCESS_HPP_

#include      <chrono>
#include      <thread>
#include      <sys/types.h>
#include      <sys/wait.h>
#include      <unistd.h>
#include      "Orders.hpp"
#include      "Thread.hpp"
#include      "NamedPipe.hpp"

class         Thread;

class         Process
{
public:
  Process(const std::vector<std::pair<std::string, Information>> &, int, size_t);

  virtual ~Process();
  Process(const Process& other) = default;
  Process(Process&& other) = default;
  Process& operator=(const Process& other) = default;
  Process& operator=(Process&& other) = default;

  int      checkThreadSlot();
  void     refreshGui();
  bool     checkDead();

  void        start();

private:
  std::vector<std::pair<std::string, Information>>   _orders;
  std::vector<Thread>   _thread;
  NamedPipe             _namedPipe;
  int                   _nbThreads;
  size_t                _processId;
};

#endif /* end of include guard: _PROCESS_HPP_ */
