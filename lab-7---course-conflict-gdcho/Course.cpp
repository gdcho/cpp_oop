#include "Course.hpp"

using namespace std;

/* Constants for the days of the week */
constexpr int ZERO = 0;
constexpr int ONE = 1;
constexpr int TWO = 2;
constexpr int THREE = 3;
constexpr int FOUR = 4;

/**
 * Constructor to initialize the course with the given parameters
 * @param title - the title of the course
 * @param day - the day of the week the course is on
 * @param start_time - the time the course starts
 * @param finish_time - the time the course ends
 */
Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time)
        : title(title), day(day), start_time(start_time), finish_time(finish_time) {
}

/**
 * Copy constructor to initialize the course with the given parameters
 * @param m - course to copy
 */
Course::Course(const Course& m)
        : title(m.title), day(m.day), start_time(m.start_time), finish_time(m.finish_time) {
}

/**
 * Assignment operator to copy the course with the given parameters
 * @param m - course to copy
 * @return - the copied course
 */
Course& Course::operator=(Course m) {
    title = m.title;
    day = m.day;
    start_time = m.start_time;
    finish_time = m.finish_time;
    return *this;
}

/**
 * Overloaded operator to compare two courses for equality
 * @param m - course to compare
 * @return - true if the courses overlap, false otherwise
 */
bool Course::operator==(const Course& m) const {
    /* check if the courses are on the same day */
    if (day != m.day) {
        return false;
    }
    /* Check if the course times overlap */
    if (finish_time <= m.start_time || start_time >= m.finish_time) {
        return false;
    }
    return true;
}

/**
 * Overloaded operator to compare two courses for less than
 * @param m - course to compare
 * @return - true if the course is less than the given course, false otherwise
 */
bool Course::operator<(const Course& m) const {
    /* if the courses are on different days, compare the days */
    if (this->day != m.day) {
        /* MON < TUE < WED < THUR < FRI */
        return this->day < m.day;
    }
    /* if the courses are on the same day, compare the start times */
    if (this->start_time != m.start_time) {
        return this->start_time < m.start_time;
    }
    /* if the courses are on the same day and start time, compare the finish times */
    return this->finish_time < m.finish_time;
}

/**
 * Overloaded operator to output the course to the screen
 * @param os - the output stream
 * @param m - the course to output
 * @return - the output stream
 */
ostream& operator<<(ostream& os, const Course& m) {
    /* convert the day to a string */
    char day;
    if (m.day == Course::dayOfWeek::MON) {
        day = static_cast<char>(Course::dayOfWeekChar::MON);
    } else if (m.day == ONE) {
        day = static_cast<char>(Course::dayOfWeekChar::TUE);
    } else if (m.day == TWO) {
        day = static_cast<char>(Course::dayOfWeekChar::WED);
    } else if (m.day == THREE) {
        day = static_cast<char>(Course::dayOfWeekChar::THUR);
    } else if (m.day == FOUR) {
        day = static_cast<char>(Course::dayOfWeekChar::FRI);
    } else {
        cerr << "Invalid day" << endl;
    }

    /* output the course information */
    os << m.title << " " << day << " " << m.start_time << " " << m.finish_time;
    return os;
}