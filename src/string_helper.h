#ifndef __STRING_HELPER_H__
#define __STRING_HELPER_H__

#include "exception.h"
#include <algorithm>
#include <sstream>

namespace util {

template <typename T>
inline std::basic_string<T>& ltrim(std::basic_string<T> &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

template <typename T>
inline std::basic_string<T>& rtrim(std::basic_string<T> &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

template <typename T>
inline std::basic_string<T> trim(std::basic_string<T> s)
{
    return ltrim(rtrim(s));
}

template <typename T>
inline size_t replace(std::basic_string<T> &str, const std::basic_string<T> &pattern, const std::basic_string<T> &newpat)
{
    size_t count = 0;
    const size_t nsize = newpat.size();
    const size_t psize = pattern.size();

    for(size_t pos = str.find(pattern, 0);
        pos != std::basic_string<T>::npos;
        pos = str.find(pattern, pos+nsize))
    {
        str.replace(pos, psize, newpat);
        count++;
    }

    return count;
}

template <typename T>
inline std::basic_string<T>& uppercase(std::basic_string<T> &str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

template <typename T>
inline std::basic_string<T>& lowercase(std::basic_string<T> &str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

template<typename T>
inline size_t split(const std::basic_string<T> &s, T c, std::vector<std::basic_string<T>> &v)
{
    if(s.size() == 0) {
        return 0;
    }

    typename std::basic_string<T>::size_type i = 0;
    typename std::basic_string<T>::size_type j = s.find(c);

    while(j != std::basic_string<T>::npos) {
        v.push_back(s.substr(i, j - i));
        i = ++j; j = s.find(c, j);
    }

    if(j == std::basic_string<T>::npos) {
        v.push_back(s.substr(i, s.length() - i));
    }

    return v.size();
}


template <typename To, typename From>
inline To to(From source)
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
