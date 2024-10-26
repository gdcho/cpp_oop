#include <iostream>
#include <vector>
using namespace std;

/*
Depicts the factory pattern in action as it generates
different kinds of users for a hypothetical website.
 */

#include "user.hpp"
#include "factory.hpp"

/*
    The Client system in the factory pattern. Depends on the UserFactory
    class to create user accounts.
 */
struct Forum {
    string name;
    vector<User*> users;
    Forum(string name) : name(name) {}

    /*
        Register_user is responsible for displaying the account
        creation menu and returning the appropriate user factory.
     */
    UserFactory* register_user() {
        cout << "Welcome! Do you want to make an account or continue as a guest?" << endl;
        cout << "1. Make Account" << endl;
        cout << "2. Continue as Guest" << endl;
        int choice = 0;
        cout << "Enter your choice (1-2)" << endl;
        cin >> choice;

        UserFactory *factory_class;
        if(choice == 1)
            factory_class = new MemberUserFactory;
        else
            factory_class = new GuestUserFactory;

        return factory_class;
    }

    /*
        This function doesn't know what kind of factory it will receive
        As a result it doesn't depend on the concrete MemberUserFactory or GuestUserFactory
        to create the user
     */
    void add_user() {
        UserFactory *factory = register_user(); //get a member or guest factory
        users.push_back(factory->create_user());
        delete factory;
    }

    ~Forum() {
        for (User *u : users)
        {
            delete u;
        }
    }
};

int main() {
    Forum my_forum = Forum("Discussion Forum");
    my_forum.add_user();
    my_forum.add_user();
    for(User *u : my_forum.users) {
        cout << *u;
    }
    return 0;
}