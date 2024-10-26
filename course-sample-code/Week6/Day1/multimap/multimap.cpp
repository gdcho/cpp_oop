
#include <iostream>
#include <map>
#include <iterator>

using namespace std;
//annoying to type out entire iterator, use typedef to shorten it
int main()
{
    multimap<string, string> nameAndNumber;

    nameAndNumber.insert(make_pair("Tom", "604-123-4567"));
    nameAndNumber.insert(make_pair("Harry", "604-999-9999"));
    nameAndNumber.insert(make_pair("Tom", "604-888-8883"));
    nameAndNumber.insert(make_pair("Tom", "604-888-8882"));
    nameAndNumber.insert(make_pair("Chris", "***-*******"));
    nameAndNumber.insert(make_pair("Tom", "604-887-8881"));

    //notice pairs are sorted based on keys (Person's name in this case)
    for (auto pairs = nameAndNumber.begin();
         pairs != nameAndNumber.end(); ++pairs)
    {
        cout << pairs->first << " phone number is " << pairs->second << endl;
    }

//    cout << endl << "Phone numbers of Tom" << endl;

//    //Method 1 - find duplicates using 1 iterator and size
//    multimap<string, string>::iterator PhoneValues = nameAndNumber.find("Tom");
//    int count = nameAndNumber.count("Tom");
//    for (int i = 0; i < count; i++)
//    {
//        cout << PhoneValues->first << " " << PhoneValues->second << endl;
//        ++PhoneValues;
//    }

////    Method 2 - find duplicates using 2 iterators
////     pairIters.first = iterator pointing to first appearance of Tom
////     pairIters.second = iterator pointing to one past last appearance of Tom
//
//    pair <multimap<string, string>::iterator, multimap<string, string>::iterator> pairIters = nameAndNumber.equal_range("Tom");
//
////    typedef multimap<string, string>::iterator mapIterator;
////    pair <mapIterator, mapIterator> pairIters = nameAndNumber.equal_range("Tom");
//
//    //ret is a pair containing iteratorBeginning, iteratorEnd>
//    for (auto it=pairIters.first; it!=pairIters.second; ++it)
//        std::cout << it->first << " "<< it->second << endl;
//    std::cout << '\n';

    return 0;
}