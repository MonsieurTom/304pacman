#include <iostream>
#include "FileReader.h"
#include "PacmanChecker.h"
#include "Pacman.h"

int main(int ac, char **av)
{
    std::vector<std::string>    wordTab;
    FileReader                  fileReader;

    if (ac != 4)
        return (84);
    if (av[2][0] == '\0' || av[2][1] != '\0' || av[3][0] == '\0' || av[3][1] != '\0') {
		return (84);
	}
    wordTab = fileReader.getFileContent(av[1]);
    if (wordTab.empty()) {
		return (84);
	}
	PacmanChecker checker(wordTab);
	Pacman pacmanGame(wordTab);
	pacmanGame.compute();
	pacmanGame.affMap(av[2][0], av[3][0]);
    return (0);
}
