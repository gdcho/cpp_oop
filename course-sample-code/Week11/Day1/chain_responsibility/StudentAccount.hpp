//
// Created by A00257049 on 2020-11-11.
//

#ifndef CHAIN_RESPONSIBILITY_STUDENTACCOUNT_HPP
#define CHAIN_RESPONSIBILITY_STUDENTACCOUNT_HPP

#include <iostream>
#include <vector>
using namespace std;
/*
    Encapsulates student account information. This would be the central
    student record in a school.
 */
struct StudentAccount {
    string student_name;
    int student_age;
    string student_id;
    int fees_due;
    string program;
    vector<string> current_courses;

    StudentAccount() = default;
    StudentAccount(string name, int age, string id, string prog) {
        this->student_name = name;
        this->student_age = age;
        this->student_id = id;
        this->fees_due = 0;
        this->program = prog;
    }
};

#endif //CHAIN_RESPONSIBILITY_STUDENTACCOUNT_HPP
