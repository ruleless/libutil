#ifndef __UTIL_SINGLETON_H__
#define __UTIL_SINGLETON_H__

#include "exception.h"
#include <assert.h>

namespace util {

template <typename T>
class Singleton
{
  public:
    Singleton()
    {
        if (instance_) {
            throw Exception("Singleton: instance has already been created");
        }

#if defined(_MSC_VER) && _MSC_VER < 1200
        int offset = (int)(T *)1 - (int)(Singleton<T> *)(T *)1;
        instance_ = (T*)((int)this + offset);
#else
        instance_ = static_cast<T *>(this);
#endif
    }

    ~Singleton() { assert(instance_);  instance_ = NULL; }

    static T &getSingleton(void)
    {
        assert(instance_);
        return (*instance_);
    }
    static T *getSingletonPtr(void)
    {
        return instance_;
    }

  protected:
    static T *instance_;
};

} // namespace util

#define SINGLETON_INIT(T) template<> T* util::Singleton<T>::instance_ = NULL;

#endif // __UTIL_SINGLETON_H__
