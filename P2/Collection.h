#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <algorithm>
#include "Book.h"

namespace seneca {

template <typename T, unsigned int C>
class Collection {
    T m_items[C];
    unsigned m_size = 0;

    static T m_smallestItem;
    static T m_largestItem;

protected:
    T& operator[](unsigned index) {
        return m_items[index];
    }

    void incrSize() {
        if (m_size < C) {
            ++m_size;
        }
    }

    void setSmallestItem(const T& item) {
        if (item < m_smallestItem || m_size == 0) {
            m_smallestItem = item;
        }
    }

    void setLargestItem(const T& item) {
        if (item > m_largestItem || m_size == 0) {
            m_largestItem = item;
        }
    }

public:
    Collection() {}

    unsigned size() const {
        return m_size;
    }

    unsigned capacity() const {
        return C;
    }

    static T getSmallestItem() {
        return m_smallestItem;
    }

    static T getLargestItem() {
        return m_largestItem;
    }

    bool operator+=(const T& item) {
        if (m_size <= C) {
            m_items[m_size] = item;
            setSmallestItem(item);
            setLargestItem(item);
            incrSize();
            return true;
        }
        return false;
    }

    void print(std::ostream& os) const;
};

// Static member definitions for Book specialization
template <>
Book Collection<Book, 10>::m_smallestItem;

template <>
Book Collection<Book, 10>::m_largestItem;

// Static member definitions for other types and capacities if needed
template <typename T, unsigned int C>
T Collection<T, C>::m_smallestItem;

template <typename T, unsigned int C>
T Collection<T, C>::m_largestItem;

template <>
void Collection<Book, 10>::print(std::ostream& os) const;

template <>
void Collection<Book, 72>::print(std::ostream& os) const;

} // namespace seneca

#endif // SENECA_COLLECTION_H
