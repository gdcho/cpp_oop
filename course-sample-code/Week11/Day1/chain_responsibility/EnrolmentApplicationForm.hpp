//
// Created by A00257049 on 2020-11-11.
//

#ifndef CHAIN_RESPONSIBILITY_ENROLMENTAPPLICATIONFORM_HPP
#define CHAIN_RESPONSIBILITY_ENROLMENTAPPLICATIONFORM_HPP

#include <iostream>
#include "StudentAccount.hpp"
using namespace std;
/*
    The Enrolment application form contains all the data the student
    filled out on the web enrolment system as well as a reference to
    the student account that was logged into while filling out this
    form.
 */
struct EnrolmentApplicationForm {
    string name;
    string age;
    string student_id;
    StudentAccount student_account;
    vector<string> courses_for_enrolment;
    int fees_paid;
    int enrolment_year;

    EnrolmentApplicationForm(string name, int age, string student_id,
                             vector<string> courses_for_enrolment, StudentAccount student_account,
                             bool enrolment_fees_paid, int school_year) {
        this->name = name;
        this->age = age;
        this->student_id = student_id;
        this->student_account = student_account;
        this->courses_for_enrolment = courses_for_enrolment;
        this->fees_paid = enrolment_fees_paid;
        this->enrolment_year = school_year;
    }
};

#endif //CHAIN_RESPONSIBILITY_ENROLMENTAPPLICATIONFORM_HPP
