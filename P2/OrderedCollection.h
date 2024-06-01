#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {

template <typename T>
class OrderedCollection : public Collection<T, 72> {
public:
    bool operator+=(const T& item);
};

} // namespace seneca

#endif // SENECA_ORDEREDCOLLECTION_H
