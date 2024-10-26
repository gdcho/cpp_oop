#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
class Name
{
private:
	std::string first;
public:
    Name(std::string first) : first(first)
    {
        if (first.length() == 0)
        {
            throw std::invalid_argument("No first name!");
        }
    }
};

int main()
{
    try {
        std::string a;
        //Name{"Jeff"};
        Name{a};
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}