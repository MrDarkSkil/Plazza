//
// Plazza.cpp for Plazza in /home/gastal_r/rendu/Plazza/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Apr 20 11:10:38 2017 gastal_r
// Last update Sat Apr 22 12:23:02 2017 gastal_r
//

#include      "Plazza.hpp"

void          Plazza::dividOrders(std::vector<std::pair<std::string, Information>>	&orders, int nbThreads)
{
  Process process(orders, nbThreads);
  process.start();
}
