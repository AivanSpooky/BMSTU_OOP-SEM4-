#pragma once

#include "base_exception.h"

// ITER & VECTOR EXCEPT
class IterExcept : public BaseExcept
{
public:
    IterExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Iter Error!") :
        BaseExcept(filename, classname, line, time, info) {}
};
class VectorExcept : public BaseExcept
{
public:
    VectorExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Vector Error!") :
        BaseExcept(filename, classname, line, time, info) {}
};
//