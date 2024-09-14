#include <sstream>
#include "Rational.h"

Rational::Rational( ) : Rational(0, 1) { }

Rational::Rational(int numerator, int denominator) : num_(numerator), den_(denominator)
{
    Simplify();
}

Rational::Rational(int numerator) : Rational(numerator, 1) { }

Rational::Rational(const std::string& string) : Rational(0, 1)
{
    str(string);
}

int Rational::num() const
{
    return num_;
}

int Rational::den() const
{
    return den_;
}

std::string Rational::str() const
{
    std::stringstream ss;
    ss << num_ << '/' << den_;
    return ss.str();
}

void Rational::str(const std::string s)
{
    if (s == "")
    {
        return;
    }

    auto middleIndex = s.find('/');

    num_ = std::stoi(s.substr(0, middleIndex));
    den_ = std::stoi(s.substr(middleIndex + 1, s.length() - 1));
    Simplify();
}

bool Rational::is_pos() const
{
    return num_ * den_ > 0;
}

bool Rational::is_neg() const
{
    return num_ * den_ < 0;
}

bool Rational::is_inf() const
{
    return den_ == 0 && num_ != 0;
}

bool Rational::is_nan() const
{
    return den_ == 0 && num_ == 0;
}


Rational &Rational::operator+=(const Rational &other)
{
    num_ = num_ * other.den_ + other.num_ * den_;
    den_ = den_ * other.den_;
    Simplify();

    return *this;
}

Rational &Rational::operator-=(const Rational &other)
{
    return operator+=({-other.num_, other.den_});
}

Rational &Rational::operator*=(const Rational &other)
{
    num_ = num_ * other.num_;
    den_ = den_ * other.den_;
    Simplify();

    return *this;
}

Rational &Rational::operator/=(const Rational &other)
{
    num_ = num_ * other.den_;
    den_ = den_ * other.num_;
    Simplify();

    return *this;
}

Rational Rational::operator-() const
{
    return Rational(-num_, den_);
}

Rational Rational::operator+() const
{
    return *this;
}

bool Rational::operator==(const Rational &rhs)
{
    return num_ * rhs.den_ == rhs.num_ * den_;
}

bool Rational::operator!=(const Rational &rhs)
{
    return !(*this == rhs);
}

bool Rational::operator>(const Rational &rhs)
{
    return num_ * rhs.den_ > rhs.num_ * den_;
}

bool Rational::operator<(const Rational &rhs)
{
    return num_ * rhs.den_ < rhs.num_ * den_;
}

bool Rational::operator>=(const Rational &rhs)
{
    return !(*this < rhs);
}

bool Rational::operator<=(const Rational &rhs)
{
    return !(*this > rhs);
}

void Rational::Simplify()
{
    for (size_t i = den_; i > 0; i--)
    {
        if ((num_ % i) == 0 && (den_ % i) == 0)
        {
            num_ = num_ / i;
            den_ /= i;
            return;
        }
    }
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    return Rational{lhs} += rhs;
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    Rational temp(lhs.num(), lhs.den());
    temp -= rhs;
    return temp;
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    Rational temp(lhs.num(), lhs.den());
    temp *= rhs;
    return temp;
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    Rational temp(lhs.num(), lhs.den());
    temp /= rhs;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Rational& other)
{
    os << other.str();

    return os;
}
