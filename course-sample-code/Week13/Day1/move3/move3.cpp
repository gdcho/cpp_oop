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
		cout << "Copy constructor" << endl;
	}

    //move constructor
    //student(student&& other) : name{static_cast<string&&>(other.name)} //does the same thing as move()
    student(student&& other) : name(move(other.name))
    {
	    //name = move(other.name); //string = operator probably has overloaded version takes in r value
	    //Don't want to create new memory and copy gpa
        //gpa = new double;
        //*gpa = *(other.gpa);

        gpa = other.gpa; //make our gpa pointer, point to other student's existing gpa memory
        other.gpa = nullptr; //other student doesn't need gpa pointer anymore, so set it to nullptr
        cout << "Move constructor" << endl;
    }

	student(const string name, const double gpa) : name{name}
	{
		this->gpa = new double(gpa);
	}

	~student() { if (gpa) { delete gpa; } }

	friend ostream& operator<<(ostream& os, const student&);
private:
	std::string name;
	double * gpa;
};

ostream& operator<<(ostream& os, const student& s)
{
	os << s.name;
	if (s.gpa != nullptr)
	{
		os << " " << *(s.gpa);
	}
	os << "\n";
	return os;
}


int main()
{
	// When this code is done, there are two student objects
	// but the contents of the rvalue have been 'moved'
	student first_student("Zephryn", 90.0);

    //student second_student(first_student); //calls student copy constructor
	student second_student(move(first_student)); //calls student move constructor

	cout << "first student: " << first_student << "\n";
	cout << "second student: " << second_student << "\n";

	return 0;
}

