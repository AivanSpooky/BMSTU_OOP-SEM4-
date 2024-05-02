#pragma once

#include "iter.h"
#include "const_iter.h"

class BaseVector
{
public:
    virtual ~BaseVector() = default;

    virtual bool IsEmpty() const noexcept = 0;
};