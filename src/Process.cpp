//
// Process.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:50:43 2017 gastal_r
// Last update Wed Apr 19 22:36:22 2017 gastal_r
//

#include        "Process.hpp"

Process::Process(const std::vector<Orders> &orders, int nbThreads) :
   _orders(orders), _nbThreads(nbThreads)
{}

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
  _thread.reserve(_nbThreads);
/*  for (auto & it : _orders)
  {
    int pos;
    if ((pos = checkThreadSlot()) != -1)
    {
      //get order -> set au thread
      // start thread;
    }
    else
      std::this_thread::sleep_for(std::chrono::milliseconds(4000));

  } */
}
