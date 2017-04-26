/*
** main.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Wed Apr 12 11:08:54 2017 gastal_r
** Last update	Sat Apr 15 19:43:08 2017 gastal_r
*/
#include <QApplication>
#include    "Orders.hpp"
#include    "Mutex.hpp"
#include    "ScopedLock.hpp"
#include    "Thread.hpp"
#include    "CondVar.hpp"
#include    "SafeQueue.hpp"
#include    "Plazza.hpp"
#include    "MainWindow.hpp"
#include    "NamedPipe.hpp"

int		main(int ac, char *av[])
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

  QApplication app(ac, av);

  MainWindow win;
  std::cout << "test" << std::endl;
  Orders	order;
  Plazza  plazza;

  win.show();
  for (std::string line; std::getline(std::cin, line);)
    {
      //std::cout << "line == " << line << std::endl;
      order.clear();
      if (order.parseLine(line) == -1)
	     return -1;
       plazza.dividOrders(order.getOrders(), std::stoi(av[1]), win);
    }

  while (1)
  {
    std::vector<size_t>  &proc = plazza.getProcess();
    std::vector<NamedPipe::Data>  data;

    data.clear();
    for (size_t i = 0; i < proc.size(); ++i)
    {
      NamedPipe::Data tmp;
      NamedPipe np(std::to_string(proc.at(i)));
      np.readContent(tmp);
      if (tmp.getDeath())
      {
        proc.erase(std::find(proc.begin(), proc.end(), proc.at(i)));
        i = 0;
      }
      else
        data.push_back(tmp);
      QCoreApplication::processEvents();
    }
    win.refreshList(data);
  }
  return (app.exec());
}
