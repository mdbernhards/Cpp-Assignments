#include <sstream>
#include <string>
#include <fstream>
#include <ostream>

#include "options.h"

/* Constructors */
Options::Options(int argc, char * argv[])
{
    parse(argc, argv);
}

Options::Options() { }

/* Accessors 
    All accessors return a value that tells whether a specific option was requested by the user
*/
bool Options::lines() const
{
    return lines_;
}

bool Options::words() const
{
    return words_;
}

bool Options::characters() const
{
    return characters_;
}

bool Options::bytes() const
{
    return bytes_;
}

bool Options::longest_line() const
{
    return longest_line_;
}

bool Options::help() const
{
    return help_;
}

bool Options::version() const
{
    return version_;
}

/// Contains a vector with file names to process
const std::vector<std::string>& Options::file_names() const
{
    return file_names_;
}

/* Modifiers */

// Parses command-line arguments and replaces the the current values
// of file names with new, parsed values
void Options::parse(int argc, char * argv[])
{
    for (auto i{1}; i < argc; ++i)
    {
        bool validArgument = true;
        std::string argument{argv[i]};

        if (argument.starts_with("--"))
        {
            validArgument = parseLongArguments(argument);
        }
        else if (argument.find("-") != std::string::npos && argument.find('-', 1) == std::string::npos)
        {
            validArgument = parseShortArguments(argument);
        }
        else if (argument.find(".") != std::string::npos && !namesFromFile_)
        {
            file_names_.push_back(argument);
        }
        else
        {
            validArgument = false;
        }

        if (!validArgument)
        {
            throw std::invalid_argument("wc: invalid option passed: " + argument + "\nTry `wc --help` for more information.\n");
        }
    }
}

bool Options::parseLongArguments(std::string argument)
{
    std::string subString = argument.substr(2, argument.length() - 2);

    if (subString == "bytes")
    {
        bytes_ = true;
    }
    else if (subString == "chars")
    {
        characters_ = true;
    }
    else if (subString == "lines")
    {
        lines_ = true;
    }
    else if (subString.substr(0, 12) == "files0-from=")
    {
        std::string fileName = argument.substr(13, subString.length() - 13), line;
        std::ifstream file{fileName};
        int index;

        if(!file)
        {
            std::cout << "No file found" << std::endl;
        }

        if (file.is_open())
        {
            file_names_.clear();
            while (getline(file, line))
            {
                if(line.find(".") != std::string::npos)
                {  
                    file_names_.push_back(line);
                }
            }

            namesFromFile_ = true;
        }
            file.close();
    }
    else if (subString == "max-line-length")
    {
        longest_line_ = true;
    }
    else if (subString == "words")
    {
        words_ = true;
    }
    else if (subString == "help")
    {
        help_ = true;
    }
    else if (subString == "version")
    {
        version_ = true;
    }
    else if (subString == "verbose")
    {
        verbose_ = true;
    }
    else 
    {
        return false;
    }

    return true;
}

bool Options::parseShortArguments(std::string argument)
{
    std::string subString = argument.substr(1, argument.length() - 1);
    int foundArgCount = 0;

    if (subString.find('c') != std::string::npos)
    {
        bytes_ = true;
        foundArgCount++;
    }

    if (subString.find('m') != std::string::npos)
    {
        characters_ = true;
        foundArgCount++;
    }

    if (subString.find('l') != std::string::npos)
    {
        lines_ = true;
        foundArgCount++;
    }

    if (subString.find('L') != std::string::npos)
    {
        longest_line_ = true;
        foundArgCount++;
    }

    if (subString.find('w') != std::string::npos)
    {
        words_ = true;
        foundArgCount++;
    }

    if (foundArgCount != subString.length())
    {
        return false;
    }

    return true;
}

/* Debug / helper functions */
bool Options::Options::verbose() const
{
    return verbose_;
}

void Options::print(std::ostream& out) const
{
    out << *this;
}