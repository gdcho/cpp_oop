#include <vector>
#include <iostream>
#include <string>

using namespace std;
template<typename Iterator>
bool is_ascending(Iterator begin, Iterator end)
{
    //1 2 3 4 5
	Iterator i, tmp;
	for (i = begin; i != end-1; ++i) {
		tmp = i + 1;
		if (*i > *tmp) {
			return false;
		}
	}
	return true;
}

int main()
{
	std::vector<int> v1 { 1, 2, 3, 4, 5};
	std::vector<int> v2 { 5, 4, 3, 2, 1};
    std::vector<string> v3 { "a", "b", "c", "d", "e"};
    std::vector<string> v4 { "e", "d", "c", "b", "a"};

	bool ascending1 = is_ascending(v1.begin(), v1.end());
	bool ascending2 = is_ascending(v2.begin(), v2.end());
    bool ascending3 = is_ascending(v3.begin(), v3.end());
    bool ascending4 = is_ascending(v4.begin(), v4.end());

	std::cout << std::boolalpha << ascending1 << std::endl;
	std::cout << std::boolalpha << ascending2 << std::endl;
    std::cout << std::boolalpha << ascending3 << std::endl;
    std::cout << std::boolalpha << ascending4 << std::endl;

	return 0;
}