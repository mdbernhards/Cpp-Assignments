#include <iostream>
#include <cstring>

namespace cppf 
{
    class String
    {
    public:
        String();
        String(const char* chr);
        String(const std::string& str);
        String(const String& str);

        String& operator=(const String& str);

        ~String();
        
        size_t size() const;
        bool empty() const;
        const char* c_str() const;
        char* data();

        char at(size_t index) const;
        char& operator[](size_t index);
        char* begin();
        char* end();

        void append(const std::string& str);
        void append(const cppf::String& str);
        void append(const char* str);
        void append(char c);

        void clear();

    private:
        size_t length_ = 0;
        char* storage_;
    };
}