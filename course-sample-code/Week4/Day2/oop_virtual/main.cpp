#include <iostream>
#include <string>

using namespace std;

class person
{
  public:
    person() = default;
    person(const std::string& name) : name(name) {}

    void set_name(const std::string& n) { name = n; }
    std::string get_name() const { return name; }
    virtual void all_info() const { std::cout << "My name is " << name << std::endl; }

  private:
    std::string name;
};

class student : public person
{
  public:
    student(const std::string& name, const std::string& passed)
      : person(name), passed(passed) {}
     void all_info() const override {
	     person::all_info();
	     std::cout << "I passed the following courses: " << passed << "\n\n" << std::endl;
    }
  private:
    std::string passed;
};


void spy_on(const person& p)
{    p.all_info(); }


int main ()
{
    person molly("Molly Markson");
    //cout << "Printing Molly's info\n";
    //molly.all_info();

    student tara("Tara Tomson", "Algebraic Analysis");
    //cout << "Printing Tara's info\n";
    //tara.all_info();

    cout << "Creating a copy, a reference, and a pointer:\n";
    person  p(tara);
    person& pr = tara; // or pr(tara)
    person* pp = &tara; // or pp(&tara)

//    cout << "(copy) p.all_info();\n";
//    p.all_info();
//    cout << "(reference) pr.all_info();\n";
//    pr.all_info();
//    cout << "(pointer) pp.all_info();\n";
//    pp->all_info();
//
    spy_on(tara);

    return 0 ;
}
