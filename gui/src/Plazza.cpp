//
// Plazza.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Apr 20 11:10:38 2017 gastal_r
// Last update Wed Apr 26 03:10:25 2017 gastal_r
//

#include      "Plazza.hpp"
#include      "Parser.hpp"

Plazza::Plazza()
{}

void          *Plazza::startParser(void *status)
{
    Parser  parser("",(Information)1);
  Thread::Data *data = (Thread::Data *) status;
  std::cout << "ENTER THREAD" << "\n";

  parser.setFile(data->getOrders().first);
  parser.setInformation((Information)data->getOrders().second);
  parser.parseFile();

  //Toujours laisser ça a la fin
  std::this_thread::sleep_for(std::chrono::milliseconds(600));
  data->getMutex().unlock();
  data->getStatus() = Thread::Status::DEAD;
  std::cout << "EXIT THREAD" << std::endl;
  return (nullptr);
}


void          Plazza::dividOrders(std::vector<std::pair<std::string, Information>>	&orders, int nbThreads, MainWindow &win)
{
  std::vector<std::pair<std::string, Information>>	tmp;
  size_t nb;

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
    if (_process.empty())
      nb = 0;
    else
      nb = _process.back() + 1;
    Process process(tmp, nbThreads, nb);
    _process.push_back(nb);
    process.start();


    std::vector<NamedPipe::Data>  data;
    data.clear();
    for (size_t i = 0; i < _process.size(); ++i)
    {
      NamedPipe::Data tmp;
      NamedPipe np(std::to_string(_process.at(i)));
      np.readContent(tmp);
      if (tmp.getDeath())
      {
        _process.erase(std::find(_process.begin(), _process.end(), _process.at(i)));
        i = 0;
      }
      else
        data.push_back(tmp);
      QCoreApplication::processEvents();
    }
    win.refreshList(data);
  }
}
