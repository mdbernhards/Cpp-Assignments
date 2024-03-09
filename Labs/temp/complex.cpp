//
// Created by marti on 06/03/2024.
//

#include "complex.h"

Complex Complex::add(Complex a, Complex b)
{
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex Complex::sub(Complex a, Complex b)
{
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex Complex::mul(Complex a, Complex b)
{
    return (Complex){a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

Complex Complex::div(Complex a, Complex b)
{
    double denominator = b.real * b.real + b.imag * b.imag;
    return (Complex){(a.real * b.real + a.imag * b.imag) / denominator, (a.imag * b.real - a.real * b.imag) / denominator};
}

double Complex::modulus(Complex a)
{
    return sqrt(a.real * a.real + a.imag * a.imag);
}

double Complex::argument(Complex a)
{
    return atan2(a.imag, a.real);
}