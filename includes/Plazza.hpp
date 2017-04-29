//
// Plazza.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Apr 20 11:11:05 2017 gastal_r
// Last update Fri Apr 28 22:10:53 2017 gastal_r
//

#ifndef       _PLAZZA_HPP_
#define       _PLAZZA_HPP_

#include      <semaphore.h>
#include      <fcntl.h>
#include      <vector>
#include      <thread>
#include      <chrono>
#include      "Orders.hpp"
#include      "Process.hpp"

class         Plazza
{
public:
  Plazza() {};

  void         dividOrders(std::vector<std::pair<std::string, Information>> &, int);
  static void  *startParser(void *);

  std::vector<size_t> &getProcess() { return (_process); }

  private:
    std::vector<size_t>  _process;
};

#endif /* !_PLAZZA_HPP_ */
