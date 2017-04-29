//
// Plazza.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Apr 20 11:10:38 2017 gastal_r
// Last update Fri Apr 28 21:59:15 2017 gastal_r
//

#include      "Plazza.hpp"
#include      "Parser.hpp"

void          *Plazza::startParser(void *status)
{
  Parser  parser("",(Information)1);
  Thread::Data *data = (Thread::Data *) status;

  parser.setFile(data->getOrders().first);
  parser.setInformation((Information)data->getOrders().second);
  parser.parseFile();

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
