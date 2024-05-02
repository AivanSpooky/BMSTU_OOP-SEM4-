#pragma once

#include "exception.h"

class RemoteObjExcept : public IterExcept
{
public:
    RemoteObjExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Attempt to work with a remote object!") :
        IterExcept(filename, classname, line, time, info) {}
};

class InvalidIterExcept : public IterExcept
{
public:
    InvalidIterExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Attempt to use invalid iterator!") :
        IterExcept(filename, classname, line, time, info) {}
};