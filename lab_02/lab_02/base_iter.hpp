#pragma once

#include "base_iter.h"

template <ValidType T>
BaseIter<T>::~BaseIter() {}

template <ValidType T>
void BaseIter<T>::check_validity(int line) const
{
    if (this->index < 0 || this->index >= this->size)
    {
        time_t t_time = time(NULL);
        throw InvalidIterExcept(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    }
}

template <ValidType T>
void BaseIter<T>::check_object(int line) const
{
    if (this->weakptr.expired())
    {
        time_t t_time = time(NULL);
        throw RemoteObjExcept(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    }
}

template <ValidType T>
typename BaseIter<T>::difference_type BaseIter<T>::operator -(const BaseIter& other) const noexcept
{
    return (this->index - other.index);
}

template <ValidType T>
typename BaseIter<T>::difference_type BaseIter<T>::Distance(const BaseIter& other) const noexcept
{
    return other - *this;
}

template <ValidType T>
const T& BaseIter<T>::operator *() const
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return *get_cur_ptr();
}

template <ValidType T>
const T* BaseIter<T>::operator ->() const
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return get_cur_ptr();
}

template <ValidType T>
BaseIter<T>::operator bool() const
{
    check_object(__LINE__);

    return (this->size == 0 || this->index < 0 || this->index >= this->size) ? false : true;
}

template <ValidType T>
T* BaseIter<T>::get_cur_ptr() const
{
    std::shared_ptr<T[]> copy_ptr = this->weakptr.lock();
    return copy_ptr.get() + index;
}

template <ValidType T>
std::strong_ordering BaseIter<T>::operator <=>(const BaseIter<T>& other) const
{
    check_object(__LINE__);

    if (this->index == other.index)
        return std::strong_ordering::equal;
    else if (this->index < other.index)
        return std::strong_ordering::less;
    else
        return std::strong_ordering::greater;
}

template <ValidType T>
BaseIter<T>::BaseIter(const BaseIter& bit)
{
    this->weakptr = bit.weakptr;
    this->size = bit.size;
    this->index = bit.index;
}