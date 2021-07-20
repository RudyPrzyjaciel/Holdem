#include <iostream>
#include <map>
#include <string>

class Talia
{

    std::map<int, std::string> karty{
        {1, "Ace of Clubs",}, {2, "2 of Clubs", }, {3, "3 of Clubs"}, {4, "4 of Clubs"}

    };

public:
    void printMap();
};