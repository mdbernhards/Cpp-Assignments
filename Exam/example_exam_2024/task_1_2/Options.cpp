#include "options.h"

#include <iostream>
#include <iomanip>
#include <algorithm>


exam::Options exam::parse_options(int argc, char* argv[])
{
    Options options{false, false, false, {}};

    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);

        if (str[0] == '-')
        {
            if (str == "-help")
            {
                options.help = true;
            }
            else if (str == "-unique")
            {
                options.unique_values = true;
            }
            else if (str == "-sorted")
            {
                options.sorted = true;
            }
            else
            {
                for (size_t i = 1; i < str.length(); i++)
                {
                    if (str[i] == 'h')
                    {
                        options.help = true;
                    }
                    else if (str[i] == 'u')
                    {
                        options.unique_values = true;
                    }
                    else if (str[i] == 's')
                    {
                        options.sorted = true;
                    }
                    else
                    {
                        throw;
                    }
                }
            }
            
        }
        else if (std::find(argv[i], argv[i] + argc, '.'))
        {
            options.files.push_back(str);
        }
        else
        {
            throw;
        }
    }
    
    return options;
}

std::ostream& exam::operator<<(std::ostream& os, const exam::Options& options)
{
    os << "Options:\n";
    os << "  unique_values: " << std::boolalpha << options.unique_values << '\n';
    os << "  sorted: " << std::boolalpha << options.sorted << '\n';
    os << "  help: " << std::boolalpha << options.help << '\n';
    os << "  files:\n";
    for (const auto& file : options.files)
    {
        os << "    " << file << '\n';
    }
    return os;
}