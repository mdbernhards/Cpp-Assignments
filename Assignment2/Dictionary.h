//
// Created by marti on 06/03/2024.
//
#include <array>
#include <string>
#include <iostream>

#ifndef ASSIGNMENT2_DICTIONARY_H
#define ASSIGNMENT2_DICTIONARY_H

struct KeyValue {
    std::string key;
    std::string value;
};

struct Dictionary {
    int const capacity_ = 100;
    std::array<KeyValue, 100> pairs_{};
    int size_ = 0;
    void add(std::string key, std::string value);
    bool contains(std::string key);
    std::string get(std::string key);
    int size() const;
    std::string key(int index) const;
};

#endif //ASSIGNMENT2_DICTIONARY_H
