//
// Crypted.hpp for Project-Master in /home/sellet_f/Projets/Tek2/Plazza
// 
// Made by sellet_f
// Login   <flavien.sellet@epitech.eu>
// 
// Started on  Tue Apr 18 17:18:57 2017 sellet_f
// Last update Tue Apr 18 17:19:48 2017 sellet_f
//

#ifndef _CRYPTED_HPP_
# define _CRYPTED_HPP_

# include <iostream>

class	Crypted
{
public:
  std::string	decryptXor(std::string, int);
  std::string	decryptCaesar(std::string, int);
};

#endif
