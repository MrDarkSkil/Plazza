/*
** Parser.cpp for Plazza in /Users/leohubertfroideval/Documents/Shared/C++_2016/Plazza/src
**
** Made by Leo Hubert Froideval
** Login   <leohubertfroideval@epitech.net>
**
** Started on  Wed Apr 19 12:32:15 2017 Leo Hubert Froideval
** Last update Thu Apr 20 16:49:54 2017 Leo Hubert Froideval
*/

#include "Parser.hpp"

Parser::Parser(std::string const &file, Information const &information)
{
    _file = file;
    _information = information;
}

void Parser::setFile(std::string const &file)
{
    _file = file;
}

void Parser::setInformation(Information const &information)
{
    _information = information;
}
void Parser::parseFile()
{
    std::regex rgx("");

    if (_information == Information::IP_ADDRESS)
        rgx = "(\\d{1,3}(\\.\\d{1,3}){3})";
    else if (_information == Information::EMAIL_ADDRESS)
        rgx = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
    else if (_information == Information::PHONE_NUMBER)
        rgx = "(\\d{1,3}(\\.\\d{1,3}){3})";
    std::smatch match;

    std::ifstream afile(_file, std::ios::in);
    if (afile.is_open()) {
        std::string line;
        while (std::getline(afile, line)) {
            std::istringstream iss(line);
            std::string word;
            while(iss >> word) {
                if (regex_match(word, rgx))
                    std::cout << "match: " << word << std::endl;
            }
        }
        afile.close();
    }
    else {
        throw Exception("File " + _file + " not found.\n");
    }
}
