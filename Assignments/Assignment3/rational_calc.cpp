#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "rational_calc.h"


Rational calculate(std::string expression)
{
    std::string rat1Temp, rat2Temp, oper;
    std::string tempString;

    if (expression.substr(0, 4) == "sqrt")
    {
        tempString = expression.substr(5, expression.length() - 1);
        return Rational(tempString).sqrt();
    }

    std::istringstream iss{ expression };
    iss >> rat1Temp >> oper >> rat2Temp;
    
    if (oper == "+")
    {
        Rational temp(rat2Temp);
        return Rational(rat1Temp).add(temp);
    }
    else if (oper == "-")
    {
        return Rational(rat1Temp).sub(Rational(rat2Temp));
    }
    else if (oper == "*")
    {
        return Rational(rat1Temp).mul(Rational(rat2Temp));
    }
    else if (oper == "/")
    {
        return Rational(rat1Temp).div(Rational(rat2Temp));
    }
    else if (oper == "^")
    {
        return Rational(rat1Temp).pow(std::stoi(rat2Temp));
    }

    return (0, 0);
}

 bool process(std::string fileName)
 {
    std::string line, outputString = "", outputFileName;
    std::ifstream file{fileName};
    int index;

    if(!file)
    {
        std::cout << "No file found" << std::endl;
        return false;
    }

    if (file.is_open())
    {
        while (getline(file, line))
        {
            Rational afterCalc = calculate(line);
            auto strigg = afterCalc.str();
            outputString.append( strigg + "\n");
        }

        file.close();
        
        auto position = fileName.find('.');
        if (position == std::string::npos)
        {
            outputFileName = fileName + ".out";
        }
        else
        {
            outputFileName =  fileName.substr(0, position) + ".out";
        }

        std::ofstream outfile(outputFileName);
        if (!outfile)
        {
            std::cerr << "Error opening output file\n";
            return EXIT_FAILURE;
        }

        outfile << outputString;
        outfile.close();
    }

    return true;
 }