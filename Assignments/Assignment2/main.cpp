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

    //std::string  text = "smelly.txt";
    //std::string  replacements = "smelly_replacements.txt";
    std::string  text = argv[1];
    std::string  replacements = argv[2];
    
    TextRedactor tr{};
    if (!tr.read_replacements(replacements))
    {
        std::cerr << "Error reading replacements from " << replacements << '\n';
        return EXIT_FAILURE;
    }

    if (std::ifstream file{text})
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