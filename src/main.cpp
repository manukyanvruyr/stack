#include <iostream>

#include <base/exception.hpp>
#include <tests/type_checker.hpp>

int main()
{
    try {
	test::run();
	std::cout << "Passed\n";
    } catch(const base::exception&) {
	std::cout << "Failed\n";
    } catch(const std::exception&) {
	std::cout << "Unexcpected std exception is thrown\n";
    } catch(...) {
	std::cout << "Unexcpected exception is thrown\n";
    }
}
