//
// Created by David Cho on 2024-09-10.
//

#include <iostream>
#include <fstream>
#include <random>

using namespace std;

#include "randomGenerator.hpp"

int random_generator(char* outputFile)
{
    const int MIN_ARRAY_SIZE = 512;
    const int MAX_ARRAY_SIZE = 1024;
    const double DOUBLE_LOWERBOUND = 50.000;
    const double DOUBLE_UPPERBOUND = 90.000;
    const int PRECISION = 3;

    fstream outfile(outputFile, ios::out);
    if(!outfile)
    {
        cerr << "Error creating file" << endl;
        exit(1);
    }

    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<> array_size(MIN_ARRAY_SIZE, MAX_ARRAY_SIZE);
    const int random_array_size = array_size(gen);

    uniform_real_distribution<> double_distribution(DOUBLE_LOWERBOUND, DOUBLE_UPPERBOUND);

    for (int i = 0; i < random_array_size; ++i)
    {
        const double random_double = double_distribution(gen);
        outfile << i << " " << fixed << setprecision(PRECISION) << random_double << endl;

    }

    outfile.close();

    return 0;
}
