#pragma once

#include <exception>
#include <string>
#include <sstream>

#define STR_CNT 512

// BASE EXCEPT
class BaseExcept : public std::exception
{
public:
    BaseExcept(const char* filename, const char* classname,
        int line, const char* time, const char* info = "Error")
    {
        std::stringstream ss;
        ss << info << "\nFile: " << filename << "\nClass: " << classname << "\nLine: " << line
            << "\nTime: " << time;
        strncpy(except_info, ss.str().c_str(), STR_CNT);
        except_info[STR_CNT - 1] = '\0';
    }

    virtual const char* get_except_info() const noexcept
    {
        return except_info;
    }

protected:
    char except_info[STR_CNT];
};