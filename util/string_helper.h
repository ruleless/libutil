#ifndef __STRING_HELPER_H__
#define __STRING_HELPER_H__

#include "exception.h"
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

namespace util {

template <typename CharT>
inline std::basic_string<CharT>& ltrim(std::basic_string<CharT> &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

template <typename CharT>
inline std::basic_string<CharT>& rtrim(std::basic_string<CharT> &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

template <typename CharT>
inline std::basic_string<CharT> trim(std::basic_string<CharT> s)
{
    return ltrim(rtrim(s));
}

template <typename CharT>
inline size_t replace(std::basic_string<CharT> &str,
                      const std::basic_string<CharT> &pattern,
                      const std::basic_string<CharT> &newpat)
{
    size_t count = 0;
    const size_t nsize = newpat.size();
    const size_t psize = pattern.size();

    for(size_t pos = str.find(pattern, 0);
        pos != std::basic_string<CharT>::npos;
        pos = str.find(pattern, pos+nsize))
    {
        str.replace(pos, psize, newpat);
        count++;
    }

    return count;
}

template <typename CharT>
inline size_t replace(std::basic_string<CharT> &str,
                      const CharT *pattern,
                      const CharT *newpat)
{
    size_t count = 0;
    const size_t nsize = strlen(newpat);
    const size_t psize = strlen(pattern);

    for(size_t pos = str.find(pattern, 0);
        pos != std::basic_string<CharT>::npos;
        pos = str.find(pattern, pos+nsize))
    {
        str.replace(pos, psize, newpat);
        count++;
    }

    return count;
}

template <typename CharT>
inline std::basic_string<CharT>& uppercase(std::basic_string<CharT> &str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

template <typename CharT>
inline std::basic_string<CharT>& lowercase(std::basic_string<CharT> &str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

template <typename CharT>
inline size_t split(const std::basic_string<CharT> &s,
                    CharT c,
                    std::vector<std::basic_string<CharT>> &v)
{
    if(s.size() == 0) {
        return 0;
    }

    typename std::basic_string<CharT>::size_type i = 0;
    typename std::basic_string<CharT>::size_type j = s.find(c);

    while(j != std::basic_string<CharT>::npos) {
        v.push_back(s.substr(i, j - i));
        i = ++j; j = s.find(c, j);
    }

    if(j == std::basic_string<CharT>::npos) {
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
