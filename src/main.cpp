/*
** main.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Wed Apr 12 11:08:54 2017 gastal_r
** Last update	Wed Apr 12 14:14:34 2017 gastal_r
*/

#include "Orders.hh"

int         main(int argc, char const *argv[])
{
  std::vector<Orders>	orders;
  std::string		commands;

  for (std::string line; std::getline(std::cin, line);)
    if (Orders::parseLine(orders, line) == -1)
      return -1;

  (void) argc;
  (void) argv;
  return 0;
}
