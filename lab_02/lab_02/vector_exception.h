#pragma once

#include "exception.h"

class MemoryExcept : public VectorExcept
{
public:
    MemoryExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Memory error found!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class DivByZeroExcept : public VectorExcept
{
public:
    DivByZeroExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Division by zero is not allowed!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class InitVectorNegSizeExcept : public VectorExcept
{
public:
    InitVectorNegSizeExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Initialising vector with negative size value is fobidden!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class InitVectorCorruptedArrayExcept : public VectorExcept
{
public:
    InitVectorCorruptedArrayExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Initialising vector with non-exist array is fobidden!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class EmptyVectorExcept : public VectorExcept
{
public:
    EmptyVectorExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Vector size must be greater than zero!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class NegVectorExcept : public VectorExcept
{
public:
    NegVectorExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Negative vector size is forbidden!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class IndexVectorExcept : public VectorExcept
{
public:
    IndexVectorExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Wrong vector index is set!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class DiffSizeVectorsExcept : public VectorExcept
{
public:
    DiffSizeVectorsExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "2 vectors are of different sizes!") :
        VectorExcept(filename, classname, line, time, info) {}
};

class NotEnoughRangeValuesExcept : public VectorExcept
{
public:
    NotEnoughRangeValuesExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Trying to initialise more values, than actually are!") :
        VectorExcept(filename, classname, line, time, info) {}
};