#include <iostream>

#ifndef ASSIGNMENT4_FILECOUNTS_H
#define ASSIGNMENT4_FILECOUNTS_H

#include "options.h"

struct FileCounts
{
  std::size_t lines{};
  std::size_t words{};
  std::size_t characters{};
  std::size_t bytes{};
  std::size_t maximum_line_length{};
  std::string file_name{};

  void print(std::ostream& out, Options const& opt) const;
  void add(FileCounts& otherFileCount);
};

#endif // ASSIGNMENT4_FILECOUNTS_H