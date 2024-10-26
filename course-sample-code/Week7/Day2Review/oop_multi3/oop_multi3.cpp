#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ClassA 
{
  public:
    ClassA()
    {
      cout << "ClassA default constructor" << endl;
    }
    ClassA(const string& name) : name(name)
    {
      cout << "ClassA 1-param constructor" << endl;
    }
    
    virtual void all_info() const
    {
      cout << "[ClassA name=" << name << "]" << endl;
    }
    
  protected:
    string name;
};

class ClassB : public virtual ClassA
{
  public:
    ClassB(const string& name, const string& data)
    : ClassA(name), data(data)
    {
      cout << "ClassB two-param constructor" << endl;
    }
  protected:
    ClassB(const string& data) : data(data)
    {
      cout << "ClassB one-param constructor" << endl;
    }

    void my_infos() const
    {
        cout << name << " has Class B's data: " << data << endl;
    }
  public:
    virtual void all_info() const override
    {
      ClassA::all_info();
      my_infos();
    }
  private:
    string data;
};

class ClassC : public virtual ClassA
{
  public:
    ClassC(const string& name, const string& extra_data) 
    : ClassA(name), extra_data(extra_data)
    {
      cout << "ClassC two-param constructor" << endl;
    }
  protected:
    ClassC(const string& extra_data) : extra_data(extra_data)
    {
      cout << "ClassC one-param constructor" << endl;
    }

    void my_infos() const
    {
      cout << name << " has Class C's extra_data: " << extra_data << endl;
    }	
  public:
    virtual void all_info() const override
    {
	     ClassA::all_info();
	     my_infos();
    }
  private:
    string extra_data;
};

class ClassD : public ClassB, public ClassC
{
  public:
    ClassD(const string& name,
                 const string& data, 
                 const string& extra_data)
    : ClassA(name), ClassB(data), ClassC(extra_data) //ClassD is responsible for calling ClassA's contructor directly because of virtual inheritance
    //  : ClassB(name, data), ClassC(name, extra_data) //won't call ClassA's 1 param constructor when using virtual inheritance. It will call ClassA's default constructor
    {
      cout << "ClassD 3-param constructor" << endl;
    }
    virtual void all_info() const override
    {
      ClassB::all_info();
      ClassC::my_infos();
    }
};

int main () 
{
    ClassD d("Derek", "Algebra", "Fermat's Last Theorem");
    //d.all_info();

    //ClassC c("Clifford", "test"); //can still instantiate ClassC directly

    return 0 ;
}
