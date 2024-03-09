#include <array>
#include <string>
#include <iostream>

#ifndef LABS2_MONEYDATABASE_H
#define LABS2_MONEYDATABASE_H
#include "deposit.h"

struct MoneyDatabase {
  int size_;
  std::array<Deposit, 100> deposits_{};

   void add(Deposit deposit);
   int size();
   Deposit get(int index);
   double total_of(std::string currency_code);
};

inline std::ostream& operator<<(std::ostream& out, struct MoneyDatabase const& db)
{
  out << "Database with size " << db.size_ << " and capacity " << db.deposits_.size() << '\n';
  out << "Deposits are:\n[\n";
  auto comma = "  ";
  for (auto i{0}; i < db.size_; ++i)
  {
    out << comma << db.deposits_[i];
    comma = ",\n  ";
  }

  return out << "\n]";
}

#endif