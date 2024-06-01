 #include "OrderedCollection.h"

namespace seneca {

template <typename T>
bool OrderedCollection<T>::operator+=(const T& item) {
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

template class OrderedCollection<int>;
template class OrderedCollection<double>;
template class OrderedCollection<seneca::Book>;
} // namespace seneca