/*
** Exception.hpp for cpp_nanotekspice
**
** Made by	Full Name
** Login	gastal_r
**
** Started on	Thu Mar 02 17:13:18 2017 Full Name
** Last update Wed Apr 19 13:10:24 2017 Leo Hubert Froideval
*/

#ifndef     _EXCEPTION_HPP_
#define     _EXCEPTION_HPP_

#include    <exception>
#include    <string>


class Exception : public std::exception
{
 public:
    explicit Exception(const std::string &message) : _message(message) {;}
    Exception(const std::string &message, const std::string &var) : _message(message)
    {
      _message += var;
    }
    virtual ~Exception() throw() {};
    virtual const char* what() const throw() { return(_message.c_str());}

 private:
    std::string   _message;
};

#endif /* !_EXCEPTION_HPP_ */
