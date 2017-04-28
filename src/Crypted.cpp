//
// Crypted.cpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
//
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
//
// Started on  Tue Apr 18 17:16:23 2017 sellet_f
// Last update Fri Apr 28 21:55:07 2017 gastal_r
//

#include "Crypted.hpp"

std::string	Crypted::decryptXor(const std::string &str, int key)
{
  std::string	tmp(str);

  for (unsigned int i = 0 ; i < str.length() ; ++i)
    tmp[i] ^= key;
  return (tmp);
}

std::string	Crypted::decryptCaesar(const std::string &str, int key)
{
  std::string	tmp(str);

  for (unsigned int i = 0 ; i < str.length() ; ++i)
    {
      if (tmp[i] + key < 127)
	tmp[i] += key;
      else
	tmp += key - 126;
    }
  return (tmp);
}
