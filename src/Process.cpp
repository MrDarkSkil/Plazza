//
// Process.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:50:43 2017 gastal_r
// Last update Sat Apr 22 14:02:22 2017 gastal_r
//

#include        "Process.hpp"

Process::Process(const std::vector<std::pair<std::string, Information>> &orders, int nbThreads) :
   _orders(orders), _nbThreads(nbThreads)
{
/*  _thread.reserve(_nbThreads);
  for (int i = 0; i < nbThreads; ++i)
  {
    Thread tread;
    _thread.push_back(tread);
  } */
  _thread.resize(nbThreads);
}

int          Process::checkThreadSlot()
{
  for (int i = 0; i < _nbThreads; ++i)
  {
    std::cerr << "Thread [" << i << "] status: " << (int) _thread.at(i).getStatus() << '\n';
    if (_thread.at(i).getStatus() == Thread::Status::NOT_STARTED
        || _thread.at(i).getStatus() == Thread::Status::DEAD)
      return (i);
  }
  return (-1);
}

void        *test(void *status)
{
  Thread::Status *tstat = (Thread::Status*) status;
  std::cout << "It's work" << "\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  *tstat = Thread::Status::DEAD;
  return (nullptr);
}

void            Process::start()
{
  pid_t pid = fork();
  if (pid == 0)
  {
    for (auto & it : _orders)
    {
      int pos;
      while ((pos = checkThreadSlot()) == -1)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      _thread.at(pos).startThread(test,  &it);
    }
  }
  else if (pid < 0)
  {
    std::cout << "Fork failed" << "\n";
  }
  else
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}
