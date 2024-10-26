/*
 * Chain of Responsibility Pattern in a school administrative system
 */

#include <iostream>
#include "handlers.hpp"
#include <vector>
using namespace std;

/*
    The Enrolment system is responsible for creating a chain of handlers
    that will eventually validate a EnrolmentApplicationForm and enrol
    the student into the courses selected.
 */
struct EnrolmentSystem {

    BaseSchoolFormHandler* handler_chain_head;
    BaseSchoolFormHandler* middle_chain_head;

    CheckCourseOfferingsHandler *course_handler;
    ValidateStudentHandler *student_validation_handler;
    FeesHandler *fees_handler;

    EnrolmentSystem() {
        //Sets up the enrolment system and creates a chain of handlers.
        //-----setup handlers-----
        course_handler = new CheckCourseOfferingsHandler;
        student_validation_handler = new ValidateStudentHandler;
        fees_handler = new FeesHandler;

        //set handler order, course_handler -> student_validation -> fees_handler
        course_handler->set_handler(student_validation_handler);
        student_validation_handler->set_handler(fees_handler);

        // for demonstrating that you can start in the middle of a chain
        // only, generally this is rarely done and wouldn't be needed.
        handler_chain_head = course_handler;
        middle_chain_head = student_validation_handler;
    }

    /*
        Enrols the student in the courses specified in the
        EnrolmentApplicationForm. Data validation checks are carried out
        before the student is enrolled.
        :param form:a EnrolmentApplicationForm
        :param skip_course_validation: a bool
        :return: bool, True if the student was enrolled, false otherwise
     */
    bool enrol(EnrolmentApplicationForm* form, bool skip_course_validation = false) {
        pair<string, bool> result;

        //can start handlers from the beginning or middle
        if(!skip_course_validation) {
            result = handler_chain_head->handle_form(form);
        }
        else {
            result = middle_chain_head->handle_form(form);
        }

        //result contains a message, and bool indicating success or failure
        //print all courses if student successfully passed all handlers
        if(result.second == true)
        {
            for(string course : form->courses_for_enrolment) {
                form->student_account.current_courses.push_back(course);
                cout << "Student enrolled in: " << course << endl;
            }
        }
        else
        {
            cout << result.first << endl;
            return false;
        }
        return false;
    }

    ~EnrolmentSystem() {
        delete course_handler;
        delete student_validation_handler;
        delete fees_handler;
    };
};

int main() {
    //------------- create student and form  -------------
    vector<string> courses {"AI for Games 2020",
                            "OOP 2 2020", "Data Comms 2020",
                            "Algorithms and Data Structures 2020",
                            "Career Development 2020"};

    StudentAccount studentAccount{"Zorak", 25, "A02355232", "CST Diploma"};
    EnrolmentApplicationForm enrolment_form("Zorak", 25, "A02355232", courses, studentAccount, true, 2020);

    cout << "------------- Enrol correctly filled form and student  -------------" << endl;
    EnrolmentSystem enrolment_system;
    enrolment_system.enrol(&enrolment_form); // begin request


    cout << "\n\n------------- Enrol Incorrect Student Data -------------" << endl;
    EnrolmentApplicationForm enrolment_form2("Zorak", 25, "A023532", courses, studentAccount, true, 2020);
    enrolment_system.enrol(&enrolment_form2);


    cout << "\n\n------------- Can start from any part of the chain - skip Checking course offerings -------------" << endl;
    EnrolmentApplicationForm enrolment_form3("Zorak", 25, "A02355232", courses, studentAccount, true, 2020);
    enrolment_system.enrol(&enrolment_form3, true); //true makes this start from the middle - skip Checking course offerings
    return 0;
}