#include <iostream>
#include <string>

using namespace std;

class person 
{
  public:
    person()
    {
        cout << "person default constructor" << endl;
    }
    person(const string& name) : name(name)
    {
        cout << "person 1-param constructor" << endl;
    }

    void set_name(const string& n) { name = n; }
    string get_name() const { return name; }
    
    virtual void all_info() const
      { cout << "[person name=" << name << "]" << endl; }
    
  private:
    string name;
};

class student : public virtual person
{
  public:
    student(const string& name, const string& passed) 
      : person(name), passed(passed) {cout << "student constructor" << endl;}
    
    virtual void all_info() const override
    { 
       cout << "[student name=" << get_name() << "]" << endl; 
       cout << "    I passed the following grades: " << passed << endl;
    }

  private:
    string passed;
};

class mathematician : public virtual person
{
  public:
    mathematician(const string& name, const string& proved) 
      : person(name), proved(proved) {cout << "mathematician constructor" << endl;}
    virtual void all_info() const override
    {
       person::all_info();
       cout << "    I proved: " << proved << endl;
    }
  private:
    string proved;
};

class math_student : public student, public mathematician
{
  public:
    math_student(const string& name, const string& passed, const string& proved)
      : person(name), student(name, passed), mathematician(name, proved) {}
      //: student(name, passed), mathematician(name, proved), person(name) {} //hacky call to person constructor
    virtual void all_info() const override
    {
       student::all_info();
       mathematician::all_info();
       person::all_info();
    }
};

int main ()
{
    math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
    bob.all_info();
    return 0 ;
}