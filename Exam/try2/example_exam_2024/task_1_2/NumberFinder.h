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
        bool find(std::string fileName);

    private:
        bool unique_;
        bool sorted_;
        std::vector<long> numbers_;

        void set(int number);
        void sort();
    };
}


#endif // INCLUDED_NUMBER_FINDER_H