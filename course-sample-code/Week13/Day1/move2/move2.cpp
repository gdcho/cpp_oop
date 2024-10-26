#include <iostream>
#include <string>

using namespace std;

class student
{
public:
	//regular copy constructor
	student(const student& other) : name{other.name}
	{
		gpa = new double;
		*gpa = *(other.gpa);
	}
	student(const string name, const double gpa) : name{name}
	{
		this->gpa = new double(gpa);
	}
	~student() { delete gpa; }

	friend ostream& operator<<(ostream& os, const student&);
private:
	std::string name;
	double * gpa;
};

ostream& operator<<(ostream& os, const student& s)
{
	os << s.name << " " << *(s.gpa) << "\n";
	return os;
}


int main()
{
	// When this code is done, there are two student objects
	student first_student("Zephryn", 90.0);
	student second_student(first_student); //calls student's copy constructor

    cout << "first student: " << first_student << "\n";
    cout << "second student: " << second_student << "\n";

	return 0;
}
