#include "options.h"
#include <stdexcept>

namespace repeat
{

Options parse(int argc, char * argv[])
{
    Options result{};

    for (auto i{1}; i < argc; ++i)
    {
        std::string arg{ argv[i] };

        if(arg[0] == '-' && arg[1] == '-')
        {
            if (arg == "--help")
            {
                result.help = true;
            }
            else if (arg == "--capitalize")
            {
                result.capitalize = true;
            }
            else if (arg == "--newline")
            {
                result.append_newline = true;
            }

            std::string argument = arg.substr(0, 9);

            if (argument == "--repeat=")
            {
                std::string number = arg.substr(9, arg.length()-1);
                

                bool isANumber = true;
                for (size_t j = 0; j < number.length() - 1; j++)
                {
                    if (!isalnum(number[j]))
                    {
                        isANumber = false;
                    }
                }
                
                if (isANumber)
                {
                    result.repeat = std::stoi(number);
                }
            }

            argument = arg.substr(0, 8);

            if (argument == "--color=")
            {
                std::string color = arg.substr(8, arg.length()-1).c_str();
                for (auto& x : color) { 
                    x = tolower(x); 
                }

                result.color = from_string(color);
            }
        }
        else if (arg[0] == '-') 
        {
            for (size_t j = 1; j < arg.length(); j++)
            {
                if (arg[j] == 'h')
                {
                    result.help = true;
                }
                else if (arg[j] == 'C')
                {
                    result.capitalize = true;
                }
                else if (arg[j] == 'n')
                {
                    result.append_newline = true;
                }
                else if (arg[j] == 'r')
                {
                    if (arg[j + 1] == ' ' || arg[j + 1] == '=')
                    {
                        j++;
                    }

                    std::string number = "";

                    while (isalnum(arg[j+1]))
                    {
                        j++;
                        number += (arg[j]);
                    }

                    result.repeat = std::stoi(number);
                }
                else if (arg[j] == 'c')
                {
                    if (arg[j + 1] == ' ' || arg[j + 1] == '=')
                    {
                        j++;
                    }

                    if (j + 3 <= arg.length() && arg.substr(j + 1, 3) == "red")
                    {
                        result.color = Color::red;
                        j += 2;
                    }
                    else if (j + 5 <= arg.length() && arg.substr(j + 1, 5) == "green")
                    {
                        result.color = Color::green;
                        j += 4;
                    }
                    else if (j+4 <= arg.length())
                    {
                        std::string color = arg.substr(j + 1, 4);
                        if (color == "none" || color == "blue")
                        {
                            result.color = from_string(color);
                        }
                        j += 3;
                    }
                }
            }
        }
        else if (arg[0] == '\"' )
        {
            result.text = arg;
        }
    }

    return result;
}

Color from_string(const std::string& text)
{
    if (text == "red")
    {
        return Color::red;
    }
    else if (text == "green")
    {
        return Color::green;
    }
    else if (text == "blue")
    {
        return Color::blue;
    }
    else if (text == "none")
    {
        return Color::none;
    }
    else
    {
        throw std::invalid_argument{"Invalid color"};
    }
}

std::ostream& operator<<(std::ostream& out, Color color)
{
    switch(color)
    {
        case Color::red:
            return out << "red";
        case Color::green:
            return out << "green";
        case Color::blue:
            return out << "blue";
        case Color::none:
            return out << "none";
        default:
            return out << "unknown";
    }
}

std::ostream& operator<<(std::ostream& out, Options const& options)
{
    out << "Options:\n";
    out << "  help: " << std::boolalpha << options.help << '\n';
    out << "  capitalize: " << std::boolalpha << options.capitalize << '\n';
    out << "  append_newline: " << std::boolalpha << options.append_newline << '\n';
    out << "  color: " << options.color << '\n';
    out << "  repeat: " << options.repeat << '\n';
    out << "  text: " << options.text << '\n';
    return out;
}
    
} // namespace repeat
