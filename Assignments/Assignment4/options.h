#include <iostream>
#include <vector>
#include <string>

#ifndef ASSIGNMENT4_OPTIONS_H
#define ASSIGNMENT4_OPTIONS_H

class Options {
public:
  /* Constructors */
  Options(int argc, char * argv[]);
  Options();  // default constructor
  
  /* Accessors 
     All accessors return a value that tells whether a specific option was requested by the user
  */
  bool lines() const;
  bool words() const;
  bool characters() const;
  bool bytes() const;
  bool longest_line() const;
  bool help() const;
  bool version() const;
  
  /// Contains a vector with file names to process
  const std::vector<std::string>& file_names() const;
  
  /* Modifiers */

  // Parses command-line arguments and replaces the the current values
  // of file names with new, parsed values
  void parse(int argc, char * argv[]);
  
  /* Debug / helper functions */
  bool verbose() const;
  void print(std::ostream& out) const;

private:
    // Arguments
    bool lines_ = false;
    bool words_ = false;
    bool characters_ = false;
    bool bytes_ = false;
    bool longest_line_ = false;
    bool help_ = false;
    bool version_ = false;
    bool namesFromFile_ = false;
    std::vector<std::string> file_names_;

    // Helper option
    bool verbose_ = false;

    // Parsing specific argument types
    bool parseLongArguments(std::string argument);
    bool parseShortArguments(std::string argument);
};

// you may use this function to print directly to a stream
inline std::ostream& operator<<(std::ostream& out, const Options& opt)
{
  out << "Options:"
      << "\n\tlines: "        << std::boolalpha << opt.lines()
      << "\n\twords: "        << std::boolalpha << opt.words()
      << "\n\tcharacters: "   << std::boolalpha << opt.characters()
      << "\n\tbytes: "        << std::boolalpha << opt.bytes()
      << "\n\tlongest_line: " << std::boolalpha << opt.longest_line()
      << "\n\thelp: "         << std::boolalpha << opt.help()
      << "\n\tversion: "      << std::boolalpha << opt.version()
      << "\n\tfiles:";

  for (const auto& fn: opt.file_names())
  {  
     out << "\n\t * " << fn;
  }
  out << "\n";
  
  return out;
}

#endif // ASSIGNMENT4_OPTIONS_H