#include "IntVector.h"

#include <algorithm>
#include <stdexcept>

namespace exam
{
    static const std::size_t INITIAL_CAPACITY = 16;

    IntVector::IntVector()
        : size_{0}, capacity_{INITIAL_CAPACITY}, data_{new long[capacity_]}
    {
    }
  
    void IntVector::push_back(long value)
    {
        if (ensureCapacity)
        {
            data_[size_++] = value;
        }
        else
        {
           throw std::runtime_error("IntVector::push_back: capacity exceeded");
        }
    }

    std::size_t IntVector::size() const
    {
        return size_;
    }

    long IntVector::operator[](std::size_t index) const
    {
        return data_[index];
    }

    long* IntVector::begin()
    {
        return data_;
    }

    long* IntVector::end()
    {
        return data_ + size_;
    }

    const long* IntVector::begin() const
    {
        return data_;
    }

    const long* IntVector::end() const
    {
        return data_ + size_;
    }

    void IntVector::sort()
    {
        std::sort(begin(), end());
    }

    void IntVector::unique()
    {
        // an ugly quadratic, manual implementation of unique. but hey, it's at least stable!
        auto current = begin();
        auto last = end();
        while (current != last)
        {
            auto next = current + 1;
            while (next != last)
            {
                if (*current == *next)
                {
                    std::copy(next + 1, last, next);
                    --last;
                }
                else
                {
                    ++next;
                }
            }
            ++current;
        }
        size_ = last - begin();
    }

    bool IntVector::ensureCapacity(int size)
    {
        if (size > capacity_)
        {
            long *tempdata = new long[size + 1];
            std::copy(data_, data_ + size_, tempdata);
            delete[] data_;
            data_ = tempdata;
            capacity_ = size + 1;
        }

        return true;
    }
}