#ifndef INCLUDED_NUMBER_FINDER_H
#define INCLUDED_NUMBER_FINDER_H

#include <vector>
#include <string>

#include "Options.h"

namespace exam
{
    class NumberFinder
    {
    public:
        NumberFinder(bool unique, bool sorted);

        std::vector<long> numbers() const;
        bool find(std::string file_name);

    private:
        bool unique_;
        bool sorted_;
        
        std::vector<long> numbers_;
    };
}


#endif // INCLUDED_NUMBER_FINDER_H