//
// NamedPipe.cpp for Plazza in /home/gastal_r/rendu/Plazza/gui/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Tue Apr 25 12:24:55 2017 gastal_r
// Last update Thu Apr 27 13:57:24 2017 gastal_r
//

#include        "NamedPipe.hpp"

std::ostream& operator<<(std::ostream &os, const NamedPipe::Data& obj)
{
  os << obj.getDeath();
  os << " ";
  os << obj.getProcessId();
  os << " ";
  if (obj.getDeath())
    return (os);
  os << (size_t) obj.getOrders().size();
  os << " ";
  for (auto & it : obj.getOrders())
  {
    os << it.first;
    os << " ";
    os << (size_t) it.second;
    os << " ";
  }
  os << (size_t) obj.getStatus().size();
  os << " ";
  for (auto & it : obj.getStatus())
  {
    os << (size_t) it;
    os << " ";
  }
  return os;
}

std::istream& operator>>(std::istream &os, NamedPipe::Data& obj)
{
  size_t length = 0;
  size_t sa = 0;
  std::vector<std::pair<std::string, Information>> orders;
  std::vector<IThread::Status> status;

  bool dead = false;
  os >> dead;
  obj.setDeath(dead);
  size_t processId;
  os >> processId;
  obj.setProcessId(processId);
  if (dead)
    return (os);
  os >> length;
  orders.resize(length);
  for (size_t i = 0; i < length; ++i)
  {
    os >> orders.at(i).first;
    os >> sa;
    orders.at(i).second = (Information) sa;
  }
  os >> length;
  status.resize(length);
  for (size_t i = 0; i < length; ++i)
  {
    os >> sa;
    status.at(i) = (IThread::Status) sa;
  }
  obj.setOrders(orders);
  obj.setStatus(status);
  return (os);
}

inline bool testFile (const std::string& name)
{
  return ( access( name.c_str(), F_OK ) != -1 );
}

NamedPipe::NamedPipe(const std::string &name) : _name(name), _filename("/tmp/plazza_" + name)
{
  if (!testFile(_filename))
    mkfifo(_filename.c_str(), 0666);
}

bool		NamedPipe::readContent(NamedPipe::Data &data) const
{
  std::ifstream file(_filename, std::ifstream::binary);

  if (file.is_open())
  {
    file >> data;
    file.close();
  }
  return (true);
}

void    NamedPipe::destroy()
{
  unlink(_filename.c_str());
}

bool		NamedPipe::writeContent(const NamedPipe::Data &data) const
{
  std::ofstream afile(_filename, std::ifstream::binary);

  if (afile.is_open())
  {
    afile << data;
    afile.close();
  }
  return 0;
}
