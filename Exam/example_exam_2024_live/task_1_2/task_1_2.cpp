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
    try {
        auto options = exam::parse_options(argc, argv);

        std::cout << options << '\n';

        if (options.help) {
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

    }
    catch(std::invalid_argument& ia)
    {
        std::cout << ia.what() << '\n';
        std::cout << help << '\n';
    }

    return EXIT_SUCCESS;
}