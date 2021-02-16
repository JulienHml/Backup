#include "File.hpp"

#include <iostream>
#include <stdexcept>


namespace julienhml
{
    File::File(const std::string name) : name(name)
    {
        this->file.open(this->name);
        if (this->file.is_open() == false) {
            throw std::runtime_error("The file \"" + this->name + "\" seems nonexistent or unreadable");
        }
    }


    const std::vector<std::string> File::getListOfPaths()
    {
        std::vector<std::string> listOfPaths;
        std::string line;

        while (getline(this->file, line))
        {
            // The line isn't a commentary or isn't empty
            if (line.substr(0, 2) != "//" && !line.empty())
                listOfPaths.push_back(line);
        }

        return listOfPaths;
    }


    File::~File()
    {
        this->file.close();
    }
}