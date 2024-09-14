#include <iostream>
#include "string.h"

int main() 
{
    cppf::String str0{};    // default constructor
    cppf::String str1{"Alice"};             // from a string literal
    cppf::String str2 = std::string{"Bob"}; // from std::string
    cppf::String str3{str2};    // copy constructor
    str0 = str1;    // copy assignment operator
    
    std::cout << str0.data() << "\n"; // Alice
    std::cout << str1.data() << "\n"; // Alice
    std::cout << str2.data() << "\n"; // Bob
    std::cout << str3.data() << "\n"; // Bob

    std::cout << "Size of Alice: " << str1.size() << "\n"; // 5
    std::cout << "Is Alice empty?: " << str1.empty() << "\n"; // 0 (false)
    cppf::String str4{};
    std::cout << "Is it empty?: " << str4.empty() << "\n"; // 1 (true)
    std::cout << "Alice?: " << str1.c_str() << "\n"; // Alice
    std::cout << "Alice?: " << str1.data() << "\n"; // Alice

    std::cout << "Character at 0 and 4: " << str1.at(0) << str1.at(4) << "\n"; // Ae
    std::cout << "Character at 1 and 2: " << str1[1] << str1[2] << "\n"; // li
    
    std::cout << "Alice?: " << str1.begin() << "\n"; // Alice
    std::cout << "Alice?: " << str1.end() << "\n"; // *nothing*

    cppf::String str{"Alice"};
    str.append(" and Bob"); // str is now "Alice and Bob"

    str.append(std::string{" are"});    // str is now "Alice and Bob are"

    cppf::String another{" friends"};
    str.append(another);    // str is now "Alice and Bob are friends"
    str.append('.');    // str is now "Alice and Bob are friends."
    std::cout << str.c_str() << "\n";

    str1.clear();


    if (str1.size() == 0 && str1.empty())
    {
        std::cout << "good" << "\n";
        return 0;
    }

    return 1;
}