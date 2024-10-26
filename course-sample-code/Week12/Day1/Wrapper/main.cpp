#include <iostream>

using namespace std;

/*
This code depicts how a wrapper can be used to wrap around an object and add
        behaviour to it without the use of inheritance.

A wrapper must fulfill the following 2 conditions:
- Implement the same interface as the object being wrapped.
- Be composed of the object being wrapped. (Have the object being
wrapped as one of its attributes.)
*/

class StudentInterface {
public:
    virtual void study() = 0;
    virtual void procrastinate() = 0;
    virtual void print() = 0;
    virtual ~StudentInterface() = default;
};

class Student : public StudentInterface {
/*
Represents a student that studies and procrastinates. The student has a
name, age, a school, happiness and knowledge score. This class
        implements the following interface:
+ study()
+ procrastinate
+ __str__
*/
private:
    string name;
    int age;
    string school;
    int knowledge;
    int happiness;

public:
    Student(string name, int age, string school) : name(name), age(age), school(school) {
        knowledge = 0;
        happiness = 100;
    }

    void study() {
        cout << "I'm studying" << endl;
        knowledge += 10;
        happiness -= 5;
    }

    void procrastinate() {
        cout << "I'm procrastinating" << endl;
        happiness += 10;
    }

    void print() {
        cout << "name: " << name
             << " Age: " << age
             << " School: " << school
             << " Knowledge: " << knowledge
             << " Happiness: " << happiness << endl;
    }
};

class ProcrastinatingStudentDecorator : public StudentInterface {
/*
 *     A wrapper that wraps around a student. Adds additional procrastination
    behaviour to a Student without using inheritance.

    A wrapper implements the same interface as the object being wrapped
    around (wrappee). All implementations of that interface just call
    the corresponding methods in the wrappee.
 */
private:
    Student *student; //wrapping around student class

public:
    ProcrastinatingStudentDecorator(Student *student) : student(student) {}

    void study() {
        /*
         * Makes the student procrastinate before making the student study.
          :return: None
         */
        student->procrastinate();
        student->study();
    }

    void procrastinate() {
        student->procrastinate();
    }

    void print() {
        student->print();
    }
    ~ProcrastinatingStudentDecorator(){delete student;}
};

int main() {
/*
    Creates the appropriate student based on user input and makes them study.
 */
    int numChoice;
    cout << "Does the student procrastinate before studying? 1 = YES, 0 = NO" << endl;
    cin >> numChoice;
    bool isProcrastinatingStudent = numChoice == 1;

    StudentInterface* student = new Student("Jeff", 99, "BCIT");
    if (isProcrastinatingStudent)
        student = new ProcrastinatingStudentDecorator((Student*)student);

    student->study();
    delete student;

    return 0;
}