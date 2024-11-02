//Name: David Cho
//Student# : A01351217

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

#include "Course.hpp"

using namespace std;

/**
 * Reads the course data from the given file and returns a vector of courses
 * @param file - the name of the file to read
 * @return - a vector of courses
 */
vector<Course> readFile(const string& file) {
    /* initialize the vector of courses to store the data */
    vector<Course> courses;
    /* initialize the input file stream */
    ifstream inputFile(file);

    /* error check if the file does not open */
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << file << endl;
    }

    /* read the data from file while file is open */
    while (inputFile.is_open()) {
        /* initialize the variables to store the course data */
        string courseTitle;
        string dayOfWeek;
        unsigned int startTime, endTime;

        /* while there is data to read from the file */
        while (inputFile >> courseTitle >> dayOfWeek >> startTime >> endTime) {
            /* check if the day of the week is valid and store the course data */
            Course::dayOfWeek day;
            if (dayOfWeek == "M") {
                day = Course::MON;
            } else if (dayOfWeek == "T") {
                day = Course::TUE;
            } else if (dayOfWeek == "W") {
                day = Course::WED;
            } else if (dayOfWeek == "R") {
                day = Course::THUR;
            } else if (dayOfWeek == "F") {
                day = Course::FRI;
            } else {
                cerr << "Invalid day: " << dayOfWeek << endl;
                continue;
            }

            /* create a new course */
            Course newCourse(courseTitle, day, startTime, endTime);
            /* add the course to the vector of courses */
            courses.push_back(newCourse);
        }
        inputFile.close();
    }
    return courses;
}

/**
 * Prints the schedule to the screen
 * @param courses - the vector of courses to print
 */
void printSchedule(const vector<Course>& courses) {
    /* use the copy algorithm, 2 iterators, and an ostream_iterator */
    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout, "\n"));
}

/**
 * Prints the schedule conflicts to the screen
 * @param courses - the vector of courses to check for conflicts
 */
void courseConflicts(const vector<Course>& courses) {
    /* initialize the vector of pairs to store the conflicts */
    vector<pair<Course, Course>> conflicts;

    /* loop and compare each course with every other course */
    for (auto it1 = courses.begin(); it1 != prev(courses.end()); ++it1) {
        for (auto it2 = next(it1); it2 != courses.end(); ++it2) {
            /* check if the courses overlap */
            if (*it1 == *it2) {
                /* store the conflicting courses */
                cout << "CONFLICT:\n" << *it1 << "\n" << *it2 << "\n" << endl;
            }
        }
    }
}

/**
 * Main function to read the course data from the file, sort the courses,
 * check for conflicts, and print the schedule
 * @return - 0
 */
int main() {
    /* read the data from the file and store data into STL container */
    vector<Course> courses = readFile("../courses.txt");

    /* sort the course vector STL container using the sort algorithm */
    sort(courses.begin(), courses.end());

    /* check for course conflicts and print out the conflicts */
    courseConflicts(courses);

    /* print the schedule to the screen */
    printSchedule(courses);

    return 0;
}