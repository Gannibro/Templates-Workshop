#include "Collection.h"

namespace seneca {

// Static member initializations for Book specialization
template <>
Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

template <>
Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

template <>
void Collection<Book, 10>::print(std::ostream& os) const {
    os << "| ----------------------------------------------------------------------------------|\n";
    for (unsigned i = 0; i < m_size; ++i) {
        os << "| ";
        m_items[i].print(os);
        os << "     |\n";
    }
    os << "| ----------------------------------------------------------------------------------|";
    std::cout << std::endl;
}

template <>
void Collection<Book, 72>::print(std::ostream& os) const {
    os << "| --------------------------------------------------------------------------------|\n";
    for (unsigned i = 0; i < m_size; ++i) {
        os << "| ";
        m_items[i].print(os);
        os << "     |\n";
    }
    os << "| --------------------------------------------------------------------------------|";
    std::cout << std::endl;
}

} // namespace seneca
