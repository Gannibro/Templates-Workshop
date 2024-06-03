#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {

template <typename T>
class OrderedCollection : public Collection<T, 72> {
public:
    OrderedCollection& operator+=(const T& item) {
        if (this->size() < this->capacity()) {
            int i = this->size() - 1;
            while (i >= 0 && this->operator[](i) > item) {
                this->operator[](i + 1) = this->operator[](i);
                --i;
            }
            this->operator[](i + 1) = item;
            this->add(item);
            return *this;
        }
        return *this;
    }
};

// Specialization for Book
template<>
class OrderedCollection<Book> : public Collection<Book, 72> {
public:
    OrderedCollection& operator+=(const Book& item) {
        if (this->size() < this->capacity()) {
            int i = this->size() - 1;
            while (i >= 0 && this->operator[](i).pagesToChaptersRatio() > item.pagesToChaptersRatio()) {
                this->operator[](i + 1) = this->operator[](i);
                --i;
            }
            this->operator[](i + 1) = item;
            this->add(item);
            return *this;
        }
        return *this;
    }

    std::ostream& print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (size_t i = 0; i < this->size(); ++i) {
            os << "| ";
            this->operator[](i).print(os);
            os << "     |\n";
        }
        return os << "| ---------------------------------------------------------------------------|\n";
    }
};

}

#endif // SENECA_ORDEREDCOLLECTION_H