#include <random>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	const int loops = 10;
	const int lowerbound = 10;
	const int upperbound = 20;

	random_device rd;
	mt19937 generator(rd()); //rd creates random seed
	uniform_int_distribution<>
		distribution(lowerbound, upperbound);

	for (int i = 0; i < loops; ++i) {
		int my_random = distribution(generator);
		cout << my_random << '\n';
	}
}

