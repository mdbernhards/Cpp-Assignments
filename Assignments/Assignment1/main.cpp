#include <iostream>
#include <string>
#include<fstream>

std::string GetFileName()
{
    std::string newString;

    std::cout << "Please enter file name: " << std::endl;
    std::cin >> newString;

    return newString;
}

std::string FindFile(std::string fileName)
{
    std::ifstream input{fileName};

    if (input) 
    {
        while (!input.eof()) 
        {

        }
    }

    return newString;
}

std::string FormatText() {
    std::string newString;

    return newString;
}

std::string GetNewFileName(std::string fileName)
{
    auto position = fileName.find('.');
    if (position == std::string::npos)
    {
        return fileName + ".clean";
    }

    return fileName.substr(0, position) + ".clean";
}

std::string CreateTheNewFile(std::string fileName)
{
    auto position = fileName.find('.');
    if (position == std::string::npos)
    {
        return fileName + ".clean";
    }

    return fileName.substr(0, position) + ".clean";
}

bool is_empty_line(std::string line)
{
    return (line == "\n");
}

std::string clean_line(std::string line)
{
    std::string::find_first_of(line, "  ")

    for (int i = 0; i < line.length(); i++)
    {
        /* code */
    }
    
}

int main()
{
    std::string fileName = GetFileName();
    FindFile();
    FormatText();
    std::string newFileName = GetNewFileName(fileName);
    CreateTheNewFile(newFileName);
}