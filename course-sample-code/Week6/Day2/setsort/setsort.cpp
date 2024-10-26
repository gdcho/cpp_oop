#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
int main()
{
	vector<string> v = {"dog","cat","cat","apple","book","dog"};
	set<string> s;

	for (string word : v)
	{
		s.insert(word);
	}

	//print out contents of set
	for (auto it = s.begin(); it != s.end(); ++it) { // use auto!
		cout << *it << ' ';
	}
	cout << endl;
	
}