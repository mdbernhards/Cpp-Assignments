#ifndef ASSIGNMENT7_RATIONAL_H
#define ASSIGNMENT7_RATIONAL_H

#include <iostream>

class Rational {
public:
    Rational();
    Rational(int numerator, int denominator);
    Rational(int numerator);
    Rational(const std::string& str);

    int num() const;
    int den() const;

    std::string str() const;
    void str(const std::string s);

    bool is_pos() const;
    bool is_neg() const;
    bool is_inf() const;
    bool is_nan() const;

    Rational &operator+=(const Rational &other);
    Rational &operator-=(const Rational &other);
    Rational &operator*=(const Rational &other);
    Rational &operator/=(const Rational &other);

    Rational operator-() const;
    Rational operator+() const;

    bool operator==(const Rational &rhs); //const
    bool operator!=(const Rational &rhs);
    bool operator>(const Rational &rhs);
    bool operator<(const Rational &rhs);
    bool operator>=(const Rational &rhs);
    bool operator<=(const Rational &rhs);

private:
    int num_;
    int den_;
    void Simplify();
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& os, const Rational& other);

#endif  //ASSIGNMENT7_RATIONAL_H