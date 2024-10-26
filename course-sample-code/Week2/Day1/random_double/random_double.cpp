#include <random>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	const int loops{10};
	const int lowerbound{10};
	const int upperbound{20};
	default_random_engine generator(time(0));
	uniform_real_distribution<double>
		distribution(lowerbound, upperbound);

	for (int i = 0; i < loops; ++i) {
		double my_random = distribution(generator);
		cout << my_random << '\n';
	}
}

