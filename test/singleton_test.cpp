#include "src/singleton.h"
#include <gtest/gtest.h>

using namespace std;

namespace foo {

class Foo : public util::Singleton<Foo>
{
  public:
    Foo() {}
    virtual ~Foo() {}
};

} // namespace foo

SINGLETON_INIT(foo::Foo);

TEST(Singleton, test)
{
    EXPECT_TRUE(!foo::Foo::getSingletonPtr());
    new foo::Foo();
    EXPECT_TRUE(foo::Foo::getSingletonPtr());

    EXPECT_THROW(new foo::Foo(), std::exception);

    try {
        new foo::Foo();
        EXPECT_TRUE(false);
    } catch (const util::Exception &e) {
        cerr<<"catch exception: "<<e.what()<<endl;
    }
}
