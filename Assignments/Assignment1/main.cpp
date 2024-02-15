#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

std::string GetFileName()
{
    std::string fileName;

    std::cout << "Please enter file name: " << std::endl;
    std::cin >> fileName;

    return fileName;
}

std::ifstream GetFile(std::string fileName)
{
    std::ifstream file{fileName};
    return file;
}

bool is_empty_line(std::string line)
{
    for (int i = 0; i < line.length(); i++)
    {
        if (!(line[i] == ' ' ||  line[i] == NULL ||  line[i] == '\n'))
        {
            return false;
        }
    }
    
    return true;
}

std::string clean_line(std::string line)
{
    std::istringstream iss{ line };
    std::string word, newLine;

    while (iss >> word)
    {
        if (newLine != "" && word != "." && word != ",")
        {
            newLine += " ";
        }

        newLine += word;
    }

    return newLine;
}

std::string FormatText(std::ifstream & text) 
{
    std::string line, formatedText;

    if (text.is_open()) 
    {
        while (getline(text, line)) 
        {
            if (!is_empty_line(line)) 
            {
                if (formatedText != "")
                {
                    formatedText += "\n";
                }

                formatedText += clean_line(line);
            }

            std::cout << line << "\n";
        }

        text.close();
    }

    return formatedText;
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

std::string CreateANewFile(std::string fileName, std::string text)
{
    std::cout << "\n" << "\n" << "New text:" << "\n";
    std::cout << text << "\n";

    std::ofstream NewFile(fileName);
    NewFile << text;
    NewFile.close();
    
    return "";
}

int main()
{
    std::string fileName = GetFileName();
    std::ifstream file = GetFile(fileName);

    if(!file)
    {
        std::cout << "No file found" << std::endl;
        return 1;
    }

    std::string newFileName = GetNewFileName(fileName);
    std::string formatedText = FormatText(file);
    CreateANewFile(newFileName, formatedText);
    
    return 0;
}