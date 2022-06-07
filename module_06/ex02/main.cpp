#include "identify.hpp"
#include <iostream>

int main() {
	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		Base *p = generate();
		identify(p);
		std::cout << " ";
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	return 0;
}
