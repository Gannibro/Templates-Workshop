#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include "Book.h"

namespace seneca {

template<typename T, size_t Capacity>
class Collection {
    T items[Capacity];
    size_t count;

public:
    Collection() : count(0) {}

    bool add(const T& item) {
        if (count < Capacity) {
            items[count++] = item;
            return true;
        }
        return false;
    }

    size_t size() const {
        return count;
    }

    size_t capacity() const {
        return Capacity;
    }

    T getSmallestItem() const {
        return *std::min_element(items, items + count);
    }

    T getLargestItem() const {
        return *std::max_element(items, items + count);
    }

    Collection& operator+=(const T& item) {
        add(item);
        return *this;
    }

    void print(std::ostream& os) const {
        os << "[";
        for (size_t i = 0; i < count; ++i) {
            os << items[i];
            if (i != count - 1) os << ",";
        }
        os << "]";
        std::cout << std::endl;
    }
};

// Specialization for Book
template<>
class Collection<Book, 10> {
    Book items[10];
    size_t count;

public:
    Collection() : count(0) {}

    bool add(const Book& item) {
        if (count < 10) {
            items[count++] = item;
            return true;
        }
        return false;
    }

    size_t size() const {
        return count;
    }

    size_t capacity() const {
        return 10;
    }

    Book getSmallestItem() const {
        auto min_ratio = std::numeric_limits<double>::max();
        Book smallest_book;
        for (size_t i = 0; i < count; ++i) {
            double ratio = items[i].pagesToChaptersRatio();
            if (ratio < min_ratio) {
                min_ratio = ratio;
                smallest_book = items[i];
            }
        }
        return smallest_book;
    }

    Book getLargestItem() const {
        auto max_ratio = std::numeric_limits<double>::min();
        Book largest_book;
        for (size_t i = 0; i < count; ++i) {
            double ratio = items[i].pagesToChaptersRatio();
            if (ratio > max_ratio) {
                max_ratio = ratio;
                largest_book = items[i];
            }
        }
        return largest_book;
    }

    Collection& operator+=(const Book& item) {
        add(item);
        return *this;
    }

    void print(std::ostream& os) const {
        os << "[After creating collection in empty state]" << std::endl;
        os << "Book with smallest pages-to-chapters ratio (initial-default state): " << std::endl;
        os << getSmallestItem() << std::endl;
        os << "Book with largest pages-to-chapters ratio (initial-default state): " << std::endl;
        os << getLargestItem() << std::endl;
        os << "size/capacity: " << count << "/" << 10 << std::endl;
    }
};

// Explicit template instantiation
template class Collection<int, 10>;
template class Collection<double, 10>;

}

#endif // COLLECTION_H