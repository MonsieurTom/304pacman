#pragma once

#include <string>
#include <vector>

class PacmanChecker
{
public:
    explicit PacmanChecker(const std::vector<std::string> &wordTab)
    {
        if (!checkSizes(wordTab))
	  {
            exit(84);
	  }
        if (!checkSymb(wordTab))
	  {
	     exit(84);
	  }
    }

    ~PacmanChecker() = default;

private:
    bool                                    checkSizes(const std::vector<std::string> &wordtab)
    {
        unsigned long                       size = 0;

        for (const std::string &line : wordtab)
        {
            if (!line.empty() && size != 0)
            {
                if (line.size() != size)
                    return (false);
                size = line.size();
            }
            else if (line.empty())
                return (false);
            else if (size == 0)
                size = line.size();
        }
        return (true);
    }

    bool                                    checkSymb(const std::vector<std::string> &wordTab)
    {
        bool                                foundPacman = false;
        bool                                foundGhost = false;

        for (const std::string &line : wordTab)
        {
            for (const char &c : line)
            {
                if (c == 'P')
                {
                    if (!foundPacman)
                        foundPacman = true;
                    else
                        return (false);
                }
                else if (c == 'F')
                {
                    if (!foundGhost)
                        foundGhost = true;
                    else
                        return (false);
                }
                else if (c < '0' || c > '1')
                    return (false);
            }
        }
        return (true);
    }
};
