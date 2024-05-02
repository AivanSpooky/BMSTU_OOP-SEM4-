#pragma once
#include <iterator>
#include <memory>
#include <compare>
#include <iostream>
#include "concepts.h"
#include "iter_exception.h"

template <ValidType T>
class Vector;

template <ValidType T>
class BaseIter
{
public:
    friend class Vector<T>;

    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using size_type = int;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    const T& operator *() const;
    const T* operator ->() const;
    operator bool() const;

    std::strong_ordering operator <=>(const BaseIter<T>& other) const;

    difference_type operator -(const BaseIter& other) const noexcept;
    difference_type Distance(const BaseIter& other) const noexcept;

protected:
    BaseIter() noexcept = default;
    BaseIter(const BaseIter& bit);

    ~BaseIter() = 0;

    T* get_cur_ptr() const;
    void check_object(int line) const;
    void check_validity(int line) const;

    size_type index;
    size_type size;
    std::weak_ptr<T[]> weakptr;
};