#include <iostream>
#include <exception>

using namespace std;

class A {
public:
    string message()
    {
        return "random class error";
    }
};

struct myexception : public exception
{
    virtual const char * what () const noexcept
    {
        return "C++ Exception";
    }
};

int main() {
   try
   {
      //throw myexception();
       //throw A{};
       throw "message error";
   }
   catch(myexception& e)
   {
      std::cout << "myexception caught" << std::endl;
      std::cout << e.what() << std::endl;
   }
   catch(std::exception& e)
   {
      //Other errors
   }
   catch (A& a)
   {
       cout << a.message() << '\n';
   }
   catch (const char *c)
   {
       cout << c << '\n';
   }
}