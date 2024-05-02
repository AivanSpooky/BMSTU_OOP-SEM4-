#pragma once

#include "base_iter.h"
#include "const_iter.h"
#include "exception.h"

template <ValidType T>
ConstIterator<T>::ConstIterator(const ConstIterator<T>& iter)
{
    this->weakptr = iter.weakptr;
    this->size = iter.size;
    this->index = iter.index;
}

template <ValidType T>
ConstIterator<T>::ConstIterator(const BaseIter<T>& bit) : BaseIter<T>(bit) {};

template <ValidType T>
ConstIterator<T>::ConstIterator(const Iterator<T>& bit) : BaseIter<T>(bit) {};

template <ValidType T>
ConstIterator<T>::ConstIterator(ConstIterator<T>&& iter)
{
    this->weakptr = iter.weakptr;
    this->size = iter.size;
    this->index = iter.index;
    iter.weakptr.reset();
}

template <ValidType T>
ConstIterator<T>::ConstIterator(const Vector<T>& vec)
{
    this->weakptr = vec.values;
    this->size = vec.size;
    this->index = 0;
}

//template <ValidType T>
//const T& ConstIterator<T>::operator *() const
//{
//    check_object(__LINE__);
//    check_validity(__LINE__);
//
//    return *get_cur_ptr();
//}
//
//template <ValidType T>
//const T* ConstIterator<T>::operator ->() const
//{
//    check_object(__LINE__);
//    check_validity(__LINE__);
//
//    return get_cur_ptr();
//}

template <ValidType T>
const T& ConstIterator<T>::operator [](size_type index) const
{
    return *(operator+(index));
}

//template <ValidType T>
//ConstIterator<T>::operator bool() const
//{
//    check_object(__LINE__);
//
//    return (this->size == 0 || this->index < 0 || this->index >= this->size) ? false : true;
//}
//template <ValidType T>
//ConstIterator<T>::operator bool() const
//{
//    return BaseIter<T>::operator bool();
//}

template <ValidType T>
ConstIterator<T>& ConstIterator<T>::operator =(const ConstIterator<T>& iter)
{
    iter.check_object(__LINE__);

    this->weakptr = iter.weakptr;
    this->size = iter.size;
    this->index = iter.index;

    return *this;
}

template <ValidType T>
ConstIterator<T>& ConstIterator<T>::operator =(ConstIterator<T>&& iter)
{
    iter.check_object(__LINE__);

    this->weakptr = iter.weakptr;
    this->size = iter.size;
    this->index = iter.index;
    iter.weakptr.reset();

    return *this;
}

template <ValidType T>
ConstIterator<T>& ConstIterator<T>::operator +=(size_type number)
{
    this->check_object(__LINE__);
    this->index += number;
    return *this;
}

template <ValidType T>
ConstIterator<T>& ConstIterator<T>::operator ++()
{
    this->check_object(__LINE__);
    if (this->index < this->size)
        ++(this->index);
    return *this;
}

template <ValidType T>
ConstIterator<T> ConstIterator<T>::operator ++(int)
{
    this->check_object(__LINE__);
    if (this->index < this->size)
        ++(*this);
    return *this;
}

template <ValidType T>
ConstIterator<T> ConstIterator<T>::operator +(size_type number) const
{
    this->check_object(__LINE__);
    ConstIterator<T> iter(*this);
    if (this->index + number <= this->size)
        iter += number;
    return iter;
}

template <ValidType T>
ConstIterator<T>& ConstIterator<T>::operator -=(size_type number)
{
    this->check_object(__LINE__);
    if (this->index >= number - 1)
        this->index -= number;
    return *this;
}

template <ValidType T>
ConstIterator<T>& ConstIterator<T>::operator --()
{
    this->check_object(__LINE__);
    if (this->index >= 0)
        --(this->index);
    return *this;
}

template <ValidType T>
ConstIterator<T> ConstIterator<T>::operator --(int)
{
    this->check_object(__LINE__);
    if (this->index >= 0)
        --(*this);
    return *this;
}

template <ValidType T>
ConstIterator<T> ConstIterator<T>::operator -(size_type number) const
{
    this->check_object(__LINE__);
    ConstIterator<T> iter(*this);
    if (this->index >= number - 1)
        iter -= number;
    return iter;
}

//template <ValidType T>
//std::strong_ordering ConstIterator<T>::operator <=>(const ConstIterator<T>& other) const
//{
//    check_object(__LINE__);
//
//    if (this->weakptr.lock() == other.weakptr.lock())
//        return std::strong_ordering::equal;
//    else if (this->weakptr.lock() < other.weakptr.lock())
//        return std::strong_ordering::less;
//    else
//        return std::strong_ordering::greater;
//}

//template <ValidType T>
//bool ConstIterator<T>::operator ==(const ConstIterator<T>& other) const
//{
//    return (*this <=> other) == std::strong_ordering::equal;
//}
////
//template <ValidType T>
//bool ConstIterator<T>::operator !=(const ConstIterator<T>& other) const
//{
//    return (*this <=> other) != std::strong_ordering::equal;
//}
////
//template <ValidType T>
//bool ConstIterator<T>::operator <=(const ConstIterator<T>& other) const
//{
//    return (*this <=> other) != std::strong_ordering::greater;
//}
////
//template <ValidType T>
//bool ConstIterator<T>::operator >=(const ConstIterator<T>& other) const
//{
//    return (*this <=> other) != std::strong_ordering::less;
//}
////
//template <ValidType T>
//bool ConstIterator<T>::operator <(const ConstIterator<T>& other) const
//{
//    return (*this <=> other) == std::strong_ordering::less;
//}
////
//template <ValidType T>
//bool ConstIterator<T>::operator >(const ConstIterator<T>& other) const
//{
//    return (*this <=> other) == std::strong_ordering::greater;
//}

//template <ValidType T>
//void ConstIterator<T>::check_object(int line) const
//{
//    if (this->weakptr.expired())
//    {
//        time_t t_time = time(NULL);
//        throw RemoteObjExcept(__FILE__, typeid(*this).name(), line, ctime(&t_time));
//    }
//}

//template <ValidType T>
//void ConstIterator<T>::check_validity(int line) const
//{
//    if (this->index < 0 || this->index >= this->size)
//    {
//        time_t t_time = time(NULL);
//        throw InvalidIterExcept(__FILE__, typeid(*this).name(), line, ctime(&t_time));
//    }
//}
//template <ValidType T>
//void ConstIterator<T>::check_validity(int line) const
//{
//    BaseIter<T>::check_validity(line);
//}
//
//template <ValidType T>
//T* ConstIterator<T>::get_cur_ptr() const
//{
//    std::shared_ptr<T[]> copy_ptr = this->weakptr.lock();
//    return copy_ptr.get() + this->index;
//}

//template <ValidType T>
//T* ConstIterator<T>::get_cur_ptr() const
//{
//    return BaseIter<T>::get_cur_ptr();
//}