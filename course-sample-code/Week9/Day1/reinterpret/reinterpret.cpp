#include <iostream>

using namespace std;
int main()
{
	struct pair { short a; short b; };
	long value = 0xA224B118;
	long *vPtr = &value;
	pair * pd = reinterpret_cast<pair *>(vPtr);
	cout << "value: " << hex << value << endl;
	cout << "pair a,b: " << hex << pd->a << " " << hex << pd->b << endl;
	pd->a = 0xaaaa;
	cout << "pair a,b: " << hex << pd->a << " " << hex << pd->b << endl;

	cout << "value: " << hex << value << endl;

}