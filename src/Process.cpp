//
// Process.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:50:43 2017 gastal_r
// Last update Sat Apr 22 21:11:05 2017 gastal_r
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
    std::cerr << "Thread [" << i << "] status: " << (int) _thread.at(i).getStatus() << std::endl;
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
    std::cout << "NEW PROCESS" << std::endl;
    for (const auto & it : _orders)
    {
      int pos;
      while ((pos = checkThreadSlot()) == -1)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      _thread.at(pos).startThread(Plazza::startParser, it);
    }
    for (auto & it : _thread)
      it.waitThread();
    std::cout << "EXIT PROCESS" << std::endl;
    exit(0);
  }
  else if (pid < 0)
  {
    std::cout << "Fork failed" << "\n";
  }
}
