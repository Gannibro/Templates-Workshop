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
        if (m_size < C) {
            m_items[m_size] = item;
            setSmallestItem(item);
            setLargestItem(item);
            incrSize();
            return true;
        }
        return false;
    }

    void print(std::ostream& os) const {
        std::cout << std::endl;
        std::cout << "[";
        for (unsigned i = 0; i < m_size; ++i) {
            os << m_items[i];
            if (i < m_size - 1)
                std::cout << ",";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
};

// Static member declarations
template <typename T, unsigned int C>
T Collection<T, C>::m_smallestItem;

template <typename T, unsigned int C>
T Collection<T, C>::m_largestItem;

// Specialized print implementation for Book
template <>
void Collection<seneca::Book, 10>::print(std::ostream& os) const {
    os << "| --------------------------------------------------------------------------------------- |\n";
    for (unsigned i = 0; i < m_size; ++i) {
        os << "| ";
        m_items[i].print(os);
        os << "     |\n";
    }
    os << "| --------------------------------------------------------------------------------------- |";
    std::cout << std::endl;
}

template <>
void Collection<seneca::Book, 72>::print(std::ostream& os) const {
    os << "| ------------------------------------------------------------------------------------- |\n";
    for (unsigned i = 0; i < m_size; ++i) {
        os << "| ";
        m_items[i].print(os);
        os << "     |\n";
    }
    os << "| ------------------------------------------------------------------------------------- |";
    std::cout << std::endl;
}

// Explicit instantiations of Collection template class for various types and capacities
template class Collection<int, 10>;
template class Collection<double, 10>;
template class Collection<Book, 10>;
template class Collection<int, 72>;
template class Collection<double, 72>;
template class Collection<Book, 72>;

} // namespace seneca

#endif // SENECA_COLLECTION_H