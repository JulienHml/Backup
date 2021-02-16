#include "Save.hpp"

#include <sys/stat.h>
#include <stdexcept>
#include <chrono>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <iomanip>


namespace julienhml
{
    Save::Save(const std::vector<std::string>& fileOfInputPaths, const std::string& fileOfOutputPath) : inputPaths(fileOfInputPaths), outputPath(fileOfOutputPath)
    {
        // Inputs
        for (auto& path : this->inputPaths)
        {
            if (!Save::isPathExist(path))
                throw std::runtime_error("The input path \"" + path + "\" is not found. Please check the file \"input_folders.txt\"");
        }

        // Output
        if (!Save::isPathExist(outputPath))
            throw std::runtime_error("The output path \"" + outputPath + "\" is not found. Please check the file \"output_folder.txt\"");
    }


    Save::~Save() { }


    void Save::start()
    {
        // New folder
        _SYSTEMTIME systemNow;
        GetLocalTime(&systemNow);
        std::vector<WORD> valueSystemNow = { systemNow.wDay, systemNow.wMonth, systemNow.wYear , systemNow.wHour , systemNow.wMinute , systemNow.wSecond , systemNow.wMilliseconds };
        std::vector<unsigned short> specifiedLength = { 2, 2, 4, 2, 2, 2, 3 };
        std::string nowFormatted;
        for (size_t i = 0; i < valueSystemNow.size(); i++)
        {
            std::stringstream ss;
            ss << std::setw(specifiedLength[i]) << std::setfill('0') << valueSystemNow[i];
            nowFormatted += ss.str() + '-';
        }
        nowFormatted.pop_back();
        std::string newDirectory = this->outputPath + "\\backup--" + nowFormatted;
        this->nameGeneratedFolder = newDirectory;
        if (!CreateDirectoryA(newDirectory.c_str(), NULL))
            throw std::runtime_error("The new directory could not be created");

        for (auto& path : this->inputPaths)
        {
            // Path of each copy
            std::size_t found = path.find_last_of("\\");
            std::string nameOfLastFolder = path.substr(found + 1);
            std::string fullPathOfTheNewFolder = newDirectory + "\\" + nameOfLastFolder;

            if (!CreateDirectoryA(fullPathOfTheNewFolder.c_str(), NULL))
                throw std::runtime_error("A new directory could not be created");

            // Command
            std::string command = "xcopy \"" + path + "\" \"" + fullPathOfTheNewFolder + "\" /D /E /C /R /H /I /K";
            system(command.c_str());
        }
    }


    const std::string Save::getNameOfGeneratedFolder()
    {
        return this->nameGeneratedFolder;
    }


    bool Save::isPathExist(const std::string& path)
    {
        struct stat buffer;
        return (stat(path.c_str(), &buffer) == 0);
    }
}