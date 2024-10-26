//
// Created by David Cho on 2024-09-10.
//

#include <iostream>
#include <fstream>

using namespace std;

#include "statistics.hpp"

int statistics(char* inputFile)
{
    const int MAX_ARRAY_SIZE = 1024;
    const int TWO = 2;
    const int PRECISION = 3;

    ifstream infile(inputFile);
    if (!infile.is_open() || !infile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    double readings[MAX_ARRAY_SIZE];
    int count = 0;
    int int_pair;
    double double_pair;

    while (infile >> int_pair >> double_pair) {
        readings[count++] = double_pair;
    }

    infile.close();

    if (count == 0) {
        cout << "No readings" << endl;
        return 0;
    }

    double sum = 0;
    double highest = readings[0];
    double lowest = readings[0];

    for (int i = 0; i < count; i++) {
        sum += readings[i];
        highest = max(highest, readings[i]);
        lowest = min(lowest, readings[i]);
    }

    double average = sum / count;

    sort(readings, readings + count);
    double median = (count % TWO == 0)
        ? (readings[count/TWO - 1] + readings[count/TWO]) / TWO
        : readings[count/TWO];

    cout << fixed << setprecision(PRECISION);
    cout << "There are " << count << " readings in the file." << flush;
    cout << " The average reading is " << average << "." << endl;
    cout << "The highest reading is " << highest << "." << endl;
    cout << "The lowest reading is " << lowest << "." << endl;
    cout << "The median reading is " << median << "." << endl;

    return 0;
}