//
// Created by marti on 06/03/2024.
//
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "complex.h"

Complex::Complex(std::string line)
{
    std::string temp;
    std::istringstream iss{ line };
    iss >> temp;
    real_ = std::stod(temp);
    iss >> temp;
    iss >> temp;
    imag_ = std::stod(temp);
}

Complex::Complex()
{
    real_ = 0;
    imag_ = 0;
}

Complex::Complex(double real, double imag)
{
    real_ = real;
    imag_ = imag;
}

Complex Complex::add(Complex other)
{
    return (Complex){this->real_ + other.real_, this->imag_ + other.imag_};
}

Complex Complex::sub(Complex other)
{
    return (Complex){this->real_ - other.real_, this->imag_ - other.imag_};
}

Complex Complex::mul(Complex other)
{
    return (Complex){this->real_ * other.real_ - this->imag_ * other.imag_, this->real_ * other.imag_ + this->imag_ * other.real_};
}

Complex Complex::div(Complex other)
{
    double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
    return (Complex){(this->real_ * other.real_ + this->imag_ * other.imag_) / denominator, (this->imag_ * other.real_ - this->real_ * other.imag_) / denominator};
}

double Complex::modulus()
{
    return sqrt(this->real_ * this->real_ + this->imag_ * this->imag_);
}

double Complex::argument()
{
    return atan2(this->imag_, this->real_);
}

double Complex::real() const
{
    return this->real_;
}

double Complex::imag() const
{
    return this->imag_;
}