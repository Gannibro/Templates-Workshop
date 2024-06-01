#include "Collection.h"

namespace seneca {

// Collection member function implementations
template <typename T, unsigned int C>
Collection<T, C>::Collection() {}

template <typename T, unsigned int C>
unsigned Collection<T, C>::size() const {
    return m_size;
}

template <typename T, unsigned int C>
unsigned Collection<T, C>::capacity() const {
    return C;
}

template <typename T, unsigned int C>
T Collection<T, C>::getSmallestItem() {
    return m_smallestItem;
}

template <typename T, unsigned int C>
T Collection<T, C>::getLargestItem() {
    return m_largestItem;
}

template <typename T, unsigned int C>
bool Collection<T, C>::operator+=(const T& item) {
    if (m_size < C) {
        m_items[m_size] = item;
        setSmallestItem(item);
        setLargestItem(item);
        incrSize();
        return true;
    }
    return false;
}

template <typename T, unsigned int C>
T& Collection<T, C>::operator[](unsigned index) {
    return m_items[index];
}

template <typename T, unsigned int C>
void Collection<T, C>::incrSize() {
    if (m_size < C) {
        ++m_size;
    }
}

template <typename T, unsigned int C>
void Collection<T, C>::setSmallestItem(const T& item) {
    if (item < m_smallestItem || m_size == 0) {
        m_smallestItem = item;
    }
}

template <typename T, unsigned int C>
void Collection<T, C>::setLargestItem(const T& item) {
    if (item > m_largestItem || m_size == 0) {
        m_largestItem = item;
    }
}

// Generic print implementation
template <typename T, unsigned int C>
void Collection<T, C>::print(std::ostream& os) const {
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
