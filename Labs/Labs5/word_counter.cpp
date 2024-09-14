#include "word_counter.h"


namespace counts
{
    WordCounter::WordCounter():
        entries_{new Entry[INITIAL_CAPACITY]}, // TODO 4
        count_{ 0 },
        capacity_{ INITIAL_CAPACITY }
    {}

    // TODO 5: implement the destructor
    WordCounter::~WordCounter()
    {
        delete[] entries_;
    }


    // TODO 7: implement ensure_capacity function
        /// @brief Resizes the dynamic entries_ array to the specified minimum capacity if needed
        /// @param minimum_capacity the minimum capacity of the dynamic entries_ array
        /// @return true if the capacity was increased, false if it was already sufficient
        bool WordCounter::ensure_capacity(std::size_t minimum_capacity)
        {
            if (minimum_capacity > capacity_)
            {
                Entry* new_entries = new Entry[minimum_capacity];
                std::copy(entries_, entries_ + count_, new_entries);
                delete[] entries_;
                entries_ = new_entries;
                capacity_ = minimum_capacity;

                return true;
            }

            return false;
        }

    void WordCounter::increment(const std::string& word)
    {
        if (auto entry = find(word); entry)
        {
            ++entry->count;
        }
        else
        {
            if (count_ >= capacity_)
            {
                // TODO 8: implement ensure_capacity function and call it here
                ensure_capacity(count_ + 1);
            }
            
            entries_[count_++] = { word, 1 };
        }
    }

    Entry* WordCounter::begin()
    {
        return this->entries_;
    }

    const Entry* WordCounter::begin() const
    {
        return entries_;
    }

    void WordCounter::decrement(const std::string& word)
    {
        if (auto entry = find(word); entry)
        {
            if (entry->count > 1)
            {
                --entry->count;
            }
        }
    }

    std::size_t WordCounter::get(const std::string& word) const
    {
        if (auto entry = find(word); entry)
        {
            return entry->count;
        }
        return 0;
    }


    Entry* WordCounter::end()
    {
        return begin() + count_;
    }

    const Entry* WordCounter::end() const
    {
        return begin() + count_;
    }
    

    std::size_t WordCounter::size() const
    {
        return count_;
    }
    
    Entry* WordCounter::find(const std::string& word)
    {
        for (std::size_t i = 0; i < count_; ++i)
        {
            if (entries_[i].word == word)
            {
                return &entries_[i];
            }
        }
        return nullptr;
    }
    
    const Entry* WordCounter::find(const std::string& word) const
    {
        for (std::size_t i = 0; i < count_; ++i)
        {
            if (entries_[i].word == word)
            {
                return &entries_[i];
            }
        }
        return nullptr;
    }
}