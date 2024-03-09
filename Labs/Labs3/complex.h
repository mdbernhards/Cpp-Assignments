//
// Created by marti on 06/03/2024.
//
#include <stdio.h>
#include <ostream>
#include <math.h>

#ifndef LABS3_COMPLEX_H
#define LABS3_COMPLEX_H


class Complex {
public:
    Complex(double real, double imag);
    Complex(std::string number);
    Complex();
    double real() const;
    double imag() const;
    Complex add(Complex other);
    Complex sub(Complex other);
    Complex mul(Complex other);
    Complex div(Complex other);
    double modulus();
    double argument();
private:
    double real_;
    double imag_;
};

inline std::ostream& operator<<(std::ostream& out, Complex const& c)
{
    return out << c.real() << (c.imag() < 0.0? "-" : "+") << std::abs(c.imag()) << "i";
}

#endif //LABS3_COMPLEX_H
