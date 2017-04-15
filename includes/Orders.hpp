//
// Orders.hpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
//
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
//
// Started on  Thu Apr 13 02:08:15 2017 sellet_f
// Last update Thu Apr 13 14:44:52 2017 sellet_f
//

#ifndef     _ORDERS_HH_
# define    _ORDERS_HH_

# include   <vector>
# include   <iostream>

class	Orders
{
  enum class Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };

public:
  static Orders	setInfos(std::string &, Orders);
  static int	fillOrders(std::vector<Orders> &, std::string);
  static int	parseLine(std::vector<Orders> &, std::string);

private:
  std::vector<std::string>	files;
  std::vector<Information>	infos;
};

#endif
