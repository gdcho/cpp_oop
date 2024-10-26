#include <iostream>

template <class T>
T get_max(T a, T b)
{
    return (a > b ? a : b);
}

int main()
{
	int first{1};
	double second{3.14};
	long third{22l};
	double maximum = get_max(first, second);

	//auto maximum = get_max<double>(first, second);
	//double maximum = get_max<double>(first, second);
	//int maximum = get_max<int>(first, second);
	//auto maximum = get_max(first, second);
	std::cout << maximum << '\n';

}
