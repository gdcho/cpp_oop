#include <iostream>
#include <string>

#include "entry.hpp"

int main()
{
	Entry<std::string, int> e("MyKey", 999);
	std::cout << e.key << " " << e.value;
}