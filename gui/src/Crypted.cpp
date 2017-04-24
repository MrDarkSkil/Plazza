//
// Crypted.cpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
// 
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
// 
// Started on  Tue Apr 18 17:16:23 2017 sellet_f
// Last update Tue Apr 18 17:20:26 2017 sellet_f
//

#include "Crypted.hpp"

std::string	Crypted::decryptXor(std::string str, int key)
{
  std::string	tmp = str;

  for (unsigned int i = 0 ; i < str.length() ; ++i)
    tmp[i] ^= key;
  return (tmp);
}

std::string	Crypted::decryptCaesar(std::string str, int key)
{
  std::string	tmp = str;

  for (unsigned int i = 0 ; i < str.length() ; ++i)
    {
      if (tmp[i] + key < 127)
	tmp[i] += key;
      else
	tmp += key - 126;
    }
  return (tmp);
}
