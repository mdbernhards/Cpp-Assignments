//
// Created by marti on 06/03/2024.
//

#ifndef LABS3_COMPLEX_H
#define LABS3_COMPLEX_H

#include <stdio.h>
#include <math.h>

class Complex {
public:
    Complex add(Complex a, Complex b);
    Complex sub(Complex a, Complex b);
    Complex mul(Complex a, Complex b);
    Complex div(Complex a, Complex b);
    double modulus(Complex a);
    double argument(Complex a);
private:
    double real;
    double imag;
};

#endif //LABS3_COMPLEX_H
