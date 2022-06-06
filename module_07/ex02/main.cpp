#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> arr(10);

	std::cout << arr.size() << std::endl;
	std::cout << arr[2] << std::endl;

	return 0;
}
