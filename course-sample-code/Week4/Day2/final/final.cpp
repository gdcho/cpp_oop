class Base
{
public:
    virtual void foo();
};

class A : Base
{
public:
    void foo() final; // A::foo is overridden and it is the final override
    void bar() final; // Error: non-virtual function cannot be overridden or be final
};
 
class B final : A // class B is final, cannot be a parent class.
{
public:
    void foo() override; // Error: foo cannot be overridden as it's final in A
};
 
class C : B // Error: B is final
{
};

int main()
{
	return 0;
}