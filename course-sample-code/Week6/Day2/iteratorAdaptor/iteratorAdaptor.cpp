#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    istringstream str("0.1 0.2 0.3 0.4"); //string streams are great! but they don't have built in iterators

    //prints contents of str to the screen by copying contents of str to cout.
    //copy(iteratorToBeginning, iteratorToEnd, outputIterator);
    copy(istream_iterator<double>(str), //istream_iterator points to 0.1, similar to vector.begin()
                     istream_iterator<double>(), //end-of-stream iterator, similar to vector.end()
                     ostream_iterator<double>(cout, "*")); //destination of copy is cout with " " in between
    return 0;
}