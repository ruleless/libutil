#ifndef __STRING_HELPER_H__
#define __STRING_HELPER_H__

#include "exception.h"
#include <sstream>

namespace util {

template <typename To, typename From>
To to(From source)
{
    std::stringstream interpreter;
    To target;

    if (!(interpreter << source) || !(interpreter >> target) || !(interpreter.eof())) {
        throw Exception("to<> fail");
    }
    return target;
}

} // namespace util

#endif // __STRING_HELPER_H__
