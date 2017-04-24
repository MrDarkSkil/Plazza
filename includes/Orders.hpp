//
// Orders.hpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
//
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
//
// Started on  Thu Apr 13 02:08:15 2017 sellet_f
// Last update Mon Apr 24 14:41:51 2017 sellet_f
//

#ifndef     _ORDERS_HH_
# define    _ORDERS_HH_

# include   <vector>
# include   <iostream>

enum class Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS,
    UNDEFINED
  };

class	Orders
{
public:
  Orders() {};

  int	setInfos(std::string &, Information &);
  std::vector<std::pair<std::string, Information>>	&getOrders(void);
  int	fillOrders(std::string &);
  int	parseLine(std::string &);
  void	epur(std::string &);
  void	clear(void);

private:
  std::vector<std::pair<std::string, Information>>	_orders;
};

#endif
