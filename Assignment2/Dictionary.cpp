//
// Created by marti on 06/03/2024.
//

#include "Dictionary.h"


void Dictionary::add(std::string key, std::string value)
{
    bool containsKey = false;

    for (int i = 0; i < this->size_; ++i)
    {
        if (this->pairs_[i].key == key)
        {
            containsKey = true;
        }
    }

    if(!containsKey && this->size_ <= this->capacity_)
    {
        this->pairs_.at(this->size_).key = key;
        this->pairs_.at(this->size_).value = value;
        this->size_++;
    }
}

bool Dictionary::contains(std::string key)
{
    for (int i = 0; i < this->size_; ++i) {
        if(this->pairs_[i].key == key)
        {
            return true;
        }
    }

    return false;
}

std::string Dictionary::get(std::string key)
{
    for (int i = 0; i < this->size_; ++i) {
        if(this->pairs_[i].key == key)
        {
            return this->pairs_[i].value;
        }
    }

    return "";
}

int Dictionary::size() const {
    return this->size_;
}

std::string Dictionary::key(int index) const {
    return this->pairs_[index].key;
}