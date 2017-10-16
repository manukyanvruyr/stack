#include <vector>

#include <local/stack.hpp>
#include <tests/type_checker.hpp>
#include <base/exception.hpp>

namespace test
{

void assert(const bool c)
{
    if (!c) {
	throw base::exception();
    }
}

namespace
{

template <typename T>
class Alloc : public std::allocator<T>
{
};

void test_container_type()
{
    assert(std::is_same<local::stack<int>::container_type, std::deque<int>>::value);
    assert(std::is_same<local::stack<int, std::vector>::container_type, std::vector<int>>::value);
    assert(!std::is_same<local::stack<int, std::vector>::container_type, std::vector<double>>::value);
    assert(!std::is_same<local::stack<int, std::vector, Alloc<int>>::container_type, std::vector<int>>::value);
    assert(std::is_same<local::stack<int, std::vector, Alloc<int>>::container_type, std::vector<int, Alloc<int>>>::value);
}

}

void run()
{
    test_container_type();
}

}
