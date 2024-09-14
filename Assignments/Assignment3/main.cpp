#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "rational_calc.h"

int main(int argc, char* argv[])
{
    std::string fileName = "smelly.txt";
    fileName = argv[1];

    bool success = process(fileName);

    if (!success)
    {
        std::cerr << "Error: Can't open file\n";
    }
}