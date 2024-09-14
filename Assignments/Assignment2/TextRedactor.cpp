//
// Created by marti on 06/03/2024.
//

#include "TextRedactor.h"

std::string TextRedactor::redact(std::string text) const
{
    text = redact_replacements(text);
    text = redact_dates(text);
    text = redact_numbers(text);
    return text;
}

std::string TextRedactor::redact_replacements(std::string text) const
{
    for (auto i=0; i < replacements_.size(); ++i)
    {
        auto key = replacements_.key(i);
        auto pos = text.find(key);
        auto replacement = replacements_.get(key);
        while (pos != std::string::npos)
        {
            text.replace(pos, key.length(), replacement);
            pos = text.find(key);
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
            replacements_.add(line.substr(0, index-1),line.substr(index+2, line.length()));
        }

        file.close();
    }

    return true;
}

std::string redact_specific_date_format(std::string text, std::string format)
{
    auto pos = text.find(format);
    while (pos != std::string::npos)
    {
        text.replace(pos, format.length(), "DATE_HERE");
        pos = text.find(format);
    }

    return text;
}

std::string TextRedactor::redact_dates(std::string text) const
{
    int startPos = -1, dateLenght = 0;

    for (int i = 0; i < text.length(); ++i)
    {
        if (isdigit(text[i]) || ((text[i] == '/' || text[i] == '-') && startPos != -1))
        {
            if (startPos == -1)
            {
                startPos = i;
            }

            dateLenght++;
        } 
        else
        {
            if (dateLenght == 8 || dateLenght == 10)
            {
                if(((text[startPos+4] == text[startPos+7]) && (text[startPos+4] == '-' || text[startPos+4] == '/')) || 
                   ((text[startPos+2] == text[startPos+5]) && (text[startPos+2] == '-' || text[startPos+2] == '/')))
                {
                    text.replace(startPos, dateLenght, "DATE_HERE");
                }
            }
            
            startPos = -1;
            dateLenght = 0; 
        }
    }

    return text;
}

// redacts numbers
std::string TextRedactor::redact_numbers(std::string text) const
{
    double number;
    while (!(iss.eof())) {
        iss >> number;
        if (!iss.fail()) {
            // go it
        } else {
            //iss.clear();
            std::string word;
            iss >> word;
        }

    }


    int startPos = -1, numberLenght = 0;

    for (int i = 0; i < text.length(); ++i)
    {
        if (isdigit(text[i]) || (text[i] == '.' && startPos != -1))
        {
            if (startPos == -1)
            {
                startPos = i;
            }

            numberLenght++;
        }
        else if (startPos != -1)
        {
            text.replace(startPos, numberLenght, "XXX");
            startPos = -1;
            numberLenght = 0;
        }

    }

    return text;
}