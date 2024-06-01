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
    T& operator[](unsigned index);

    void incrSize();

    void setSmallestItem(const T& item);

    void setLargestItem(const T& item);

public:
    Collection();

    unsigned size() const;

    unsigned capacity() const;

    static T getSmallestItem();

    static T getLargestItem();

    bool operator+=(const T& item);

    void print(std::ostream& os) const;
};

// Static member declarations
template <typename T, unsigned int C>
T Collection<T, C>::m_smallestItem;

template <typename T, unsigned int C>
T Collection<T, C>::m_largestItem;

} // namespace seneca

#endif // SENECA_COLLECTION_H
