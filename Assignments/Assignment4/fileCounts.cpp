#include <string>

#include "fileCounts.h"

std::string addSpaces(int spaceAmount)
{
    std::string text = "";

    for (size_t i = 0; i < spaceAmount; i++)
    {
        text += ' ';
    }

    return text;
}

void FileCounts::print(std::ostream& out, Options const& opt) const
{
    if (opt.lines())
    {
        out << lines;
    }

    if (opt.words())
    {
        out << "\t" << words;
    }

    if (opt.characters())
    {
        out << "\t" << characters;
    }

    if (opt.bytes())
    {
        out << "\t" << bytes;
    }

    if (opt.longest_line())
    {
        out << "\t" << maximum_line_length;
    }

    out << "\t" << file_name << "\n";
}


  void FileCounts::add(FileCounts& otherFileCount)
  {
      lines += otherFileCount.lines;
      words += otherFileCount.words;
      characters += otherFileCount.characters;
      bytes += otherFileCount.bytes;
      
      if (otherFileCount.maximum_line_length > maximum_line_length)
      {
        maximum_line_length = otherFileCount.maximum_line_length;
      }
  }