#pragma once

#include <string>
#include <vector>
#include <fstream>

class FileReader
{
public:
    FileReader()
    {}

    ~FileReader()
    {}

    std::vector<std::string>        getFileContent(std::string fileName)
    {
        std::ifstream               file;
        std::vector<std::string>    wordTab;
        std::string                 line;

        file.open(fileName);
        if (file.is_open())
        {
            while (std::getline(file, line))
                wordTab.push_back(line);
        }
        return (wordTab);
    }
};