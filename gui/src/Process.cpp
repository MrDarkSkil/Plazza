//
// Process.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Apr 19 16:50:43 2017 gastal_r
// Last update Wed Apr 26 03:12:13 2017 gastal_r
//

#include        "Process.hpp"

Process::Process(const std::vector<std::pair<std::string, Information>> &orders, int nbThreads, size_t id) :
   _orders(orders), _namedPipe(std::to_string(id)), _nbThreads(nbThreads)
{
  _thread.resize(nbThreads);
}

Process::~Process()
{
  _namedPipe.destroy();
}

int          Process::checkThreadSlot()
{
  for (int i = 0; i < _nbThreads; ++i)
  {
    //std::cerr << "Thread [" << i << "] status: " << (int) _thread.at(i).getStatus() << std::endl;
    if (_thread.at(i).getStatus() == Thread::Status::NOT_STARTED
        || _thread.at(i).getStatus() == Thread::Status::DEAD)
      return (i);
  }
  return (-1);
}

void            Process::refreshGui()
{
  std::vector<Thread::Status> v;
  NamedPipe::Data data;

  for (int i = 0; i < _nbThreads; ++i)
  {
    //std::cerr << "Thread [" << i << "] status: " << (int) _thread.at(i).getStatus() << std::endl;
    //std::cout << "!!!! " << (int) _thread.at(i).getStatus() << std::endl;
    v.push_back(_thread.at(i).getStatus());
  }
  data.setStatus(v);
  data.setOrders(_orders);
  _namedPipe.writeContent(data);
}

bool            Process::checkDead()
{
  static std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  static std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();


  if (std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() < 5)
  {
    t2 = std::chrono::high_resolution_clock::now();
    return (false);
  }
  for (int i = 0; i < _nbThreads; ++i)
  {
    if (_thread.at(i).getStatus() == Thread::Status::RUNNING)
    {
      t2 = std::chrono::high_resolution_clock::now();
      return (false);
    }
  }
  return (true);
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
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      _thread.at(pos).startThread(Plazza::startParser, it);
      refreshGui();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    while (checkDead() == false)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      refreshGui();
    }
    NamedPipe::Data data;

    data.setDeath(true);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
   _namedPipe.writeContent(data);
/*    for (auto & it : _thread)
      it.waitThread(); */
    std::cout << "EXIT PROCESS" << std::endl;
    exit(0);
  }
  else if (pid < 0)
  {
    std::cout << "Fork failed" << "\n";
  }
}
