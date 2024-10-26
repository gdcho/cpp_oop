#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a = 64;
	a <<= 2;
	cout << a << endl;

	double pi = 3.1459268535;
	double cake = 8.314462618;

	cout << setw(10) << pi << " " << cake << "\n";

	streamsize precision = cout.precision();
	cout << "precision: " << cout.precision() << endl;

	cout << setprecision(3) << pi << " " << cake << "\n";

	cout << setprecision(precision) << pi << " " << cake << "\n";

	streamsize prec = cout.precision();

	int m, n;
	cout << "Enter 2 numbers\n";
	cin >> m >> n;
	cout << "m: " << m << endl;
	cout << "n: " << n << endl;
}