#ifndef INCLUDED_NUMBERS_H
#define INCLUDED_NUMBERS_H

#include <cstddef>
#include <iostream>


namespace numeric
{
    class Numbers
    {
    public:
        Numbers();
        ~Numbers();
        
        Numbers(const Numbers& other);
        Numbers& operator=(const Numbers& other);
        void swap(Numbers& other);
        Numbers clone() const;

        std::size_t size() const;

        void push_back(double value);
        double pop_back();

        double front() const;
        double& front();

        double back() const;
        double& back();

        double * begin();
        double * end();

        const double * begin() const;
        const double * end() const;
        
        double at(std::size_t index) const;
        double& at(std::size_t index);

        double operator[](std::size_t index) const;
        double& operator[](std::size_t index);

        friend std::ostream& operator<<(std::ostream& os, const Numbers& numbers);

    private:
        double * array_;
        std::size_t size_;
        std::size_t capacity_;
    };

    std::ostream& operator<<(std::ostream& os, const Numbers& numbers);
}


#endif // INCLUDED_NUMBERS_H