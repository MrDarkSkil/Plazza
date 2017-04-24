//
// NamedPipe.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 17 15:42:43 2017 gastal_r
// Last update Mon Apr 17 17:21:41 2017 gastal_r
//

#ifndef       _NAMEDPIPE_HPP_
#define       _NAMEDPIPE_HPP_

class         NamedPipe
{
public:
  NamedPipe();

  ~NamedPipe() = default;
  NamedPipe(const NamedPipe& other) = default;
  NamedPipe(NamedPipe&& other) = default;
  NamedPipe& operator=(const NamedPipe& other) = default;
  NamedPipe& operator=(NamedPipe&& other) = default;
};

#endif /* !_NAMEDPIPE_HPP_ */
