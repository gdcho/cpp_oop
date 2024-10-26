//
// Created by A00257049 on 2020-11-06.
//

#ifndef FORUM_USER_FACTORY_FACTORY_HPP
#define FORUM_USER_FACTORY_FACTORY_HPP

#include "user.hpp"

/*
    The UserFactory class is the base class that the rest of the system
    depends on. It defines a factory interface that creates a user.
 */
struct UserFactory {
    virtual User* create_user() = 0;
};

//The GuestFactory is responsible for creating Guests USer Accounts.
struct GuestUserFactory : UserFactory {
    User* create_user() override {
        return new Guest("","");
    }
};

/*
    The MemberUserFactory is responsible for creating Member User
    Accounts
 */
struct MemberUserFactory : UserFactory {
    User* create_user() override {
        string username;
        string password;
        cout << "Enter username: " << endl;
        cin >> username;
        cout << "Enter password: " << endl;
        cin >> password;
        return new Member(username, password);
    }
};

#endif //FORUM_USER_FACTORY_FACTORY_HPP
