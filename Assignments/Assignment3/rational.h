#include <array>
#include <string>
#include <iostream>

#ifndef ASSIGNMENT3_RATIONAL_H
#define ASSIGNMENT3_RATIONAL_H

class Rational {
public:
    /* Constructors */
    Rational();
    Rational(int num, int den);
    Rational(int num);
    Rational(std::string str);

    /* Accessors */
    int num() const;
    int den() const;
    std::string str() const;

    bool is_pos() const;
    bool is_neg() const;
    bool is_inf() const;
    bool is_nan() const;

    /* Modifiers */
    void set(int num, int den);
    void str(std::string str);
    
    Rational add(Rational other) const;
    Rational sub(Rational other) const;
    Rational mul(Rational other) const;
    Rational div(Rational other) const;
    Rational pow(int n) const;
    Rational sqrt() const;
private:
    int num_;
    int den_;
};

#endif // ASSIGNMENT3_RATIONAL_H