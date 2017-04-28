//
// Process.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:50:43 2017 gastal_r
// Last update Fri Apr 28 21:53:01 2017 gastal_r
//

#include        "Process.hpp"

Process::Process(const std::vector<std::pair<std::string, Information>> &orders, int nbThreads) :
   _orders(orders), _nbThreads(nbThreads)
{
  _thread.resize(nbThreads);
}

int          Process::checkThreadSlot()
{
  for (int i = 0; i < _nbThreads; ++i)
  {
    if (_thread.at(i).getStatus() == Thread::Status::NOT_STARTED
        || _thread.at(i).getStatus() == Thread::Status::DEAD)
      return (i);
  }
  return (-1);
}

void            Process::start()
{
  pid_t pid = fork();

  if (pid == 0)
  {
    for (const auto & it : _orders)
    {
      int pos;
      while ((pos = checkThreadSlot()) == -1)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      _thread.at(pos).startThread(Plazza::startParser, it);
    }
    for (auto & it : _thread)
      it.waitThread();
    exit(0);
  }
  else if (pid < 0)
    std::cerr << "Fork failed" << "\n";
}
