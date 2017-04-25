//
// orders.cpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
//
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
//
// Started on  Thu Apr 13 14:34:02 2017 sellet_f
// Last update Mon Apr 24 14:53:36 2017 sellet_f
//

#include "Orders.hpp"
#include "Parser.hpp"

void		Orders::epur(std::string &str)
{
  bool		space;
  auto		beg = str.begin();

  space = false;
  for (auto ch : str)
    if (std::isspace(ch))
      space = beg != str.begin();
    else
      {
	if (space)
	  *beg++ = ' ';
	*beg++ = ch;
	space = false;
      }
  str.erase(beg, str.end());
}

int		Orders::setInfos(std::string &token, Information &info)
{
  if (!token.compare("PHONE_NUMBER"))
    {
      info = info == Information::UNDEFINED ? Information::PHONE_NUMBER : info;
      return (1);
    }
  else if (!token.compare("EMAIL_ADDRESS"))
    {
      info = info == Information::UNDEFINED ? Information::EMAIL_ADDRESS : info;
      return (1);
    }
  else if (!token.compare("IP_ADDRESS"))
    {
      info = info == Information::UNDEFINED ? Information::IP_ADDRESS : info;
      return (1);
    }
  return (0);
}

int						Orders::fillOrders(std::string &command)
{
  std::pair<std::string, Information>		newOrder;
  std::string					token;
  Information					info;
  size_t					pos;

  pos = 0;
  info = Information::UNDEFINED;
  while ((pos = command.find(" ")) != std::string::npos)
    {
      newOrder = make_pair(std::string(""), Information::UNDEFINED);
      token = command.substr(0, pos);
      if (Orders::setInfos(token, info) == 0)
	{
	  newOrder.first = token;
	  _orders.push_back(newOrder);
	}
      command.erase(0, pos + 1);
    }
  newOrder = make_pair(std::string(""), Information::UNDEFINED);
  token = command.substr(0, pos);
  if (Orders::setInfos(token, info) == 0)
    {
      newOrder.first = token;
      _orders.push_back(newOrder);
    }
  if (info == Information::UNDEFINED)
    return -1;

  for (auto & it : _orders)
    if (it.second == Information::UNDEFINED)
      it.second = info;
  return 0;
}

void		Orders::clear(void)
{
  _orders.clear();
}

std::vector<std::pair<std::string, Information>>	&Orders::getOrders(void)
{
  return (_orders);
}

int		Orders::parseLine(std::string &commands)
{
  std::string	token;
  size_t	pos;
  Parser    parser(" ", Information::UNDEFINED);

  while ((pos = commands.find(";")) != std::string::npos)
    {
      token = commands.substr(0, pos);
      if (token != "")
	Orders::fillOrders(token);
      commands.erase(0, pos +  2);
    }
  token = commands.substr(0, pos);
  if (token != "")
    Orders::fillOrders(token);
  if (_orders.size() == 0)
    return -1;
  return 0;
}
