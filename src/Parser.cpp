/*
** Parser.cpp for Plazza in /Users/leohubertfroideval/Documents/Shared/C++_2016/Plazza/src
**
** Made by Leo Hubert Froideval
** Login   <leohubertfroideval@epitech.net>
**
** Started on  Wed Apr 19 12:32:15 2017 Leo Hubert Froideval
** Last update Sun Apr 30 22:30:39 2017 gastal_r
*/

#include "Parser.hpp"
#include "Crypted.hpp"


#include <iostream>
#include <dirent.h>
#include <string.h> //TODO

static bool isUpDirecory(const char* directory)
{
        if (strcmp(directory, "..") == 0 || strcmp(directory, ".") == 0)
            return true;
        else
            return false;
}

static bool findFile(const std::string& fileName, const std::string& path, std::string& resultPath)
{
    dirent* entry;
    DIR* dir = opendir(path.c_str());

    if (dir == NULL)
        return false;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            if (fileName.compare(entry->d_name) == 0) {
                resultPath = path + "/" + entry->d_name;
                closedir(dir);
                return true;
            }
        }
    }

    rewinddir(dir);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (!isUpDirecory(entry->d_name)) {
                std::string nextDirectoryPath = path + "/" + entry->d_name;
                bool result = findFile(fileName, nextDirectoryPath, resultPath);
                if (result == true) {
                    closedir(dir);
                    return true;
                }
            }
        }
    }

    closedir(dir);
    return false;
}


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
    Crypted cr;
    std::string file;
    std::string word;
    std::string line;
    std::smatch match;
    bool found = false;
    int caesar = 0;
    int xxor = -1;
    std::string path;
    bool result = findFile(_file, ".", path);
    std::ifstream afile(path, std::ios::in);

    if (_information == Information::IP_ADDRESS)
      rgx = "(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)[.]){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)";
    else if (_information == Information::EMAIL_ADDRESS)
      rgx = "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+.[a-zA-Z]+";
    else if (_information == Information::PHONE_NUMBER)
      rgx = "0[0-9][ ]?[0-9][0-9][ ]?[0-9][0-9][ ]?[0-9][0-9][ ]?[0-9][0-9]";

    if (afile.is_open() && result == true)
    {
      while (std::getline(afile, line))
      {
        if (regex_search(line, match, rgx))
        {
          for (const auto & it : match)
          {
            if (_information == Information::EMAIL_ADDRESS && std::string(it).find(" ") != std::string::npos)
              std::cout << std::string(it).substr(0, std::string(it).find_last_of(" ")) << std::endl;
            else
              std::cout << std::string(it) << std::endl;
          }
          found = true;
        }
      }
      if (!found)
      {
        afile.seekg(0, std::ios::beg);
        found = false;
        std::string tmp(line);
        while (std::getline(afile, line))
        {
          xxor = -1;
          caesar = 0;
          while (xxor < 32767  && found == false)
          {
            if (caesar < 255)
            {
              line = cr.decryptCaesar(line, caesar);
              caesar++;
            }
            else if (xxor == -1)
            {
              line  = tmp;
              afile.clear();
              afile.seekg(0, std::ios::beg);
              xxor++;
            }
            else if (xxor < 32767)
            {
              line = cr.decryptXor(line, xxor);
              xxor++;
            }
            if (regex_search(line, match, rgx))
              found = true;
          }
          if (regex_search(line, match, rgx))
          {
            for (const auto & it : match)
            {
              if (_information == Information::EMAIL_ADDRESS && std::string(it).find(" ") != std::string::npos)
                std::cout << std::string(it).substr(0, std::string(it).find_last_of(" ")) << std::endl;
              else
                std::cout << std::string(it) << std::endl;
            }
          }
        }
      }
      afile.close();
    }
}
