#pragma once

#include "Talia.h"
#include <algorithm>

void Talia::printMap()
{
    auto print = [](std::pair<const int, std::string>& n)
    {
        std::cout << " " << n.first << "(" << n.second << ")";
    };

    std::for_each(karty.begin(), karty.end(), print);
}