#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

class Pacman
{
private:
	int 									xf;
	int 									yf;
    std::vector<std::vector<int>>   		_map;
	std::vector<std::tuple<int, int, int>>	_tuple;
	bool 									_found = false;

public:
    Pacman(const std::vector<std::string> &wordTab)
    {
        this->initBasMap(wordTab);
    }

    ~Pacman() = default;

    void        affMap(char c1, char c2)
    {
        for (const std::vector<int> &line: _map)
        {
            for (const int &nb: line)
            {
                if (nb == -1)
                    std::cout << c2;
                else if (nb == -2)
                    std::cout << c1;
                else if (nb == -3)
                    std::cout << 'P';
                else if (nb == -4)
                    std::cout << 'F';
                else
                    std::cout << nb % 10;
            }
            std::cout << std::endl;
        }
    }

public:
	void 		compute()
	{
		this->find_ghost();

		std::tuple<int, int, int> first(this->xf, this->yf, 0);
		this->_tuple.push_back(first);
		for (unsigned int i = 0; i < (_map.size() * _map[0].size()); i++)
		{
			std::vector<std::tuple<int, int, int>>	save(_tuple);
			for (auto thisTuple: save)
			{
				if (compute_case(std::get<0>(thisTuple), std::get<1>(thisTuple), std::get<2>(thisTuple), i))
					break;
			}
			if (_found)
				break;
		}
		if (!_found) {
			exit(84);
		}
	}

private:
    bool        compute_case(int x, int y, int current_prof, int max_prof)
	{
		if (y >= (int)_map.size() || x >= (int)_map[y].size() || _map[y][x] == -2 || _map[y][x] >= 0 || _found)
			return (false);
		if (current_prof > max_prof)
		{
			std::tuple<int, int, int> new_tuple(x, y, current_prof);
			_tuple.push_back(new_tuple);
			return (false);
		}
		if (_map[y][x] == -1)
			_map[y][x] = current_prof;
		else if (_map[y][x] == -3)
		{
			_found = true;
			return (true);
		}
		if (compute_case(x, y - 1, current_prof + 1, max_prof))
			return (true);
		if (compute_case(x + 1, y, current_prof + 1, max_prof))
			return (true);
		if (compute_case(x, y + 1, current_prof + 1, max_prof))
			return (true);
		if (compute_case(x - 1, y, current_prof + 1, max_prof))
			return (true);
		return (false);
    }

	void 	find_ghost()
	{
		for (int y = 0; y < (int)_map.size(); y++)
		{
			for (int x = 0; x < (int)_map[y].size(); x++)
			{
				if (_map[y][x] == -4)
				{
					this->xf = x;
					this->yf = y;
					return ;
				}
			}
		}
	}

    void    initBasMap(const std::vector<std::string> &wordTab)
    {
        std::vector<int>    line;

        // 0 = -1
        // 1 = -2
        // P = -3
        // F = -4
        for (const std::string &lineTab: wordTab)
        {
            for (const char c: lineTab)
            {
                if (c == '0')
                    line.push_back(-1);
                else if (c == '1')
                    line.push_back(-2);
                else if (c == 'P')
                    line.push_back(-3);
                else if (c == 'F')
                    line.push_back(-4);
            }
            _map.push_back(line);
            line.clear();
        }
    }
};