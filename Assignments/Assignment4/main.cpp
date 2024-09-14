#include <iostream>
#include <stdexcept>
#include "options.h"
#include "counter.h"
#include "fileCounts.h"

auto help_text = " Usage: wc [OPTION]... [FILE]...\n"
"or:  wc [OPTION]... --files0-from=F\n"
"Print newline, word, and byte counts for each FILE, and a total line if\n"
"more than one FILE is specified.  A word is a non-zero-length sequence of\n"
"characters delimited by white space.\n\n"
"With no FILE, or when FILE is -, read standard input.\n\n"
"The options below may be used to select which counts are printed, always in\n"
"the following order: newline, word, character, byte, maximum line length.\n"
"  -c, --bytes            print the byte counts\n"
"  -m, --chars            print the character counts\n"
"  -l, --lines            print the newline counts\n"
"      --files0-from=F    read input from the files specified by\n"
"                           NUL-terminated names in file F;\n"
"                           If F is - then read names from standard input\n"
"  -L, --max-line-length  print the maximum display width\n"
"  -w, --words            print the word counts\n"
"      --help     display this help and exit\n"
"      --version  output version information and exit\n\n";

int main(int argc, char * argv[])
{
    try
    {
        Options opts{argc, argv};

        if (opts.verbose())
        {
            // print parsed options
            opts.print(std::cout);
        }

        if (opts.help())
        {
            std::cout << help_text;
            return EXIT_SUCCESS;
        }

        if (opts.version())
        {
            std::cout << "wc version: 1.0" << '\n';   
            return EXIT_SUCCESS;
        }

        Counter counter(opts);

        size_t fileCount = opts.file_names().size();
        if (fileCount > 1)
        {
            FileCounts totalFileCounts;
            totalFileCounts.file_name = "total";

            for (size_t i = 0; i < fileCount; i++)
            {
                FileCounts fileCounts = counter.process(opts.file_names().at(i));
                fileCounts.print(std::cout, opts);
                totalFileCounts.add(fileCounts);
            }
            
            totalFileCounts.print(std::cout, opts);
        }
        else
        {
            FileCounts fileCounts = counter.process(opts.file_names().front());
            fileCounts.print(std::cout, opts);
        }

        return EXIT_SUCCESS;
    }
    catch(const std::invalid_argument& exc)
    {
        std::cout << exc.what() << '\n';
        return EXIT_FAILURE;
    }
}

//Options opts{argc, argv};

//char *tempArg[] = {"wc", "-l", "hello.txt", "-m", "--verbose", "world.md"};
//int tempArgCount = 6;

//char *tempArg[] = {"wc", "-clmwL", "anna_karenina.txt", "count_monte.txt", "--verbose"};
//int tempArgCount = 5; -clmwL anna_karenina.txt count_monte.txt --verbose

//char *tempArg[] = {"wc", "-lmLR", "hello.txt"};
//int tempArgCount = 3;