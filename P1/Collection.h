#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <iomanip>
#include "Book.h"

namespace seneca {

template<typename T, size_t Capacity>
class Collection {
    T items[Capacity];
    size_t count;

public:
    Collection();

    bool add(const T& item);
    size_t size() const;
    size_t capacity() const;
    T getSmallestItem() const;
    T getLargestItem() const;
    Collection& operator+=(const T& item);
    void print(std::ostream& os) const;
};

// Specialization for Book
template<>
class Collection<Book, 10> {
    Book items[10];
    size_t count;

public:
    Collection();

    bool add(const Book& item);
    size_t size() const;
    size_t capacity() const;
    Book getSmallestItem() const;
    Book getLargestItem() const;
    Collection& operator+=(const Book& item);
    void print(std::ostream& os) const;
};

}

#include "Collection.cpp"

#endif // COLLECTION_H
