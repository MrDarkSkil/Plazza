/*
** main.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Wed Apr 12 11:08:54 2017 gastal_r
** Last update	Wed Apr 12 14:14:34 2017 gastal_r
*/

#include "Orders.hpp"
#include "Mutex.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"
#include "CondVar.hpp"
#include "SafeQueue.hpp"

int		main(int argc, char const *argv[])
{
  Orders	order;
  std::string	commands;

  for (std::string line; std::getline(std::cin, line);)
    {
      std::cout << "line == " << line << std::endl;
      if (order.parseLine(line) == -1)
	return -1;
      order.clear();
    }

  (void) argc;
  (void) argv;
  return 0;
}
