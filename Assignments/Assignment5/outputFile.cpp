#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#include "outputFile.h"

// constructor, opens the file with the given name
OutputFile::OutputFile(const std::string& file_name)
{
    open(file_name.c_str());
}

// default constructor, initializes the object without opening a file
// and with an empty file name
OutputFile::OutputFile() { }

// destructor
OutputFile::~OutputFile()
{
   
    close();
}

// opens the file with the given name, closes the previous file if it was open
void OutputFile::open(const std::string& file_name)
{
    if (!is_open())
    {
        fileName = file_name;
        file = std::fopen(fileName.c_str(), "w");
    }
}

// closes the file
void OutputFile::close()
{
    if (file)
        std::fclose(file);
    file = nullptr;
}

// writes the given value to the file if it is open
// all those functions use std::fprintf or std::fputs

OutputFile& OutputFile::operator<<(const std::string& value)
{
    std::fputs(value.c_str(), file);
    countLinesAndCharacter(value.c_str());

    return *this;
}

OutputFile& OutputFile::operator<<(const char *value)
{
    std::fputs(value, file);
    countLinesAndCharacter(value);

    return *this;
}

OutputFile& OutputFile::operator<<(char value)
{
    std::fputc(value, file);
    countLinesAndCharacter(&value);

    return *this;
}

OutputFile& OutputFile::operator<<(int number)
{
    const char* text = std::to_string(number).c_str();

    std::fputs(text, file);
    countLinesAndCharacter(text);

    return *this;
}

OutputFile& OutputFile::operator<<(double number)
{
    const char* text = std::to_string(number).c_str();

    std::fputs(text, file);
    countLinesAndCharacter(text);

    return *this;
}

// writes "true" or "false" to the file
OutputFile& OutputFile::operator<<(bool value)
{
    if (value)
    {
        std::fputs("true", file);
    }
    else
    {
        std::fputs("false", file);
    }

    return *this;
}

bool OutputFile::is_open() const
{
    return file != nullptr;
}

bool OutputFile::error() const
{
    return std::ferror(file);
}

bool OutputFile::eof() const
{
    return std::feof(file);
}

std::string OutputFile::name() const
{
    return fileName;
}

size_t OutputFile::getLines() const
{
    return lineCount;
}

size_t OutputFile::getCharacters() const
{
    return characterCount;
}

void OutputFile::countLinesAndCharacter(const std::string& value)
{
    characterCount += value.length();

    for (size_t i = 0; i < characterCount - 1; i++)
    {
        if (value[i] == '\n')
        {
            lineCount++;
        }
    }
}