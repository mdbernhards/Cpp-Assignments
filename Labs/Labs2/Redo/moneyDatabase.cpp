#include <string>

#include "moneyDatabase.h"

void MoneyDatabase::add(Deposit deposit)
{
    this->deposits_.at(this->size_) = deposit;
    this->size_++;
}

int MoneyDatabase::size()
{
    return this->size_;
}

Deposit MoneyDatabase::get(int index)
{
    return this->deposits_.at(index);
}

double MoneyDatabase::total_of(std::string currency_code)
{
    int sum;
    for (int i = 0; i < this->size_; i++)
    {
        if(this->deposits_.at(i).currency == currency_code)
        {
            sum+= this->deposits_.at(i).amount;
        }
    }
    return sum;
}