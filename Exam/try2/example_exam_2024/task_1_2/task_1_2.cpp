#include <iostream>
#include "Options.h"
#include "NumberFinder.h"

auto help = "Usage: task_1 [options] file1 [file2 ...]\n"
            "Options:\n"
            "  -u, --unique    Output only unique values\n"
            "  -s, --sorted    Output sorted values\n"
            "  -h, --help      Display this help message\n";


int main(int argc, char* argv[])
{
    int argCount = 4;
    char *arguments[argCount] = {"./task_1_2", "-su", "file.txt", "file2.txt"};

    auto options = exam::parse_options(argCount, arguments);

    std::cout << options;

    if (options.help)
    {
        std::cout << help;
        return EXIT_SUCCESS;;
    }

    exam::NumberFinder nf{options.unique_values, options.sorted};
    for (auto const& file : options.files)
    {
        nf.find(file);
    }

    std::cout << "The following numbers have been found:\n";
    for (auto const& number : nf.numbers())
    {
        std::cout << number << '\n';
    }
   
    return EXIT_SUCCESS;
}