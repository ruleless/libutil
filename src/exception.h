#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
#include <exception>

namespace util {

class Exception : public std::exception
{
  public:
    Exception() : message_() {}

    Exception(const std::string &message) : message_(message) {}

    virtual ~Exception() throw() {}

    virtual const char *what() const throw()
    {
        if (message_.empty()) {
            return "Default Exception.";
        } else {
            return message_.c_str();
        }
    }

  protected:
    std::string message_;
};

} // namespace util

#endif // __EXCEPTION_H__
