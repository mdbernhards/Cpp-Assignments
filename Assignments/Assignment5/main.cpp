#include <iostream>
#include "outputFile.h"

int main(int, char**){
    std::cout << "Hello, from Assignment5!\n";
    /*
    OutputFile outPut{"output.txt"};

    const char *temp = " More Eggs please \n";

    outPut << "egg" << 'n' << 'o' << temp << 12 << " Eggs please\n";
    outPut << "That will be " << 12.55 << " Euro please!\n";
    outPut << "Thats \n" << true;

    std::cout << "Line Count: " << outPut.getLines() << "\n";
    std::cout << "Char Count: " << outPut.getCharacters() << "\n";
    */
    OutputFile fw{"test.txt"};
    fw << "Alice has " << 3 << " rats.\n";

    // Optional
    std::cout << "Written " << fw.getCharacters() << " chars and " 
        << fw.getLines() << " lines.\n";

    fw << "True of false: does Alice like rats?\n"
    << "Answer: " << true << "\n";

    // Optional
    std::cout << "Written " << fw.getCharacters() << " chars and " 
        << fw.getLines() << " lines.\n";

}
