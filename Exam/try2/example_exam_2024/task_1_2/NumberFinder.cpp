#include "NumberFinder.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <fstream>

namespace exam
{
    NumberFinder::NumberFinder(bool unique, bool sorted) : unique_(unique), sorted_(sorted) { }

    std::vector<long> NumberFinder::numbers() const
    {
        return numbers_;
    }

    bool NumberFinder::find(std::string fileName)
    {
        bool numberFound = false;

        auto ifsteam = std::ifstream{fileName};
        std::string word;
        while (ifsteam >> word)
        {
            if (word.find_first_not_of("0987654321") == std::string::npos)
            {
                numberFound = true;
                set(std::stoi(word));
            }
        }

        if (sorted_)
        {
            sort();
        }

        return numberFound;
    }

    void NumberFinder::set(int number)
    {
        bool copyFound = false;

        if(unique_)
        {
            auto size = numbers_.size();
            if(size > 0)
            {
                for (size_t i = 0; i < size; i++)
                {
                    if (numbers_[i] == number)
                    {
                        copyFound = true;
                    }
                }
            }
        }

        if (!copyFound)
        {
            numbers_.push_back(number);
        }
    }
    
    void NumberFinder::sort()
    {
        std::sort(numbers_.begin(), numbers_.end());
    }
}