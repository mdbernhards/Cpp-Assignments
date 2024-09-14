#include "String.h"

namespace cppf 
{
    String::String() : String("") {}

    String::String(const std::string& str) : String(str.c_str()) {}

    String::String(const String& other) : String(other.storage_) {}

    String::String(const char* str) :
        length_{ strlen(str) },
        storage_{new char[length_ + 1]}
    {
        std::copy(str, str+length_, storage_);
    }

    String::~String() 
    {
        delete[] storage_;
    }

    String& String::operator=(const String& str)
    {
        auto temp  = new char[str.length_ + 1];
        delete[] storage_;
        length_ = str.length_;
        storage_ = temp;
        std::copy(str.storage_, str.storage_+length_, storage_);
        return *this;
    }

    size_t String::size() const
    {
        return length_;
    }

    bool String::empty() const
    {
        return length_ == 0;
    }

    const char* String::c_str() const
    {
        return storage_;
    }

    char* String::data() 
    {
        return storage_;
    }

    char String::at(size_t index) const
    {
        return storage_[index];
    }

    char& String::operator[](size_t index)
    {
        return storage_[index];
    }

    char* String::begin()
    {
        return storage_;
    }

    char* String::end()
    {
        return storage_ + length_;
    }

    void String::append(const std::string& str)
    {
        append(str.c_str());
    }

    void String::append(const cppf::String& str)
    {
        append(str.c_str());
    }

    void String::append(const char* str)
    {
        size_t strLenght = strlen(str);

        char* tempChar = new char[length_ + strLenght + 1];

        strcpy(tempChar, storage_);
        strcpy(tempChar + length_, str);

        delete[] storage_;

        storage_ = tempChar;
        length_ += strLenght;
    }

    void String::append(char c)
    {
        char temp[2] = {c};
        append(temp);
    }

    void String::clear()
    {
        storage_[0] = 0;
        length_ = 0;
    }
}
