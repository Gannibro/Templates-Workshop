#include "Collection.h"
#include <algorithm>
#include <limits>

namespace seneca {

template<typename T, size_t Capacity>
Collection<T, Capacity>::Collection() : count(0) {}

template<typename T, size_t Capacity>
bool Collection<T, Capacity>::add(const T& item) {
    if (count < Capacity) {
        items[count++] = item;
        return true;
    }
    return false;
}

template<typename T, size_t Capacity>
size_t Collection<T, Capacity>::size() const {
    return count;
}

template<typename T, size_t Capacity>
size_t Collection<T, Capacity>::capacity() const {
    return Capacity;
}

template<typename T, size_t Capacity>
T Collection<T, Capacity>::getSmallestItem() const {
    return *std::min_element(items, items + count);
}

template<typename T, size_t Capacity>
T Collection<T, Capacity>::getLargestItem() const {
    return *std::max_element(items, items + count);
}

template<typename T, size_t Capacity>
Collection<T, Capacity>& Collection<T, Capacity>::operator+=(const T& item) {
    add(item);
    return *this;
}

template<typename T, size_t Capacity>
void Collection<T, Capacity>::print(std::ostream& os) const {
    os << "[";
    for (size_t i = 0; i < count; ++i) {
        os << items[i];
        if (i != count - 1) os << ",";
    }
    os << "]";
    std::cout << std::endl;
}

// Specialization for Book

Collection<Book, 10>::Collection() : count(0) {}

bool Collection<Book, 10>::add(const Book& item) {
    if (count < 10) {
        items[count++] = item;
        return true;
    }
    return false;
}

size_t Collection<Book, 10>::size() const {
    return count;
}

size_t Collection<Book, 10>::capacity() const {
    return 10;
}

Book Collection<Book, 10>::getSmallestItem() const {
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

Book Collection<Book, 10>::getLargestItem() const {
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

Collection<Book, 10>& Collection<Book, 10>::operator+=(const Book& item) {
    add(item);
    return *this;
}

void Collection<Book, 10>::print(std::ostream& os) const {
    os << "[After creating collection in empty state]" << std::endl;
    os << "Book with smallest pages-to-chapters ratio (initial-default state): " << std::endl;
    os << getSmallestItem() << std::endl;
    os << "Book with largest pages-to-chapters ratio (initial-default state): " << std::endl;
    os << getLargestItem() << std::endl;
    os << "size/capacity: " << count << "/" << 10 << std::endl;
}

} // namespace seneca

// Explicit template instantiation
template class seneca::Collection<int, 10>;
template class seneca::Collection<double, 10>;
