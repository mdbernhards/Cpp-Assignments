#include <string>

#ifndef ASSIGNMENT5_OUTPUTFILE_H
#define ASSIGNMENT5_OUTPUTFILE_H

class OutputFile {
public:
    // constructor, opens the file with the given name
    OutputFile(const std::string& file_name);

    // default constructor, initializes the object without opening a file
    // and with an empty file name
    OutputFile();

    // destructor
    ~OutputFile();

    // opens the file with the given name, closes the previous file if it was open
    void open(const std::string& file_name);
    // closes the file
    void close();

    // writes the given value to the file if it is open
    // all those functions use std::fprintf or std::fputs

    OutputFile& operator<<(const std::string& value);
    OutputFile& operator<<(const char *value);
    OutputFile& operator<<(char value);
    OutputFile& operator<<(int number);
    OutputFile& operator<<(double number);

    // writes "true" or "false" to the file
    OutputFile& operator<<(bool value);

    //gets
    bool is_open() const;
    bool error() const;
    bool eof() const;
    std::string name() const;
    size_t getLines() const;
    size_t getCharacters() const;

private:
    void countLinesAndCharacter(const std::string& value);

    std::string fileName;
    std::FILE *file = nullptr;
    size_t lineCount = 0;
    size_t characterCount = 0;
};

#endif // ASSIGNMENT5_OUTPUTFILE_H