#pragma once


#include "base_iter.h"
#include <memory>
#include <compare>
#include <iostream>
#include <ctime>
#include "concepts.h"

template <ValidType T>
class Vector;

template <ValidType T>
class ConstIterator : public BaseIter<T>
{
public:
    using iterator_category = typename BaseIter<T>::iterator_category;
    using size_type = typename BaseIter<T>::size_type;
    using value_type = typename BaseIter<T>::value_type;
    using difference_type = typename BaseIter<T>::difference_type;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;

    ConstIterator(const ConstIterator<T>& iter);
    ConstIterator(const Iterator<T>& bit);
    ConstIterator(const BaseIter<T>& bit);
    ConstIterator(const Vector<T>& vec);
    ConstIterator(ConstIterator<T>&& iter);
    

    const T& operator [](size_type index) const;

    ConstIterator<T>& operator =(const ConstIterator<T>& iter);
    ConstIterator<T>& operator =(ConstIterator<T>&& iter);

    ConstIterator<T>& operator +=(size_type number);
    ConstIterator<T>& operator ++();
    ConstIterator<T> operator ++(int);
    ConstIterator<T> operator +(size_type number) const;

    ConstIterator<T>& operator -=(size_type number);
    ConstIterator<T>& operator --();
    ConstIterator<T> operator --(int);
    ConstIterator<T> operator -(size_type number) const;

//protected:
//    using BaseIter<T>::check_object;
//    using BaseIter<T>::check_validity;
//    using BaseIter<T>::get_cur_ptr;
};
