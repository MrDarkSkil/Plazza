//
// NamedPipe.hpp for Plazza in /home/gastal_r/rendu/Plazza/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 17 15:42:43 2017 gastal_r
// Last update Tue Apr 25 22:37:39 2017 gastal_r
//

#ifndef       _NAMEDPIPE_HPP_
#define       _NAMEDPIPE_HPP_

#include      <string>
#include      <fstream>
#include      <vector>
#include      <sys/types.h>
#include      <sys/stat.h>
#include      <unistd.h>
#include      "IThread.hh"

class         NamedPipe
{
public:
  class       Data
  {
  public:
    Data() : _dead(false) {};

    void setOrders(const std::vector<std::pair<std::string, Information>> &orders) { _orders = orders; }
    void setStatus(const std::vector<IThread::Status> &status) { _status = status; }
    void setDeath(bool val) { _dead = val; }

    std::vector<std::pair<std::string, Information>> getOrders(void) const { return (_orders); }
    std::vector<IThread::Status> getStatus(void) const { return (_status); }
    bool  getDeath() const { return (_dead); }

    friend std::ostream& operator<<(std::ostream &os, const Data& o);
    friend std::istream& operator>>(std::istream &os, Data& o);

  private:
    std::vector<std::pair<std::string, Information>> _orders;
    std::vector<IThread::Status> _status;
    bool _dead;
  };

public:
  explicit NamedPipe(const std::string &);
  ~NamedPipe();
  NamedPipe(const NamedPipe& other) = default;
  NamedPipe(NamedPipe&& other) = default;
  NamedPipe& operator=(const NamedPipe& other) = default;
  NamedPipe& operator=(NamedPipe&& other) = default;

  bool		readContent(NamedPipe::Data &) const;
  bool		writeContent(const NamedPipe::Data &) const;
  void		destroy();

private:
  std::string _name;
  std::string	_filename;
  int		_fd;

};

#endif /* !_NAMEDPIPE_HPP_ */
