#pragma once

#include "vector.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <ctime>
#include <limits>
#include "iter.hpp"
#include "const_iter.hpp"
#include "exception.h"

template <ValidType T>
typename Vector<T>::iterator Vector<T>::begin() noexcept
{
    return iterator(*this);
}

template <ValidType T>
typename Vector<T>::iterator Vector<T>::end() noexcept
{
    iterator iter(*this);
    return (iter + this->size);
}

template <ValidType T>
typename Vector<T>::iterator Vector<T>::rbegin() noexcept
{
    return this->end();
}

template <ValidType T>
typename Vector<T>::iterator Vector<T>::rend() noexcept
{
    return (this->begin() - 1);
}

template <ValidType T>
typename Vector<T>::const_iterator Vector<T>::begin() const noexcept
{
    const_iterator iter(*this);
    return iter;
}

template <ValidType T>
typename Vector<T>::const_iterator Vector<T>::end() const noexcept
{
    const_iterator iter(*this);
    return (iter + this->size);
}

template <ValidType T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const noexcept
{
    return this->begin();
}

template <ValidType T>
typename Vector<T>::const_iterator Vector<T>::cend() const noexcept
{
    return this->end();
}

template <ValidType T>
typename Vector<T>::const_iterator Vector<T>::rbegin() const noexcept
{
    return this->end();
}

template <ValidType T>
typename Vector<T>::const_iterator Vector<T>::rend() const noexcept
{
    return (this->begin() - 1);
}

template <ValidType T>
Vector<T>::Vector()
{
    time_t t_time = time(NULL);
    this->size = 0;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

template <ValidType T>
Vector<T>::Vector(size_type len)
{
    time_t t_time = time(NULL);
    if (len < 0)
        throw InitVectorNegSizeExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    else if (len == 0)
    {
        Vector();
        return;
    }

    this->size = len;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    for (iterator iter(*this); iter; iter++)
        *iter = 0;
}

template <ValidType T>
Vector<T>::Vector(size_type len, value_type* arr)
{
    time_t t_time = time(NULL);
    if (len < 0)
        throw InitVectorNegSizeExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    else if (len == 0)
    {
        Vector();
        return;
    }

    if (!arr)
        throw InitVectorCorruptedArrayExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    this->size = len;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (int i = 0; iter; i++, iter++)
        *iter = arr[i];
}

template <ValidType T>
Vector<T>::Vector(size_type len, value_type vector, ...)
{
    time_t t_time = time(NULL);
    if (len < 0)
        throw InitVectorNegSizeExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    else if (len == 0)
    {
        Vector();
        return;
    }

    this->size = len;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    va_list var;
    va_start(var, vector);
    for (iterator iter(*this); iter; iter++)
    {
        *iter = vector;
        vector = va_arg(var, T);
    }
    va_end(var);
}

template <ValidType T>
template <CanWorkWithT<T> U>
Vector<T>::Vector(initializer_list<U> args)
{
    if (args.size() == 0)
    {
        Vector();
        return;
    }

    time_t t_time = time(NULL);

    this->size = size_type(args.size());
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (auto& curItem : args)
    {
        *iter = curItem;
        iter++;
    }
}

template <ValidType T>
template <ConvertibleIterator<T> I>
Vector<T>::Vector(const I begin, const I end, const size_type cnt)
{
    time_t t_time = time(NULL);
    if (cnt > begin.Distance(end))
        throw NotEnoughRangeValuesExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (cnt == 0)
    {
        Vector();
        return;
    }

    t_time = time(NULL);
    this->size = cnt;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    size_t written = 0;
    iterator iter(*this);
    for (auto it = begin; written < cnt && it != end; it++, iter++)
    {
        *iter = *it;
        written++;
    }
}

template <ValidType T>
template <ConvertibleIterator<T> I>
Vector<T>::Vector(const I begin, const I end)
{
    size_t cnt = 0;
    for (auto it = begin; it != end; it++)
        cnt++;
    
    if (cnt == 0)
    {
        Vector();
        return;
    }

    time_t t_time = time(NULL);
    this->size = cnt;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    size_t written = 0;
    iterator iter(*this);
    for (auto it = begin; written < cnt && it != end; it++, iter++)
    {
        *iter = *it;
        written++;
    }
}

template <ValidType T>
template <ConvertibleIterator<T> I>
Vector<T>::Vector(const I begin, const size_type cnt)
{
    time_t t_time = time(NULL);
    size_t written = 0;
    for (auto it = begin; it; it++)
        written++;

    if (cnt > written)
        throw NotEnoughRangeValuesExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (cnt == 0)
    {
        Vector();
        return;
    }

    t_time = time(NULL);
    this->size = cnt;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    written = 0;
    iterator iter(*this);
    for (auto it = begin; written < cnt && it; it++, iter++)
    {
        *iter = *it;
        written++;
    }
}

template <ValidType T>
template <ConvertibleContainer<T> C>
Vector<T>::Vector(const C& cont)
{
    time_t t_time = time(NULL);

    this->size = size_type(cont.size());
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (auto& a : cont)
    {
        *iter = a;
        iter++;
    }
}

// Конструктор копирования
template <ValidType T>
Vector<T>::Vector(reference vector)
{
    time_t t_time = time(NULL);

    this->size = vector.size;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (iterator iterFrom(vector); iterFrom; iterFrom++)
    {
        *iter = *iterFrom;
        iter++;
    }
}

template <ValidType T>
template <CanWorkWithT<T> U>
Vector<T>::Vector(const Vector<U>& vector)
{
    time_t t_time = time(NULL);

    this->size = vector.GetSize();
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (auto &a: vector)
    {
        *iter = a;
        iter++;
    }
}

// Конструктор переноса
template <ValidType T>
Vector<T>::Vector(Vector<value_type>&& vector) noexcept
{
    this->size = vector.size;
    values = vector.values;
    vector.values = nullptr;
}

template <ValidType T>
template <CanWorkWithT<T> U>
Vector<T>::Vector(Vector<U>&& vector) noexcept
{
    this->size = vector.size;
    values = vector.values;
    vector.values = nullptr;
}

// Деструктор.
template <ValidType T>
Vector<T>::~Vector() noexcept
{
    if (values)
        values.reset();
}


// = копирование
template <ValidType T>
Vector<T>& Vector<T>::operator =(reference vector)
{
    time_t t_time = time(NULL);

    this->size = vector.size;
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));


    iterator iterFrom(vector);
    for (iterator iterTo(*this); iterTo; iterFrom++, iterTo++)
        *iterTo = *iterFrom;

    return *this;
}
// = копирование
template <ValidType T>
template <CanWorkWithT<T> U>
Vector<T>& Vector<T>::operator =(const Vector<U>& vector)
{
    time_t t_time = time(NULL);

    this->size = vector.GetSize();
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));


    Iterator<U> iterFrom(vector);
    for (iterator iterTo(*this); iterTo; iterFrom++, iterTo++)
        *iterTo = *iterFrom;

    return *this;
}
// = копирование
template <ValidType T>
template <CanWorkWithT<T> U>
Vector<T>& Vector<T>::operator =(initializer_list<U> args)
{
    time_t t_time = time(NULL);

    this->size = size_type(args.size());
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (auto& curItem : args)
    {
        *iter = curItem;
        iter++;
    }

    return *this;
}

template <ValidType T>
template <ConvertibleContainer<T> C>
Vector<T> &Vector<T>::operator =(const C& cont)
{
    time_t t_time = time(NULL);

    this->size = size_type(cont.size());
    AllocNewVector(this->size);
    if (!values)
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    iterator iter(*this);
    for (auto& a : cont)
    {
        *iter = a;
        iter++;
    }
}
// = перенос
template <ValidType T>
Vector<T>& Vector<T>::operator =(Vector<T>&& vector) noexcept
{
    this->size = vector.size;
    values = vector.values;
    vector.values.reset();

    return *this;
}

// OPS

// GetItem
template <ValidType T>
T& Vector<T>::GetItem(size_type index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size)
        throw IndexVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (int i = 0; i < index; i++, iter++);

    return *iter;
}
// GetItem - const
template <ValidType T>
const T& Vector<T>::GetItem(size_type index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size)
        throw IndexVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator iter(*this);
    for (int i = 0; i < index; i++, iter++) {}

    return *iter;
}
// SetItem
template <ValidType T>
bool Vector<T>::SetItem(size_type index, const value_type& item)
{
    time_t t_time = time(NULL);
    bool res = true;
    if (index < 0 || index >= this->size)
        throw IndexVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    else
    {
        iterator iter(*this);
        for (int i = 0; i < index; i++, iter++);
        (*iter) = item;
    }
    return res;
}

// Index
template <ValidType T>
T& Vector<T>::operator[] (size_type index)
{
    return GetItem(index);
}

// Inedex - const
template <ValidType T>
const T& Vector<T>::operator [](size_type index) const
{
    return GetItem(index);
}

// single-lenght vector check
template <ValidType T>
bool Vector<T>::IsSingle() const noexcept
{
    return (fabs(GetLength() - 1) < std::numeric_limits<double>::epsilon());
}

// zero-lenght vector check
template <ValidType T>
bool Vector<T>::IsZero() const noexcept
{
    return (GetLength() == 0);
}

// GetLength of vector
template <ValidType T>
decltype(auto) Vector<T>::GetLength() const noexcept
{
    time_t t_time = time(NULL);

    decltype(auto) sum = 0.;
    for (iterator iter(*this); iter; iter++)
        sum += *iter * *iter;
    sum = sqrt(sum);
    return sum;
}

// get single-lenght vector from cur vector
template <ValidType T>
decltype(auto) Vector<T>::GetSingle() const noexcept
{
    time_t t_time = time(NULL);

    Vector<T> single_vector(*this);

    decltype(auto) len = GetLength();
    for (iterator iter(single_vector); iter; iter++)
        *iter /= len;
    return single_vector;
}

// get angle between cur vector and vector given in params
template <ValidType T>
decltype(auto) Vector<T>::GetAngleBetweenVectors(reference vector) const
{
    time_t t_time = time(NULL);
    if (!this->GetLength() || !vector.GetLength())
        throw DivByZeroExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    double angle = (*this * vector) / (this->GetLength() * vector.GetLength());
    if (angle > 1) angle = 1.0;
    return acos(angle) * 180 / M_PI;
}

// cur vector is collinear to given in params vector
template <ValidType T>
bool Vector<T>::IsCollinear(reference vector) const
{
    time_t t_time = time(NULL);
    if (this->size == 0 || vector.size == 0 || this->size != vector.size)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return (GetAngleBetweenVectors(vector) < 1e-05);
}

// cur vector is orthogonal to given in params vector
template <ValidType T>
bool Vector<T>::IsOrthgonal(reference vector) const
{
    time_t t_time = time(NULL);
    if (this->size == 0 || vector.size == 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return (fabs(GetAngleBetweenVectors(vector) - 90) < std::numeric_limits<double>::epsilon());
}

// Comparison methods
template <ValidType T>
std::strong_ordering Vector<T>::operator<=>(reference other) const noexcept
{
    if (this->size == other->GetLength())
        return std::strong_ordering::equal;
    else if (this->size < other->GetLength())
        return std::strong_ordering::less;
    else
        return std::strong_ordering::greater;
}
//template <ValidType T>
//bool Vector<T>::operator <=(reference other) const noexcept
//{
//    return (*this <=> other) != std::strong_ordering::greater;
//}
//template <ValidType T>
//bool Vector<T>::operator >=(reference other) const noexcept
//{
//    return (*this <=> other) != std::strong_ordering::less;
//}
//template <ValidType T>
//bool Vector<T>::operator <(reference other) const noexcept
//{
//    return (*this <=> other) == std::strong_ordering::less;
//}
//template <ValidType T>
//bool Vector<T>::operator >(reference other) const noexcept
//{
//    return (*this <=> other) == std::strong_ordering::greater;
//}

// Умножить на число
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::operator *(const U &num) const noexcept
{
    time_t t_time = time(NULL);

    Vector<decltype((*this)[0] * num)> newVector(*this);
    iterator iterator(newVector);
    for (; iterator; iterator++)
    {
        *iterator *= num;
    }


    return newVector;
}

template <ValidType T, CanWorkWithT<T> U>
Vector<T> operator *(const U& i, const Vector<T>& vec)
{
    return (vec * i);
}

template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::MulNum(const U &num) const noexcept
{
    return operator*(num);
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T> &Vector<T>::operator *=(const U &num) noexcept
{
    time_t t_time = time(NULL);

    iterator iterator(*this);
    for (; iterator; iterator++)
        *iterator *= num;
    return *this;
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T> &Vector<T>::MulNumEqual(const U &num) noexcept
{
    return operator*=(num);
}

template <ValidType T>
Vector<T> operator *=(const T& i, const Vector<T>& vec)
{
    return operator*=(vec);
}

// 2 vectors by-elem multiplication
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::operator ^(const Vector<U>& vector) const
{
    time_t t_time = time(NULL);
    if (this->size <= 0 || vector.GetSize() <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Vector<decltype((*this)[0] * vector[0])> new_vec(this->size);

    iterator resIter(new_vec);
    iterator fIter(*this);
    iterator sIter(vector);

    for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
    {
        *resIter = *fIter * *sIter;
    }
    
    return new_vec;
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T>& Vector<T>::operator ^=(const Vector<U>& vector)
{
    time_t t_time = time(NULL);
    if (this->size <= 0 || vector.GetSize() <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator fIter(*this);
    iterator sIter(vector);

    for (int i = 0; fIter; i++, fIter++, sIter++)
        *fIter = *fIter * *sIter;

    return (*this);
}

template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::MulElems(const Vector<U>& vector) const
{
    return operator^(vector);
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T>& Vector<T>::MulElemsEqual(const Vector<U>& vector)
{
    return operator^=(vector);
}

// Scalar multiplication
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::operator *(const Vector<U>& vector) const
{
    time_t t_time = time(NULL);
    if (this->size <= 0 || vector.size <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Vector<decltype((*this)[0] * vector[0])> new_vec(this->size);
    new_vec = (*this) ^ vector;
    return new_vec.Sum();
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
T Vector<T>::operator *=(const Vector<U>& vector)
{
    time_t curTime = time(NULL);
    if (this->size <= 0 || vector.size <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    (*this) ^= vector;
    return this->Sum();
}

template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::ScalarMul(const Vector<U> &vector) const
{
    return operator*(vector);
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
T Vector<T>::ScalarMulEqual(const Vector<U>& vector)
{
    return operator*=(vector);
}

// Vector Multiplication
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::operator &(const Vector<U> &vector) const
{
    time_t t_time = time(NULL);
    if (this->size <= 0 || vector.GetSize() <= 0)
        EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    if (this->size != 3 && this->size != 5 && this->size != 7)
        return Vector<T>();

    if (this->size == 3)
    {
        decltype((*this)[0] * vector[0]) x = (*this)[1] * vector[2] - (*this)[2] * vector[1];
        decltype((*this)[0] * vector[0]) y = (*this)[2] * vector[0] - (*this)[0] * vector[2];
        decltype((*this)[0] * vector[0]) z = (*this)[0] * vector[1] - (*this)[1] * vector[0];

        Vector<decltype((*this)[0] * vector[0])> new_vector(3, x, y, z);
        return new_vector;
    }
    else if (this->size == 5)
    {
        decltype((*this)[0] * vector[0]) x = (*this)[1] * vector[2] - (*this)[2] * vector[1];
        decltype((*this)[0] * vector[0]) y = (*this)[2] * vector[3] - (*this)[3] * vector[2];
        decltype((*this)[0] * vector[0]) z = (*this)[3] * vector[4] - (*this)[4] * vector[3];
        decltype((*this)[0] * vector[0]) a = (*this)[4] * vector[0] - (*this)[0] * vector[4];
        decltype((*this)[0] * vector[0]) b = (*this)[0] * vector[1] - (*this)[1] * vector[0];

        Vector<decltype((*this)[0] * vector[0])> new_vector(5, x, y, z, a, b);
        return new_vector;
    }
    else
    {
        decltype((*this)[0] * vector[0]) x = (*this)[1] * vector[2] - (*this)[2] * vector[1];
        decltype((*this)[0] * vector[0]) y = (*this)[2] * vector[3] - (*this)[3] * vector[2];
        decltype((*this)[0] * vector[0]) z = (*this)[3] * vector[4] - (*this)[4] * vector[3];
        decltype((*this)[0] * vector[0]) a = (*this)[4] * vector[5] - (*this)[5] * vector[4];
        decltype((*this)[0] * vector[0]) b = (*this)[5] * vector[6] - (*this)[6] * vector[5];
        decltype((*this)[0] * vector[0]) c = (*this)[6] * vector[0] - (*this)[0] * vector[6];
        decltype((*this)[0] * vector[0]) d = (*this)[0] * vector[1] - (*this)[1] * vector[0];

        Vector<decltype((*this)[0] * vector[0])> new_vector(7, x, y, z, a, b, c, d);
        return new_vector;
    }
}

template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::VectorMul(const Vector<U> &vector) const
{
    return operator&(vector);
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T>& Vector<T>::operator &=(const Vector<U>& vector)
{
    time_t t_time = time(NULL);
    if (this->size <= 0 || vector.size <= 0)
        EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    if (this->size != 3)
        return *(new Vector<T>);

    decltype((*this)[0] * vector[0]) x = (*this)[1] * vector[2] - (*this)[2] * vector[1];
    decltype((*this)[0] * vector[0]) y = (*this)[2] * vector[0] - (*this)[0] * vector[2];
    decltype((*this)[0] * vector[0]) z = (*this)[0] * vector[1] - (*this)[1] * vector[0];

    *this = Vector<decltype((*this)[0] * vector[0])>(3, x, y, z);
    return *this;
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T>& Vector<T>::VectorMulEqual(const Vector<U>& vector)
{
    return operator&=(vector);
}

 // Division of 2 vectors
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::operator /(const Vector<U>& vector) const
 {
     time_t t_time = time(NULL);
     if (this->size <= 0 || vector.GetSize() <= 0)
         throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
     if (this->size != vector.GetSize())
         throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     Vector<decltype((*this)[0] + vector[0])> newVector(this->size);

     iterator resIter(newVector);
     iterator fIter((*this));
     iterator sIter(vector);

     for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
     {
         if (fabs(*sIter) < std::numeric_limits<double>::epsilon())
         {
             t_time = time(NULL);
             throw DivByZeroExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
         }
         *resIter = *fIter / *sIter;
     }

     return newVector;
 }
 // Division of 2 vectors
 template <ValidType T>
 template <WorkableAndConvertibleToT<T> U>
 Vector<T> &Vector<T>::operator /=(const Vector<U>& vector)
 {
     time_t t_time = time(NULL);
     if (this->size <= 0 || vector.GetSize() <= 0)
         throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
     if (this->size != vector.GetSize())
         throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     iterator fIter((*this));
     iterator sIter(vector);

     for (int i = 0; fIter; i++, fIter++, sIter++)
     {
         if (fabs(*sIter) < std::numeric_limits<double>::epsilon())
         {
             t_time = time(NULL);
             throw DivByZeroExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
         }
         *fIter /= *sIter;
     }

     return *this;
 }
 // Division of 2 vectors
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::Div(const Vector<U>& vector) const
 {
     return operator/(vector);
 }
 // Division of 2 vectors
 template <ValidType T>
 template <WorkableAndConvertibleToT<T> U>
 Vector<T> &Vector<T>::DivEqual(const Vector<U>& vector)
 {
     return operator/=(vector);
 }

// Divide vector by number
template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T>& Vector<T>::operator /=(const U& number)
{
    time_t t_time = time(NULL);
    if (number == 0)
        throw DivByZeroExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    
    for (iterator iterator(*this); iterator; iterator++)
        *iterator /= number;
    return *this;
}
// Divide vector by number
template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T> &Vector<T>::DivNumEqual(const U& number)
{
    return operator/=(number);
}

template <ValidType T>
Vector<T> operator /=(const T& i, const Vector<T>& vec)
{
    Vector<T> newVec(vec);
    return ((newVec).reverse());
}

// Divide vector by number
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::operator /(const U& number) const
 {
     time_t t_time = time(NULL);
     if (number == 0)
         throw DivByZeroExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     Vector<decltype((*this)[0] / number)> new_vector(*this);
     Iterator<decltype((*this)[0] / number)> iterator(new_vector);
     for (; iterator; iterator++)
         *iterator /= number;
     return new_vector;
 }

 template <ValidType T, CanWorkWithT<T> U>
 Vector<T> operator /(const U& i, const Vector<T>& vec)
 {
     Vector<T> newVec(vec);
     newVec = newVec.turn();
     return (newVec * i);
 }
 // Divide vector by number
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::DivNum(const U& number) const
 {
     return operator/(number);
 }


// vector == vector (equal)
 template <ValidType T>
 bool Vector<T>::operator ==(reference vector) const
 {
     bool res = true;
     time_t t_time = time(NULL);
     if (this->size < 0 || vector.vector_size < 0)
         throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     if (this->size != vector.size)
         res = true;
     else
     {
         iterator fIter(*this);
         iterator sIter(vector);
         for (; res && fIter; sIter++, fIter++)
             if (fabs(*fIter - *sIter) > std::numeric_limits<double>::epsilon())
                 res = false;
     }

     return res;
 }

 // vector != vector (not equal)
 template <ValidType T>
 bool Vector<T>::operator !=(reference vector) const
 {
     bool res = false;
     time_t t_time = time(NULL);
     if (this->size < 0 || vector.vector_size < 0)
         throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     if (this->size != vector.size)
         res = true;
     else
     {
         iterator fIter(*this);
         iterator sIter(vector);
         for (; !res && fIter; sIter++)
             if (*fIter != *sIter)
                 res = true;
     }

     return res;
 }

 // Sum of all vector elements
 //template <ValidType T>
 //T Vector<T>::SumValue()
 //{
 //    time_t t_time = time(NULL);
 //    if (this->size <= 0)
 //        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

 //    iterator iterator(*this);
 //    T summary = 0;
 //    for (; iterator; iterator++)
 //        summary += *iterator;

 //    return summary;
 //}

 // Vector sum
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::operator +(const Vector<U> &vector) const
 {
     time_t t_time = time(NULL);
     if (this->size != vector.GetSize())
         throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     Vector<decltype((*this)[0] + vector[0])> newVector(this->size);

     iterator resIter(newVector);
     iterator fIter((*this));
     iterator sIter(vector);
     for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
         *resIter = *fIter + *sIter;

     return newVector;
 }
 // Vector sum
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::sum(const Vector<U> &vector) const
 {
     return operator+(vector);
 }
 // Vector sum
 template <ValidType T>
 template <WorkableAndConvertibleToT<T> U>
 Vector<T> &Vector<T>::operator +=(const Vector<U>& vector)
 {
     time_t t_time = time(NULL);
     if (this->size != vector.GetSize())
         throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

     iterator fIter((*this));
     iterator sIter(vector);
     for (int i = 0; fIter; i++, fIter++, sIter++)
         *fIter = *fIter + *sIter;

     return *this;
 }
 // Vector sum
 template <ValidType T>
 template <WorkableAndConvertibleToT<T> U>
 Vector<T> &Vector<T>::SumEqual(const Vector<U>& vector)
 {
     return operator+=(vector);
 }

// Vector sub
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::operator -(const Vector<U> &vector) const
{
    time_t t_time = time(NULL);
    //if (this->size <= 0 || vector.GetSize() <= 0)
    //    throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
 
    Vector<decltype((*this)[0] - vector[0])> newVector(this->size);
    iterator resIter(newVector);
    iterator fIter((*this));
    iterator sIter(vector);
 
    for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
        *resIter = *fIter - *sIter;
 
    return newVector;
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T> &Vector<T>::operator -=(const Vector<U>& vector)
{
    time_t t_time = time(NULL);
    if (this->size != vector.GetSize())
        throw DiffSizeVectorsExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    iterator fIter((*this));
    iterator sIter(vector);

    for (int i = 0; fIter; i++, fIter++, sIter++)
        *fIter = *fIter - *sIter;

    return *this;
}

template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::Sub(const Vector<U> &vector) const
{
    return operator-(vector);
}

template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T> &Vector<T>::SubEqual(const Vector<U>& vector)
{
    return operator-=(vector);
}


 // vector + number (sum)
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::operator +(const U &number) const noexcept
 {
     time_t t_time = time(NULL);

     Vector<decltype((*this)[0] + number)> newVector(this->size);

     iterator/*ator<decltype((*this)[0] + number)>*/ resIter(newVector);
     iterator/*ator<Type>*/ fIter((*this));
     for (int i = 0; resIter; i++, resIter++, fIter++)
         *resIter = *fIter + number;

     return newVector;
 }

 template <ValidType T, CanWorkWithT<T> U>
 Vector<T> operator +(const U& i, const Vector<T>& vec)
 {
     return (vec + i);
 }

 // vector + number (sum)
 template <ValidType T>
 template <WorkableAndConvertibleToT<T> U>
 Vector<T>& Vector<T>::operator +=(const U& number) noexcept
 {
     time_t t_time = time(NULL);

     iterator fIter((*this));
     for (int i = 0; fIter; i++, fIter++)
         *fIter += number;

     return (*this);
 }
 // vector + number (sum)
 template <ValidType T>
 template <CanWorkWithT<T> U>
 decltype(auto) Vector<T>::SumNum(const U &number) const noexcept
 {
     return operator +(number);
 }
 // vector + number (sum)
 template <ValidType T>
 template <WorkableAndConvertibleToT<T> U>
 Vector<T> &Vector<T>::SumNumEqual(const U &number) noexcept
 {
     return operator+=(number);
 }

 //template <ValidType T>
 //Vector<T> operator +=(const T& i, const Vector<T>& vec)
 //{
 //    return operator+=(i);
 //}

// vector - num (sub)
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::operator -(const U& number) const noexcept
{
    time_t t_time = time(NULL);

    Vector<decltype((*this)[0] + number)> newVector(this->size);

    iterator resIter(newVector);
    iterator fIter((*this));
    for (int i = 0; resIter; i++, resIter++, fIter++)
        *resIter = *fIter - number;

    return newVector;
}

template <ValidType T, CanWorkWithT<T> U>
Vector<T> operator -(const U& i, const Vector<T>& vec)
{
    Vector<T> newVec(vec);
    newVec = newVec.reverse();
    return (newVec + i);
}

// vector - num (sub)
template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T> &Vector<T>::operator -=(const U& number) noexcept
{
    time_t t_time = time(NULL);
 
    iterator fIter((*this));
    for (int i = 0; fIter; i++, fIter++)
        *fIter -= number;
 
    return (*this);
}
// vector - num (sub)
template <ValidType T>
template <CanWorkWithT<T> U>
decltype(auto) Vector<T>::SubNum(const U &number) const noexcept
{
    return operator -(number);
}
// vector - num (sub) 
template <ValidType T>
template <WorkableAndConvertibleToT<T> U>
Vector<T>& Vector<T>::SubNumEqual(const U& number) noexcept
{
    return operator -=(number);
};

//template <ValidType T, CanWorkWithT<T> U>
//Vector<T> operator -=(const U& i, const Vector<T>& vec)
//{
//    Vector<T> newVec(vec);
//    return (((newVec).reverse()) += i);
//}

// Reversed vector
template <ValidType T>
Vector<T> Vector<T>::operator -()
{
    time_t t_time = time(NULL);
    if (this->size <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Vector<T> newVector(*this);
    for (iterator iterator(newVector); iterator; iterator++)
        *iterator = -*iterator;

    return newVector;
}
// Reversed vector
template <ValidType T>
Vector<T> Vector<T>::reverse()
{
    return operator-();
}

//template <ValidType T>
//Vector<T> Vector<T>::operator /()
//{
//
//}

template <ValidType T>
Vector<T> Vector<T>::turn()
{
    time_t t_time = time(NULL);
    if (this->size <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Vector<T> newVector(*this);
    for (iterator iterator(newVector); iterator; iterator++)
    {
        if (*iterator == 0)
            throw DivByZeroExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        *iterator = 1 / (*iterator);
    }

    return newVector;
}

// GETSIZE
template <ValidType T>
typename Vector<T>::size_type Vector<T>::GetSize() const noexcept
{
    return this->size;
}
// ISEMPTY
template <ValidType T>
bool Vector<T>::IsEmpty() const noexcept
{
    return bool(this->size);
}
// SUM (protected)
template <ValidType T>
T Vector<T>::Sum()
{
    time_t t_time = time(NULL);
    if (this->size <= 0)
        throw EmptyVectorExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    T res = 0;
    for (iterator iter(*this); iter; iter++)
        res += *iter;

    return res;
}
// ALLOCNEWVECTOR
template <ValidType T>
void Vector<T>::AllocNewVector(int amount)
{
    time_t t_time = time(NULL);
    try
    {
        values.reset();
    }
    catch (std::bad_alloc& exception)
    {
        throw MemoryExcept(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    // std::default_delete - функция удаления по умолчанию при уничтожении shared_ptr
    std::shared_ptr<T[]> temp(new T[amount], std::default_delete<T[]>());
    values = temp;
}

template <ValidType T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    os << "(";
    for (ConstIterator<T> iter = vector.begin(); vector.GetSize() != 0 && iter != vector.end(); ++iter)
    {
        if (iter + 1 != vector.end())
            os << *iter << ", ";
        else
            os << *iter;
    }
    os << ")";
    return os;
}