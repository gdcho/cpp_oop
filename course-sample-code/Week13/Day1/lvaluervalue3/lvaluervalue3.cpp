#include <iostream>
struct Person {
    std::string Name;
    int Age; 
};

int main()
{
    Person person;
    person.Name = "Trixie"; // person.Name is an lvalue
    
    const char * name = "Bart"; 	// name is an lvalue
    
    return 0;
}
