#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	const int loops = 10;
	const int upperbound = 100;
	srand (time(NULL));

	for (int i = 0; i < loops; ++i) {
		int my_int = rand() % upperbound;
		double zero_to_one = rand() / (double) RAND_MAX;	
		cout << my_int << " " << zero_to_one << '\n';
	}
}

