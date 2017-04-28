/*
** Parser.hpp for Plazza in /Users/leohubertfroideval/Documents/Shared/C++_2016/Plazza/includes
**
** Made by Leo Hubert Froideval
** Login   <leohubertfroideval@epitech.net>
**
** Started on  Wed Apr 19 12:23:03 2017 Leo Hubert Froideval
** Last update Fri Apr 28 13:08:40 2017 gastal_r
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <cstring>
#include <semaphore.h>

#include "Exception.hpp"
#include "Orders.hpp"

class Parser
{
public:
    Parser(std::string const &, Information const &);
    void setFile(std::string const &);
    void setInformation(Information const &);
    void parseFile();

    ~Parser() = default;
    Parser(const Parser& other) = default;
    Parser(Parser&& other) = default;
    Parser& operator=(const Parser& other) = default;
    Parser& operator=(Parser&& other) = default;
private:
    std::string _file;
    Information _information;
};

#endif /* !PARSER_HPP_ */
