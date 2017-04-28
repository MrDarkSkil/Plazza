/*
** Parser.cpp for Plazza in /Users/leohubertfroideval/Documents/Shared/C++_2016/Plazza/src
**
** Made by Leo Hubert Froideval
** Login   <leohubertfroideval@epitech.net>
**
** Started on  Wed Apr 19 12:32:15 2017 Leo Hubert Froideval
** Last update Fri Apr 28 13:56:52 2017 Leo Hubert Froideval
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
    sem_t *sem = sem_open("/tmp", 0);
    std::regex rgx("");
    Crypted cr;
    std::string file;
    std::string word;
    std::string line;
    std::smatch match;
    bool found = false;
    int caesar = 0;
    short xxor = 0;
    std::string path;
    bool result = findFile(_file, ".", path);
    std::ifstream afile(path, std::ios::in);

    if (_information == Information::IP_ADDRESS)
        rgx = "(\\d{1,3}(\\.\\d{1,3}){3})";
    else if (_information == Information::EMAIL_ADDRESS)
        rgx = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
    else if (_information == Information::PHONE_NUMBER)
        rgx = "[[:digit:]]{2}(\\ )?[[:digit:]]{2}(\\ )?[[:digit:]]{2}(\\ )?[[:digit:]]{2}(\\ )?[[:digit:]]{2}";

    if (afile.is_open() && result == true)
    {
        while (found == false)
        {
            while (std::getline(afile, line))
            {
                if (caesar < 255 && caesar != 0)
                   line = cr.decryptCaesar(file, caesar);
                if (xxor < 32767 && caesar == 255 && xxor != 0)
                   line = cr.decryptXor(file, xxor);
                while (regex_search(line, match, rgx))
                {
                    sem_wait(sem);
                    std::cout << match[0] << std::endl;
                    line = match.suffix().str();
                    found = true;
                    sem_post(sem);
                }
            }
            if (found == false)
            {
                if (caesar < 255)
                    caesar++;
                if (xxor < 32767 && caesar == 255)
                    xxor++;
                if (xxor >= 32767 && caesar >= 255)
                   return;
                afile.clear();
                afile.seekg(0, std::ios::beg);
            }
        }
        afile.close();
    }
    else
    {
        std::cerr << "File " << _file << " not found." << std::endl;
    }
}
