//
// NamedPipe.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 17 15:42:43 2017 gastal_r
// Last update Tue Apr 25 12:37:50 2017 gastal_r
//

#ifndef       _NAMEDPIPE_HPP_
#define       _NAMEDPIPE_HPP_

class         NamedPipe
{
public:
  NamedPipe(std::string);
  ~NamedPipe();
  NamedPipe(const NamedPipe& other) = default;
  NamedPipe(NamedPipe&& other) = default;
  NamedPipe& operator=(const NamedPipe& other) = default;
  NamedPipe& operator=(NamedPipe&& other) = default;

  bool		read(std::string &msg) const;
  bool		write(const std::string &msg) const;
  void		destroy();
  std::string getName() const;

private:
  std::string _name;
  std::string	_filename;
  int		_fd;

};

#endif /* !_NAMEDPIPE_HPP_ */
