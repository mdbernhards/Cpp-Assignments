#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "TextRedactor.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <replacements_file>\n";
        return EXIT_FAILURE;
    }

    TextRedactor tr{};
    std::string  bbb= argv[0];
    std::string  ddc = argv[1];
    std::string  ddd= argv[2];
    if (!tr.read_replacements(argv[2]))
    {
        std::cerr << "Error reading replacements from " << argv[2] << '\n';
        return EXIT_FAILURE;
    }

    if (std::ifstream file{argv[1]})
    {
        std::stringstream ss;
        ss << file.rdbuf();
        auto redacted = tr.redact( ss.str() );

        std::ofstream outfile("output.txt");
        if (!outfile)
        {
            std::cerr << "Error opening output file\n";
            return EXIT_FAILURE;
        }

        outfile << redacted;
        outfile.close();
    }
}