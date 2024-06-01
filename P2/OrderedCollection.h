#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {

template <typename T>
class OrderedCollection : public Collection<T, 72> {
public:
    bool operator+=(const T& item) {
        if (this->size() < this->capacity()) {
            int i = this->size() - 1;
            while (i >= 0 && this->operator[](i) > item) {
                this->operator[](i + 1) = this->operator[](i);
                --i;
            }
            this->operator[](i + 1) = item;
            this->incrSize();
            this->setSmallestItem(item);
            this->setLargestItem(item);
            return true;
        }
        return false;
    }

};



} // namespace seneca

#endif
