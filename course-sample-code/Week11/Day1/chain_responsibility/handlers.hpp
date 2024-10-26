//
// Created by A00257049 on 2020-11-11.
//

#ifndef CHAIN_RESPONSIBILITY_HANDLERS_HPP
#define CHAIN_RESPONSIBILITY_HANDLERS_HPP

#include <iostream>
#include "EnrolmentApplicationForm.hpp"
using namespace std;
/*
    Baseclass for all handlers that handle school forms. This can be
    refactored to work for all school forms, not just the enrolment
    form. Each handler can maintain a reference to another handler
    thereby enabling the chain of responsibility pattern.
 */
struct BaseSchoolFormHandler {
    BaseSchoolFormHandler *next_handler = nullptr;

    BaseSchoolFormHandler() = default;
    BaseSchoolFormHandler(BaseSchoolFormHandler *handler) : next_handler(handler) {}

    /*
        Each handler would have a specific implementation of how it
        processes a form.
        :param form: a EnrolmentApplicationForm
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    virtual pair<string,bool> handle_form(EnrolmentApplicationForm* form) {};

    /*
        Each handler can invoke another handler at the end of it's
        processing of the form. This handler needs to implement the
        BaseSchoolFormHandler interface.
        :param handler: a BaseSchoolFormHandler
     */
    void set_handler(BaseSchoolFormHandler *handler) { next_handler = handler;}
};

/*
    This handler ensures that the data on the form is in sync with that
    in the associated student account.
 */
struct ValidateStudentHandler : BaseSchoolFormHandler {
    /*
        Checks to see if the name and student id on the form match the
        student account that was used to fill out the form.
        :param form: a EnrolmentApplicationForm
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    ValidateStudentHandler() = default;
    pair<string,bool> handle_form(EnrolmentApplicationForm* form) override {
        cout << "Validating student data" << endl;
        if (form->name == form->student_account.student_name &&
            form->student_id == form->student_account.student_id) {

            //if no more handlers exist, return with success message
            if (!next_handler)
                return make_pair("", true);

            //else call next handler in sequence
            return next_handler->handle_form(form);
        }
        else
            //failed validation, return failure message
            return make_pair("Student cannot be validated", false);
    }
};

/*
    This handler ensures that the courses being enrolled into are being
    offered in the coming academic year.
 */
struct CheckCourseOfferingsHandler : BaseSchoolFormHandler {

    /*
        Checks each course that the student is enrolling into to ensure
        that it is being offered next year.
        :param form: a EnrolmentApplicationForm
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    CheckCourseOfferingsHandler() = default;
    pair<string,bool> handle_form(EnrolmentApplicationForm* form) override {
        cout << "Checking course offerings" << endl;

        //check if course name contains the required year
        string enrolment_year = to_string(form->enrolment_year);
        for (string course : form->courses_for_enrolment) {
            if (course.find(enrolment_year) == std::string::npos)
                //failed validation, return failure message
                return make_pair("Course not offered", false);
        }

        //if no more handlers exist, return with success message
        if (!next_handler)
            return make_pair("", true);

        //else call next handler in sequence
        return next_handler->handle_form(form);
    }
};

//Validates that the application fees have been paid by the student.
struct FeesHandler : BaseSchoolFormHandler {
    /*
        Validates that the application fees have been paid by the
        student.
        :param form: a EnrolmentApplicationForm
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    FeesHandler() = default;
    pair<string,bool> handle_form(EnrolmentApplicationForm* form) override {
        cout << "Checking if application fee was paid" << endl;
        if(form->fees_paid)
        {
            //if no more handlers exist, return with success message
            if(!next_handler)
                return make_pair("", true);

            //else call next handler in sequence
            return next_handler->handle_form(form);
        }
        else
        {
            //failed validation, return failure message
            return make_pair("Application fees not paid", false);
        }
    }
};

#endif //CHAIN_RESPONSIBILITY_HANDLERS_HPP
