#include <iostream>

using namespace std;

class Base
{
  public:
    Base ()
      { cout << "Base: no parameters\n"; }
    Base (int a)
      { cout << "Base: int parameter\n"; }
};

class Derived_One : public Base
{
  public:
    Derived_One (int a) // LOOK AT THIS!
      { cout << "Derived_One: int parameter\n\n";}
};

class Derived_Two : public Base
{
  public:
    Derived_Two (int a) : Base (a) // COMPARE TO THIS!
      { cout << "Derived_Two: int parameter\n\n"; }
};

int main ()
{
  Derived_One first_child(0);
  Derived_Two second_child(0);
  
  return 0;
}