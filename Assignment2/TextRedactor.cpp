//
// Created by marti on 06/03/2024.
//

#include "TextRedactor.h"

std::string TextRedactor::redact(std::string text) const
{
    text = redact_replacements(text);
    //text = redact_dates(text);
    text = redact_numbers(text);
    return text;
}

std::string TextRedactor::redact_replacements(std::string text) const
{
    for (auto i=0; i < replacements_.size(); ++i)
    {
        auto key = replacements_.key(i);
        auto pos = text.find(key);
        while (pos != std::string::npos)
        {
            // TODO
        }
    }
    return text;
}

/// Reads the replacements from the input file and stores them in the replacements_ dictionary.
bool TextRedactor::read_replacements(std::string file_name)
{
    std::ifstream file{file_name};

    if(!file)
    {
        std::cout << "No file found" << std::endl;
        return false;
    }

    std::string line;
    int index;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            index = line.find_first_of('|');
            replacements_.add(line.substr(0, index-1),line.substr(index+1, line.length()));
        }

        file.close();
    }

    return true;
}

// (optional) redacts dates
std::string TextRedactor::redact_dates(std::string text) const
{
 return "";
}

// redacts numbers
std::string TextRedactor::redact_numbers(std::string text) const
{
    for (int i = 0; i < text.length(); ++i) {
        if(isdigit(text[i]))
        {
            text[i] = 'X';
        }

    }
    return text;
}