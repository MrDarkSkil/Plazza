//
// Plazza.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Apr 20 11:10:38 2017 gastal_r
// Last update Sat Apr 22 21:31:18 2017 gastal_r
//

#include      "Plazza.hpp"

void          *Plazza::startParser(void *status)
{
  Thread::Data *data = (Thread::Data *) status;
  std::cout << "ENTER THREAD" << "\n";
  //std::cout << data->getOrders().first << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  //Toujours laisser ça a la fin
  data->getMutex().unlock();
  data->getStatus() = Thread::Status::DEAD;
  return (nullptr);
}


void          Plazza::dividOrders(std::vector<std::pair<std::string, Information>>	&orders, int nbThreads)
{
  std::vector<std::pair<std::string, Information>>	tmp;
  while (orders.size() != 0)
  {
    tmp.clear();
    for (int i = 0; i < nbThreads * 2; ++i)
    {
      tmp.push_back(*orders.begin());
      orders.erase(orders.begin());
      if (orders.size() == 0)
        break;
    }
    Process process(tmp, nbThreads);
    process.start();
  }
}
