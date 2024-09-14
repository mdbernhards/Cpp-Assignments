#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <locale>
#include <string>

#include "counter.h"

Counter::Counter(const Options& opts)
{
    lines_ = opts.lines();
    words_ = opts.words();
    characters_ = opts.characters();
    bytes_ = opts.bytes();
    longest_line_ = opts.longest_line();
}

FileCounts Counter::process(const std::string& file_name)
{
    std::ifstream file{file_name};

    if (!file.is_open())
    {
        throw std::invalid_argument("wc: invalid file name passed: " + file_name + "\nTry `wc --help` for more information.\n");
    }

    FileCounts fileCounts{};
    std::string line;

    fileCounts.file_name = file_name;

    while (getline(file,line))
    {
        if(lines_)
        {
            fileCounts.lines++;
        }

        if(words_)
        {
            fileCounts.words += countWords(line);
        }

        if (characters_ || longest_line_)
        {
            size_t charCount  = countCharacters(line);

            if (characters_)
            {
            fileCounts.characters += charCount;

            }

            if (longest_line_ && fileCounts.maximum_line_length < charCount)
            {
                fileCounts.maximum_line_length = charCount;
            }
        }
        if (bytes_)
        {
            fileCounts.bytes += countBytes(line);
        }
    }

    file.close();

    return fileCounts;
}

size_t Counter::countWords(const std::string& line) const
{
    std::string word;
    std::istringstream iss{line};
    size_t count = 0;

    while (iss >> word)
    {
        count++;
    }

    iss.clear();
    return count;
}

size_t Counter::countCharacters(const std::string& line) const
{
    size_t count = 0;

    if(line.empty())
    {
        return 0;
    }

    for (size_t i = 0; i < line.length() - 1; i++)
    {
        if (((line[i] & 0x80) == 0 || ((line[i] & 0xc0) == 0xc0)))
        {
            ++count;
        }
    }

    return count;
}

size_t Counter::countBytes(const std::string& line) const
{
    return line.size();
}