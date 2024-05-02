#pragma once


#include "base_iter.hpp"
#include <ctime>
#include "concepts.h"

template <ValidType T>
class Vector;

template <ValidType T>
class Iterator : public BaseIter<T>
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using size_type = typename BaseIter<T>::size_type;
    using value_type = typename BaseIter<T>::value_type;
    using difference_type = typename BaseIter<T>::difference_type;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;

    Iterator(const Iterator<T>& Iterator);
    Iterator(Iterator<T>&& Iterator);
    Iterator(const BaseIter<T>& bit);
    Iterator(const Vector<T>& vec);

    T& operator *();
    T* operator ->();

    T& operator [](difference_type index);
    const T& operator [](difference_type index) const;

    Iterator<T>& operator =(const Iterator<T>& Iterator);
    Iterator<T>& operator =(Iterator<T>&& Iterator);

    Iterator<T>& operator +=(size_type number);
    Iterator<T>& operator ++();
    Iterator<T> operator ++(int);
    Iterator<T> operator +(size_type number) const;

    Iterator<T>& operator -=(size_type number);
    Iterator<T>& operator --();
    Iterator<T> operator --(int);
    Iterator<T> operator -(size_type number) const;

//protected:
//    using BaseIter<T>::check_object;
//    using BaseIter<T>::check_validity;
//    using BaseIter<T>::get_cur_ptr;
};