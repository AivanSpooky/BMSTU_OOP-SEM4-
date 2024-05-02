#pragma once

#include "iter.h"
#include "exception.h"

template <ValidType T>
Iterator<T>::Iterator(const Iterator<T>& Iterator)
{
    this->weakptr = Iterator.weakptr;
    this->size = Iterator.size;
    this->index = Iterator.index;
}

template <ValidType T>
Iterator<T>::Iterator(const BaseIter<T>& bit) : BaseIter<T>(bit) {};

template <ValidType T>
Iterator<T>::Iterator(Iterator<T>&& Iterator)
{
    this->weakptr = Iterator.weakptr;
    this->size = Iterator.size;
    this->index = Iterator.index;
    Iterator.weakptr.reset();
}

template <ValidType T>
Iterator<T>::Iterator(const Vector<T>& vec)
{
    this->weakptr = vec.values;
    this->size = vec.size;
    this->index = 0;
}

template <ValidType T>
T& Iterator<T>::operator *()
{
    this->check_object(__LINE__);
    this->check_validity(__LINE__);

    return *this->get_cur_ptr();
}

//template <ValidType T>
//const T& Iterator<T>::operator *() const
//{
//    return BaseIter<T>::operator *();
//}
//
template <ValidType T>
T* Iterator<T>::operator ->()
{
    this->check_object(__LINE__);
    this->check_validity(__LINE__);

    return this->get_cur_ptr();
}

//template <ValidType T>
//const T* Iterator<T>::operator ->() const
//{
//    check_object(__LINE__);
//    check_validity(__LINE__);
//
//    return get_cur_ptr();
//}
// 
//template <ValidType T>
//const T* Iterator<T>::operator ->() const
//{
//    return BaseIter<T>::operator ->();
//}

template <ValidType T>
T& Iterator<T>::operator [](difference_type index)
{
    return *(operator+(index));
}

template <ValidType T>
const T& Iterator<T>::operator [](difference_type index) const
{
    return *(operator+(index));
}

//template <ValidType T>
//Iterator<T>::operator bool() const
//{
//    check_object(__LINE__);
//
//    return (this->size == 0 || this->index < 0 || this->index >= this->size) ? false : true;
//}
//template <ValidType T>
//Iterator<T>::operator bool() const
//{
//    return BaseIter<T>::operator bool();
//}

template <ValidType T>
Iterator<T>& Iterator<T>::operator =(const Iterator<T>& Iterator)
{
    Iterator.check_object(__LINE__);

    this->weakptr = Iterator.weakptr;
    this->size = Iterator.size;
    this->index = Iterator.index;

    return *this;
}

template <ValidType T>
Iterator<T>& Iterator<T>::operator =(Iterator<T>&& Iterator)
{
    Iterator.check_object(__LINE__);

    this->weakptr = Iterator.weakptr;
    this->size = Iterator.size;
    this->index = Iterator.index;
    Iterator.weakptr.reset();

    return *this;
}

template <ValidType T>
Iterator<T>& Iterator<T>::operator +=(size_type number)
{
    this->check_object(__LINE__);
    this->index += number;
    return *this;
}

template <ValidType T>
Iterator<T>& Iterator<T>::operator ++()
{
    this->check_object(__LINE__);
    if (this->index < this->size)
        ++(this->index);
    return *this;
}

template <ValidType T>
Iterator<T> Iterator<T>::operator ++(int)
{
    this->check_object(__LINE__);
    if (this->index < this->size)
        ++(*this);
    return *this;
}

template <ValidType T>
Iterator<T> Iterator<T>::operator +(size_type number) const
{
    this->check_object(__LINE__);
    Iterator<T> Iterator(*this);
    if (this->index + number <= this->size)
        Iterator += number;
    return Iterator;
}

template <ValidType T>
Iterator<T>& Iterator<T>::operator -=(size_type number)
{
    this->check_object(__LINE__);
    if (this->index >= number - 1)
        this->index -= number;
    return *this;
}

template <ValidType T>
Iterator<T>& Iterator<T>::operator --()
{
    this->check_object(__LINE__);
    if (this->index >= 0)
        --(this->index);
    return *this;
}

template <ValidType T>
Iterator<T> Iterator<T>::operator --(int)
{
    this->check_object(__LINE__);
    if (this->index >= 0)
        --(*this);
    return *this;
}

template <ValidType T>
Iterator<T> Iterator<T>::operator -(size_type number) const
{
    this->check_object(__LINE__);
    Iterator<T> Iterator(*this);
    if (this->index >= number - 1)
        Iterator -= number;
    return Iterator;
}

//template <ValidType T>
//std::strong_ordering Iterator<T>::operator <=>(const Iterator<T>& other) const
//{
//    check_object(__LINE__);
//
//    if (this->index == other.index)
//        return std::strong_ordering::equal;
//    else if (this->index < other.index)
//        return std::strong_ordering::less;
//    else
//        return std::strong_ordering::greater;
//}

//template <ValidType T>
//bool Iterator<T>::operator ==(const Iterator<T>& other) const
//{
//    return (*this <=> other) == std::strong_ordering::equal;
//}
////
//template <ValidType T>
//bool Iterator<T>::operator !=(const Iterator<T>& other) const
//{
//    return (*this <=> other) != std::strong_ordering::equal;
//}
////
//template <ValidType T>
//bool Iterator<T>::operator <=(const Iterator<T>& other) const
//{
//    return (*this <=> other) != std::strong_ordering::greater;
//}
////
//template <ValidType T>
//bool Iterator<T>::operator >=(const Iterator<T>& other) const
//{
//    return (*this <=> other) != std::strong_ordering::less;
//}
////
//template <ValidType T>
//bool Iterator<T>::operator <(const Iterator<T>& other) const
//{
//    return (*this <=> other) == std::strong_ordering::less;
//}
////
//template <ValidType T>
//bool Iterator<T>::operator >(const Iterator<T>& other) const
//{
//    return (*this <=> other) == std::strong_ordering::greater;
//}
//
//template <ValidType T>
//typename Iterator<T>::difference_type Iterator<T>::operator -(const Iterator<T>& other) const noexcept
//{
//    return BaseIter<T>:: operator -(other);
//}
//
//template <ValidType T>
//typename Iterator<T>::difference_type Iterator<T>::Distance(const Iterator<T>& other) const noexcept
//{
//    return BaseIter<T>::Distance(other);
//}

//template <ValidType T>
//void Iterator<T>::check_object(int line) const
//{
//    if (this->weakptr.expired())
//    {
//        time_t t_time = time(NULL);
//        throw RemoteObjExcept(__FILE__, typeid(*this).name(), line, ctime(&t_time));
//    }
//}
//template <ValidType T>
//void Iterator<T>::check_object(int line) const
//{
//    BaseIter<T>::check_object(line);
//}
//
//template <ValidType T>
//void Iterator<T>::check_validity(int line) const
//{
//    if (this->index < 0 || this->index >= this->size)
//    {
//        time_t t_time = time(NULL);
//        throw InvalidIterExcept(__FILE__, typeid(*this).name(), line, ctime(&t_time));
//    }
//}
//template <ValidType T>
//void Iterator<T>::check_validity(int line) const
//{
//    BaseIter<T>::check_validity(line);
//}
//
//template <ValidType T>
//T* Iterator<T>::get_cur_ptr() const
//{
//    std::shared_ptr<T[]> copy_ptr = this->weakptr.lock();
//    return copy_ptr.get() + this->index;
//}
//template <ValidType T>
//T* Iterator<T>::get_cur_ptr() const
//{
//    return BaseIter<T>::get_cur_ptr();
//}
