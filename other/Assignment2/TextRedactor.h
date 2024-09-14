//
// Created by marti on 06/03/2024.
//

#ifndef ASSIGNMENT2_TEXTREDACTOR_H
#define ASSIGNMENT2_TEXTREDACTOR_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Dictionary.h"

struct TextRedactor
{
    /// Reads the replacements from the input file and stores them in the replacements_ dictionary.
    bool read_replacements(std::string file_name);

    // (optional) redacts dates
    std::string redact_dates(std::string text) const;

    // redacts numbers
    std::string redact_numbers(std::string text) const;

    // redacts replacements
    std::string redact_replacements(std::string text) const;

    // redacts all
    std::string redact(std::string text) const;

    Dictionary replacements_{};
};



#endif //ASSIGNMENT2_TEXTREDACTOR_H
