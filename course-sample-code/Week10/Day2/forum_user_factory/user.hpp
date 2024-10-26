//
// Created by A00257049 on 2020-11-06.
//

#ifndef FORUM_USER_FACTORY_USER_HPP
#define FORUM_USER_FACTORY_USER_HPP

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

//This enum specifies the different distinct permission types.
enum Permission {
    NONE,
    READ,
    LIKE,
    SHARE,
    FLAG,
    WRITE
};

/*
    Defines the User interface. This is the Product that the Factory
    Pattern creates. A user has a username, password, date_joined and a
    list of permissions.
 */
struct User {
    string username;
    string password;
    vector<Permission> permissions;
    string date_joined;

    User(string username, string password) : username(username), password(password) {
        // declaring argument of time()
        time_t my_time = time(NULL);
        date_joined = ctime(&my_time);
    }

    bool authenticate(const string& password_input) {
        return password_input == password;
    }

    pair<string, string> get_profile() {
        return make_pair(username, date_joined);
    }

    virtual string getString() const {
        return "Username: ";
    }
    friend ostream& operator<<(ostream& os, const User& u)
    {
        os << u.getString() << u.username << " Date joined: " << u.date_joined << endl;
        return os;
    }
};

//This type of user can Read, Like, Share and Flag posts.
struct Guest : User {
    Guest(string username, string password) : User(username, password) {
        permissions.push_back(Permission::READ);
        permissions.push_back(Permission::LIKE);
        permissions.push_back(Permission::SHARE);
        permissions.push_back(Permission::FLAG);
    }

    string getString() const override {
        return "Guest User: ";
    }

};

//This type of user can Read, Write, Like, Share, and Flag posts
struct Member : User {
    Member(string username, string password) : User(username, password) {
        permissions.push_back(Permission::READ);
        permissions.push_back(Permission::LIKE);
        permissions.push_back(Permission::SHARE);
        permissions.push_back(Permission::FLAG);
        permissions.push_back(Permission::WRITE);
    }

    string getString() const override {
        return "Member User: ";
    }
};

#endif //FORUM_USER_FACTORY_USER_HPP
