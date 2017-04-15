//
// orders.cpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
//
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
//
// Started on  Thu Apr 13 14:34:02 2017 sellet_f
// Last update Thu Apr 13 14:45:37 2017 sellet_f
//

#include "Orders.hpp"

Orders		Orders::setInfos(std::string &token, Orders newOrder)
{
  if (!token.compare("PHONE_NUMBER"))
    newOrder.infos.push_back(Information::PHONE_NUMBER);
  else if (!token.compare("EMAIL_ADDRESS"))
    newOrder.infos.push_back(Information::EMAIL_ADDRESS);
  else if (!token.compare("IP_ADDRESS"))
    newOrder.infos.push_back(Information::IP_ADDRESS);
  else
    newOrder.files.push_back(token);
  return (newOrder);
}

int		Orders::fillOrders(std::vector<Orders> &orders, std::string command)
{
  Orders	newOrder;
  std::string	token;
  size_t	pos;

  pos = 0;
  while ((pos = command.find(" ")) != std::string::npos)
    {
      token = command.substr(0, pos);
      newOrder = Orders::setInfos(token, newOrder);
      command.erase(0, pos + 1);
    }
  token = command.substr(0, pos);
  newOrder = Orders::setInfos(token, newOrder);

  if (newOrder.infos.size() == 0)
    return -1;
  orders.push_back(newOrder);
  std::cout << "Files = ";
  for (const auto & it : newOrder.files)
    std::cout << it << "; ";
  std::cout << std::endl << "Command = ";
  for (const auto & it : newOrder.infos)
    std::cout << (int) it << "; ";
  std::cout << std::endl;
  return 0;
}

int		Orders::parseLine(std::vector<Orders> &orders, std::string commands)
{
  std::string	token;
  size_t	pos;

  pos = 0;
  while ((pos = commands.find(";")) != std::string::npos)
    {
      token = commands.substr(0, pos);
      Orders::fillOrders(orders, token);
      commands.erase(0, pos +  2);
    }
  token = commands.substr(0, pos);
  Orders::fillOrders(orders, token);
  if (orders.size() == 0)
    return -1;
  return 0;
}
