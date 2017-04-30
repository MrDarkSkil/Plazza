/*
** main.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Wed Apr 12 11:08:54 2017 gastal_r
** Last update	Sat Apr 15 19:43:08 2017 gastal_r
*/

#include    "Orders.hpp"
#include    "Mutex.hpp"
#include    "ScopedLock.hpp"
#include    "Thread.hpp"
#include    "CondVar.hpp"
#include    "Plazza.hpp"
#include    "NamedPipe.hpp"

int		main(int ac, char const *av[])
{
  if (ac != 2)
  {
    std::cout << "Usage: " << av[0] << " [threads numbers per process]" << "\n";
    return (0);
  }
  else if (std::stoi(av[1]) <= 0)
  {
    std::cout << "Thread number need to be positive" << "\n";
    return (0);
  }
  Orders	order;
  Plazza	plazza;
  NamedPipe nm("1");
  for (std::string line; std::getline(std::cin, line);)
    {
      order.clear();
      order.epur(line);
      if (line != "")
	if (order.parseLine(line) == -1)
	  return -1;
      plazza.dividOrders(order.getOrders(), std::stoi(av[1]));
    }
    nm.destroy();
  return (0);
}
