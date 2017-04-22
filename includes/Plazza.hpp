//
// Plazza.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Apr 20 11:11:05 2017 gastal_r
// Last update Sat Apr 22 11:12:53 2017 gastal_r
//

#ifndef       _PLAZZA_HPP_
#define       _PLAZZA_HPP_

#include      <vector>
#include      <thread>
#include      <chrono>
#include      "Orders.hpp"
#include      "Process.hpp"

class         Plazza
{
public:
  Plazza() {};

  void        dividOrders(std::vector<std::pair<std::string, Information>> &, int);

  ~Plazza() = default;
  Plazza(const Plazza& other) = default;
  Plazza(Plazza&& other) = default;
  Plazza& operator=(const Plazza& other) = default;
  Plazza& operator=(Plazza&& other) = default;
};

#endif /* !_PLAZZA_HPP_ */
