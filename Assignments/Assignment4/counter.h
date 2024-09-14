#include <iostream>

#ifndef ASSIGNMENT4_COUNTER_H
#define ASSIGNMENT4_COUNTER_H

#include "options.h"
#include "fileCounts.h"

class Counter 
{
    public:
        Counter(const Options& opts);
        FileCounts process(const std::string& file_name);
    private:
        // Arguments
        bool lines_ = false;
        bool words_ = false;
        bool characters_ = false;
        bool bytes_ = false;
        bool longest_line_ = false;

        // Counter functions
        size_t countWords(const std::string& line) const;
        size_t countCharacters(const std::string& line) const;
        size_t countBytes(const std::string& line) const;
};

#endif // ASSIGNMENT4_COUNTER_H