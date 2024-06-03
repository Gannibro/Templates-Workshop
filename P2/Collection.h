#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <algorithm>
#include "Book.h"

namespace seneca {

template <typename T, size_t Capacity>
class Collection {
    T items[Capacity];
    size_t count{0};

    T smallestItem{};
    T largestItem{};

protected:
    T& operator[](size_t index) { return items[index]; }
    const T& operator[](size_t index) const { return items[index]; }

public:
    Collection() = default;

    bool add(const T& item) {
        if (count < Capacity) {
            items[count++] = item;
            if (count == 1 || item < smallestItem) smallestItem = item;
            if (count == 1 || item > largestItem) largestItem = item;
            return true;
        }
        return false;
    }

    size_t size() const { return count; }
    size_t capacity() const { return Capacity; }
    T getSmallestItem() const { return smallestItem; }
    T getLargestItem() const { return largestItem; }

    Collection& operator+=(const T& item) {
        add(item);
        return *this;
    }

    std::ostream& print(std::ostream& os) const {
        os << "[";
        for (size_t i = 0; i < count; ++i) {
            os << items[i];
            if (i < count - 1) os << ",";
        }
        return os << "]" << std::endl;
    }
};

// Specialization for Book and 10
template<>
class Collection<Book, 10> {
    Book items[10];
    size_t count{0};

public:
    Collection() = default;

    bool add(const Book& item) {
        if (count < 10) {
            items[count++] = item;
            return true;
        }
        return false;
    }

    size_t size() const { return count; }
    size_t capacity() const { return 10; }
    Book getSmallestItem() const { return std::min_element(items, items + count, [](const Book& a, const Book& b) { return a.pagesToChaptersRatio() < b.pagesToChaptersRatio(); })->pagesToChaptersRatio() > 0 ? *std::min_element(items, items + count, [](const Book& a, const Book& b) { return a.pagesToChaptersRatio() < b.pagesToChaptersRatio(); }) : Book(); }
    Book getLargestItem() const { return std::max_element(items, items + count, [](const Book& a, const Book& b) { return a.pagesToChaptersRatio() < b.pagesToChaptersRatio(); })->pagesToChaptersRatio() > 0 ? *std::max_element(items, items + count, [](const Book& a, const Book& b) { return a.pagesToChaptersRatio() < b.pagesToChaptersRatio(); }) : Book(); }

    Collection& operator+=(const Book& item) {
        add(item);
        return *this;
    }

    std::ostream& print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (size_t i = 0; i < count; ++i) {
            os << "| ";
            items[i].print(os);
            os << "     |\n";
        }
        return os << "| ---------------------------------------------------------------------------|";
    }
};

}

#endif // SENECA_COLLECTION_H