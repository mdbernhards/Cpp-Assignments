#include "rational.h"

Rational::Rational() : Rational(0, 1)
{
    //set(0, 1);
}

Rational::Rational(int num, int den)
{
    set(num, den);
}

Rational::Rational(int num) : Rational(num, 1)
{
    //set(num, 1);
}

Rational::Rational(std::string s)
{
    str(s);
}

int Rational::num() const
{
    return this->num_;
}

int Rational::den() const
{
    return this->den_;
}

std::string Rational::str() const
{
    return std::to_string(this->num_) + "/" + std::to_string(this->den_);
}

bool Rational::is_pos() const
{
    return (this->num_ / this->den_) > 0;
}

bool Rational::is_neg() const
{
    return (this->num_ / this->den_) < 0;
}

bool Rational::is_inf() const
{
    return this->den_ == 0;
}

bool Rational::is_nan() const
{
    return this->den_ == 0 && this->num_ == 0;
}

int get_gcd(int one, int two)
{
    int smallestNum;

    if (one < 0)
    {
        one *= -1;
    }

    if (two < 0)
    {
        two *= -1;
    }

    if (one > two)
    {
        smallestNum = two;
    }
    else
    {
        smallestNum = one;
    }
    while (smallestNum > 0) 
    { 
        if (one % smallestNum == 0 && two % smallestNum == 0) 
        { 
            break; 
        }

        smallestNum--; 
    } 
  
    return smallestNum; 
}

void Rational::set(int num, int den)
{
    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }

    int gcd = get_gcd(num, den);

    if (gcd == 0)
    {
        this->num_ = num;
        this->den_ = den;
    }
    else
    {
        this->num_ = num / gcd;
        this->den_ = den / gcd;
    }
}

void Rational::str(std::string s)
{
    int startPosition = 0, endPosition = s.length() - 1;
    auto pos = s.find("/");

    if (!(isdigit(s[0]) || s[0] == '-'))
    {
        startPosition++;
    }
    if (!isdigit(s[s.length() - 1]))
    {
        endPosition--;
    }
    std::string subString1 = s.substr(startPosition, pos - startPosition);
    std::string subString2 = s.substr(pos + 1, endPosition - pos + 1);
    int num = std::stoi(subString1);
    int den = std::stoi(subString2);

    set(num, den);
}

    Rational Rational::add(Rational other) const
    {
        if (this->is_inf() || other.is_inf())
        {
            return Rational(1, 0);
        }

        return Rational((this->num_ * other.den()) + (this->den_ * other.num()), 
            this->den_ * other.den());
    }

    Rational Rational::sub(Rational other) const
    {
        if (other.den() == 0)
        {
            return Rational(this->num_, this->den_);
        }

        return (Rational((this->num_ * other.den()) - (this->den_ * other.num()), 
            this->den_ * other.den()));
    }
    
    Rational Rational::mul(Rational other) const
    {
        return (Rational(this->num_ * other.num(), 
            this->den_ * other.den()));
    }
    
    Rational Rational::div(Rational other) const
    {
        return (Rational(this->num_ * other.den(), 
            this->den_ * other.num()));
    }
    
    Rational Rational::pow(int n) const
    {
        if (n == 0)
        {
            return Rational(1, 1);
        }

        int num = this->num_, den = this->den_;

        for (size_t i = 1; i < n; i++)
        {
            num *= this->num_;
            den *= this->den_;
        }

        return (Rational(num, den));
    }
    
    Rational Rational::sqrt() const
    {
        double numSquareRoot = 0, denSquareRoot = 0;

        if(this->is_neg())
        {
            return Rational(0, 0);
        }

        for (size_t i = 1; i <= this->num_; i++)
        {
            if((double)(this->num_ / i) == i)
            {
                numSquareRoot = i;
            }
        }

        for (size_t i = 1; i <= this->den_; i++)
        {
            if( (double) (this->den_ / i) == i)
            {
                denSquareRoot = i;
            }
        }

        Rational temp(numSquareRoot, denSquareRoot);

        if (temp.is_neg() || temp.is_inf() || temp.is_nan() || temp.num_ == 0)
        {
            return Rational(0, 0);
        }

        return temp;
    }
