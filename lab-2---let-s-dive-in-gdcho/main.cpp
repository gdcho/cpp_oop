//Name: David Cho
//Student# : A01351217

#include "randomGenerator.hpp"
#include "statistics.hpp"

int main() {
    char fileName[] = "Readings.txt";

    random_generator(fileName);
    statistics(fileName);

    return 0;
}