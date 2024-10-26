#include <iostream>
#include <string>
#include <iomanip>

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

    void set_name(const string& n) { name= n; }
    string get_name() const { return name; }
    
    virtual void all_info() const
    {
      cout << "[person name=" << name << "]" << endl;
    }
    
  protected:
    string name;
};

class student : public virtual person
{
  public:
    student(const string& name, const string& passed)
    : person(name), passed(passed)
    {
      cout << "student two-param constructor" << endl;
    }
  protected:
    student(const string& passed) : passed(passed)
    {
      cout << "student one-param constructor" << endl;
    }

    void my_infos() const
    {
      cout << "I passed: " << passed << endl;
    }
  public:
    virtual void all_info() const override
    {
      person::all_info();
      my_infos();
    }
  private:
    string passed;
};

class mathematician : public virtual person
{
  public:
    mathematician(const string& name, const string& proved) 
    : person(name), proved(proved)
    {
      cout << "mathematician two-param constructor" << endl;
    }
  protected:
    mathematician(const string& proved) : proved(proved)
    {
      cout << "mathematician one-param constructor" << endl;
    }

    void my_infos() const
    {
      cout << "I proved: " << proved << endl;
    }	
  public:
    virtual void all_info() const override
    {
	     person::all_info();
	     my_infos();
    }
  private:
    string proved;
};

class math_student : public student, public mathematician
{
  public:
    math_student(const string& name,
                 const string& passed, 
                 const string& proved)
    : person(name), student(passed), mathematician(proved)
     // : student(name, passed), mathematician(name, proved) //won't call person's 1 param constructor
    {
      cout << "math_student 3-param constructor" << endl;
    }
    virtual void all_info() const override
    {
      student::all_info();
      mathematician::my_infos();
    }
};

int main () 
{
    math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
    bob.all_info();

    mathematician m("Jeff", "test");

    return 0 ;
}
