// Course.hpp
#pragma once

#include <iostream>

using namespace std;

/**
 * Class to represent a course.
 * A course has a title, day of the week, start time, and finish time.
 */
class Course {
public:
    /* constants for the days of the week */
    enum dayOfWeek {
        MON, TUE, WED, THUR, FRI
    };

    enum struct dayOfWeekChar {
     MON = 'M', TUE = 'T', WED = 'W', THUR = 'R', FRI = 'F'
    };

    /**
     * Constructor to initialize the course with the given parameters
     * @param title - the title of the course
     * @param day - the day of the week the course is on
     * @param start_time - the time the course starts
     * @param finish_time - the time the course ends
     */
    Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);

    /**
     * Copy constructor to initialize the course with the given parameters
     * @param m - course to copy
     */
    Course(const Course& m);

    /**
     * Assignment operator to copy the course with the given parameters
     * @param m - course to copy
     * @return - the copied course
     */
    Course& operator=(Course m);

    /**
     * Overloaded operator to compare two courses for less than
     * @param m - course to compare
     * @return - true if the course is less than the given course, false otherwise
     */
    bool operator<(const Course& m) const;

     /**
     * Overloaded operator to compare two courses for equality
     * @param m - course to compare
     * @return - true if the courses overlap, false otherwise
     */
    bool operator==(const Course& m) const;

    /**
     * Overloaded operator to output the course to the given stream
     * @param os - the output stream
     * @param m - the course to output
     * @return - the output stream
     */
    friend ostream& operator<<(ostream& os, const Course& m);

private:
    /* title of the course */
    string title;
    /* day of the week the course is on */
    dayOfWeek day;
    /* time the course starts */
    unsigned int start_time;
    /* time the course ends */
    unsigned int finish_time;

};