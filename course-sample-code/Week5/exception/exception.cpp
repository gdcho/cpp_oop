// using standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception
{
public:
 const char* what() const noexcept
  {
    return "My exception happened";
  }
};

int main () {
  try
  {
    throw myexception();
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}