#include <utility>
#include <iostream>

using namespace std;
int main()
{
	pair<string, int> myPair;
	myPair.first = "hi";
	myPair.second = 7;

	pair<int, double> p(1, 3.14);

	pair<char, char> p2 = make_pair('a', 'b');

	cout << p.first << ' ' << p.second << std::endl;
	cout << p2.first << ' ' << p2.second << std::endl;

	p2.first = 'z';
	p2.second = 'h';

    cout << p2.first << ' ' << p2.second << std::endl;
}