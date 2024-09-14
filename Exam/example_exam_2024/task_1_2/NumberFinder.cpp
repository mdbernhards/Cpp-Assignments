#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "NumberFinder.h"

namespace exam
{
    NumberFinder::NumberFinder(bool unique, bool sorted)
    {
        unique_ = unique;
        sorted_ = sorted;
    }

    std::vector<long> NumberFinder::numbers() const
    {
        return numbers_;
    }

    bool NumberFinder::find(std::string file_name)
    {
        std::ifstream stream{file_name};
        bool foundNumber = false;
        std::string line;
        while (getline(stream, line))
        {
            auto pos = line.find_first_of("0123456789");

            size_t endPos = pos;

            for (size_t i = pos; i < line.length() - 1; i++)
            {
                if (isdigit(line[i]) || line[i] == '.')
                {
                    endPos = i;
                }
                else
                {
                    auto subStr = line.substr(pos, endPos - pos + 1);
                    auto num = std::stol(subStr);
                    if (subStr.find_first_not_of("0987654321") == std::string::npos)
                    {
                        bool isunique = false;
                        if (unique_)
                        {
                            int cnt = count(numbers_.begin(), numbers_.end(), num); 
                            
                            if (cnt < 1)
                            {
                                isunique = true;
                            }
                        }

                        if((isunique && unique_) || (!unique_))
                        {

                            numbers_.push_back(num);
                            foundNumber = true;
                        }
                    }

                    i += endPos - pos;
                }
            }
        }

        if (sorted_)
        {
            std::sort(numbers_.begin(), numbers_.end());
        }

        return foundNumber;
    }
}

