#pragma once


#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <stdexcept>

#include "base_vector.h"
#include "vector_exception.h"
#include "concepts.h"

using namespace std;

template <ValidType T>
class Vector final : public BaseVector 
{
public
    friend class Iterator<T>;
    friend class ConstIterator<T>;

    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;
    using size_type = int;
    using value_type = T;

    using pointer = Vector<T>*;
    using reference = const Vector<T>&;

    // Iter methods
    iterator begin() noexcept;
    iterator end() noexcept;
    iterator rbegin() noexcept;
    iterator rend() noexcept;

    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_iterator rbegin() const noexcept;
    const_iterator rend() const noexcept;

    // Constructors
    Vector();
    explicit Vector(size_type len);
    Vector(size_type len, value_type* arr);
    Vector(size_type len, value_type vector, ...);
    template <CanWorkWithT<T> U>
    Vector(initializer_list<U> args);
    // Copy constructors
    explicit Vector(reference vector);
    template <CanWorkWithT<T> U>
    explicit Vector(const Vector<U>& vector);
    // Move constructors
    Vector(Vector<value_type>&& vector) noexcept;
    template <CanWorkWithT<T> U>
    Vector(Vector<U>&& vector) noexcept;
    // Iter constructors
    template <ConvertibleIterator<T> I>
    Vector(const I begin, const I end, const size_type cnt);
    template <ConvertibleIterator<T> I>
    Vector(const I begin, const I end);
    template <ConvertibleIterator<T> I>
    Vector(const I begin, const size_type cnt);
    // Container constructors
    template <ConvertibleContainer<T> C>
    explicit Vector(const C& cont);

    // Destructor
    virtual ~Vector() noexcept;

    // Assignment
    Vector<T>& operator =(reference vector);
    template <CanWorkWithT<T> U>
    Vector<T>& operator =(const Vector<U> & vector);
    template <CanWorkWithT<T> U>
    Vector<T>& operator =(initializer_list<U> args);
    template <ConvertibleContainer<T> C>
    Vector<T>& operator =(const C& cont);
    Vector<T>& operator =(Vector&& vector) noexcept;

    // Get
    T& GetItem(size_type index);
    const T& GetItem(size_type index) const;

    // Set
    bool SetItem(size_type index, const value_type& item);

    // []
    T& operator [](size_type index);
    const T& operator [](size_type index) const;

    // Some properties
    bool IsZero() const noexcept;
    decltype(auto) GetLength() const noexcept; // Есть концепт для извлекаемости корня
    bool IsSingle() const noexcept;
    decltype(auto) GetSingle() const noexcept;
    decltype(auto) GetAngleBetweenVectors(reference vector) const;
    bool IsCollinear(reference vector) const;
    bool IsOrthgonal(reference vector) const;

    
    
    // vector + num (sum)
    template <CanWorkWithT<T> U>
    decltype(auto) operator +(const U& number) const noexcept;
    template <CanWorkWithT<T> U>
    decltype(auto) SumNum(const U& number) const noexcept;
    template <ValidType T, CanWorkWithT<T> U>
    friend Vector<T> operator +(const U& i, const Vector<T>& vec);
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator +=(const U& number) noexcept;
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& SumNumEqual(const U& number) noexcept;

    // vector - num (sub)
    template <CanWorkWithT<T> U>
    decltype(auto) operator -(const U& number) const noexcept;
    template <CanWorkWithT<T> U>
    decltype(auto) SubNum(const U& number) const noexcept;
    template <ValidType T, CanWorkWithT<T> U>
    friend Vector<T> operator -(const U& i, const Vector<T>& vec);
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator -=(const U& number) noexcept;
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& SubNumEqual(const U& number) noexcept;

    // Multiply vector by number
    template <CanWorkWithT<T> U>
    decltype(auto) operator *(const U& num) const noexcept;
    template <CanWorkWithT<T> U>
    decltype(auto) MulNum(const U& num) const noexcept;
    template <ValidType T, CanWorkWithT<T> U>
    friend Vector<T> operator *(const U& i, const Vector<T>& vec);
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator *=(const U& num) noexcept;
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& MulNumEqual(const U& num) noexcept;

    // Divide vector by number
    template <CanWorkWithT<T> U>
    decltype(auto) operator /(const U& number) const;
    template <CanWorkWithT<T> U>
    decltype(auto) DivNum(const U& number) const;
    template <ValidType T, CanWorkWithT<T> U>
    friend Vector<T> operator /(const U& i, const Vector<T>& vec);
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator /=(const U& number);
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& DivNumEqual(const U& number);



    // vector + vector (sum)
    template <CanWorkWithT<T> U>
    decltype(auto) operator +(const Vector<U>& vector) const;
    template <CanWorkWithT<T> U>
    decltype(auto) sum(const Vector<U>& vector) const;
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator +=(const Vector<U>& vector);
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& SumEqual(const Vector<U>& vector);

    // vector - vector (sub)
    template <CanWorkWithT<T> U>
    decltype(auto) operator -(const Vector<U>& vector) const;
    template <CanWorkWithT<T> U>
    decltype(auto) Sub(const Vector<U>& vector) const;
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator -=(const Vector<U>& vector);
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& SubEqual(const Vector<U>& vector);

    // Scalar multiplication
    template <CanWorkWithT<T> U>
    decltype(auto) operator *(const Vector<U>& vector) const;
    template <CanWorkWithT<T> U>
    decltype(auto) ScalarMul(const Vector<U>& vector) const;
    //
    template <WorkableAndConvertibleToT<T> U>
    T operator *=(const Vector<U>& vector);
    template <WorkableAndConvertibleToT<T> U>
    T ScalarMulEqual(const Vector<U>& vector);

    // Vector multiplication
    template <CanWorkWithT<T> U>
    decltype(auto) operator &(const Vector<U>& vector) const;
    template <CanWorkWithT<T> U>
    decltype(auto) VectorMul(const Vector<U>& vector) const;
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator &=(const Vector<U>& vector);
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& VectorMulEqual(const Vector<U>& vector);

    // ElemMul vectors
    template <CanWorkWithT<T> U>
    decltype(auto) operator ^(const Vector<U>& vector) const;
    template <CanWorkWithT<T> U>
    decltype(auto) MulElems(const Vector<U>& vector) const;
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator ^=(const Vector<U>& vector);
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& MulElemsEqual(const Vector<U>& vector);
    
    // Divide vector by vector
    template <CanWorkWithT<T> U>
    decltype(auto) operator /(const Vector<U>& vector) const;
    template <CanWorkWithT<T> U>
    decltype(auto) Div(const Vector<U>& vector) const;
    //
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& operator /=(const Vector<U>& vector);
    template <WorkableAndConvertibleToT<T> U>
    Vector<T>& DivEqual(const Vector<U>& vector);


    // Comparison
    std::strong_ordering operator<=>(reference other) const noexcept;

    // Equal vectors
    bool operator ==(reference vector) const;

    // Not Equal vectors
    bool operator !=(reference vector) const;
    
    // Reverse vector
    Vector<T> operator -();
    Vector<T> reverse();
    Vector<T> turn();

    // GetSize & IsEmpty methods
    size_type GetSize() const noexcept;
    bool IsEmpty() const noexcept;

protected:
    size_type size = 0;
    T Sum();
    void AllocNewVector(int amount);
private:
    std::shared_ptr<value_type[]> values;
};