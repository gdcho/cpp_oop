#include <iostream>

class grandparent
{
  public:
	virtual void foo() { std::cout << "grandparent.foo" << std::endl;}
};

class father : virtual public grandparent
{
  public:
    void foo() { std::cout << "father.foo" << std::endl;}
};

class mother : virtual public grandparent
{
  public:
	void foo() { std::cout << "mother.foo" << std::endl;}
};

class child : public father, public mother
{
  public:
    void foo() { std::cout << "child.foo" << std::endl;}

};

int main()
{
	child a;
	grandparent &gp = a;
	gp.foo();
}