#include <string>
#include <exception>
#include <iostream>
 
int main()
{
	try
	{
		//trying to start copying from index 10. Doesn't exist
    	std::string("abc").substr(10); // throws std::length_error
	}
	catch(const std::exception& e)
	{
    	std::cout << e.what() << '\n';
    	//throw;   // rethrows the exception object of type std::length_error
	}
}