#include <iostream>

#include "Rational.h"

int main(int, char**)
{
    Rational a{"45/8"};
    Rational b{3,4};

    auto r = a + b;

    r /= b;

    if (r > a/b)
    {
        std::cout << r << " is bigger than " << (a/b) << "\n";
    }

    Rational c{}, d{5};
    std::cout << "a is: " << a << " c is: " << c << " d is: " << d << "\n";
    std::cout << "a num is: " << a.num() << " den is: " << a.den() << "\n";

    if(a.is_pos() && !a.is_neg() && !a.is_nan() && !a.is_inf())
    {
        std::cout << "a is good!" << "\n";
        a += Rational(3, 3);
        std::cout << "a is  " << a << "\n";
        a *= Rational(2, 1);
        std::cout << "a is  " << a << "\n";
        a -= Rational(10, 5);
        std::cout << "a is  " << a << "\n";
        a = a + a;
        std::cout << "a is  " << a << "\n";
        b = a - a;
        std::cout << "b is  " << b << "\n";
    }

    if (a == a && a <= a && a >= a && a != c)
    {
        std::cout << "a is very good!" << "\n";
    }
}
