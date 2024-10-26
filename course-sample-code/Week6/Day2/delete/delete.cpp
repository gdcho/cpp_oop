#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <random>

using namespace std;
namespace templates {
	template <typename InputIterator, typename OutputIterator>
	OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
	{
		while (first != last) {
			result = *first++;
		}
		return result;
	}
}

int main()
{
	list<int> lst;
	for (int i = 0; i < 10; ++i) {
		int randomNum = 1 + (rand() % 100);
		lst.push_back(randomNum);
	}

	cout << "Before: " << endl;
	templates::copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " ")); //our own custom copy function
	//copy(iteratorToBeginning, iteratorToEnd, iteratorToOutput)
	//copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " ")); //built in copy algorithm

	cout << endl;


	// JAVA DEVELOPERS ARE TEARING THEIR HAIR OUT ABOUT THIS
	list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); ) // Don't increment here...
	{
		//erase values greater than 10
		if (*it > 10) {
			it = lst.erase(it); // erases element and returns iterator to next element here...
		}
		else {
			++it; // Or increments here!
		}
	}

	cout << "After: " << endl;
	templates::copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));

}