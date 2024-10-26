#include <utility>
#include <iostream>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    map<string, string> nameAndNumbers;

    //approach 1, make a pair first, then insert
    nameAndNumbers.insert(pair<string, string>("Tom","604-123-4567"));

    //approach 2, the super long version using the value_type typedef. value_type is of type pair behind the scenes
    //nameAndNumbers.insert(map<string, string>::value_type("Tom", "604-123-4567"));

    //approach 3, insert pair using built-in make_pair function
    //nameAndNumbers.insert(make_pair("Tom", "604-123-4567"));

    //add Harry and attempt to add duplicate Tom key/value pairs
    nameAndNumbers.insert(make_pair("Harry", "604-999-9999"));
    nameAndNumbers.insert(make_pair("Tom", "604-888-8888"));
    nameAndNumbers.insert(make_pair("Tom", "604-888-8228"));
    nameAndNumbers.insert(make_pair("Tom", "604-8888"));
    nameAndNumbers.insert(make_pair("Tom", "604-818888"));

    cout << endl << "Phone numbers of people Named Tom" << endl;

    //get iterator pointing to Tom and print
    map<string, string>::iterator oneNumber = nameAndNumbers.find("Tom");
    cout << oneNumber->first << " - " << oneNumber->second;

//    //print out everything in map
//    for(auto it = nameAndNumbers.begin(); it != nameAndNumbers.end(); ++it)
//    {
//        cout << it->first << " - " << it->second << endl;
//    }

    return 0;

}