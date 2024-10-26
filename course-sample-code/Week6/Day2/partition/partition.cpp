#include <algorithm>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <random>
#include <string>
#include <utility>
/*
 * partition re-orders cities so cities that have a distance
 * less than DISTANCE appear first
*/

using namespace std;

constexpr int POPULATION = 10;
constexpr double DISTANCE = 50;

struct city
{
	static int counter;
	int number;
	std::pair<double, double> coordinates;
	city(std::pair<double, double> coordinates) : 
	    number{++counter}, coordinates{ coordinates } { }
	city(double x, double y) : 
	    number{++counter} , coordinates{ std::make_pair(x, y) } { }
	friend std::ostream& operator<<(std::ostream& out, const struct city& s);
};

int city::counter = 0;

std::ostream& operator<<(std::ostream& out, const struct city& s) {
	out << s.number << " (" << s.coordinates.first << ", " << s.coordinates.second << ")";
	return out;
}

typedef struct city city;

double distance(city candidate) {
	return std::sqrt( pow(candidate.coordinates.first, 2) 
		+ pow(candidate.coordinates.second, 2));
}

bool close_to_origin(city candidate)
{
	if (DISTANCE > distance(candidate)) {
		return true;
	}
	return false;
}

void print(city candidate)
{
	std::cout << candidate << " " << distance(candidate) << std::endl;
}

int main()
{
    //setup random number generator
	double lower = 0.0;
	double upper = 100.0;
	std::default_random_engine generator(time(0));
	std::uniform_real_distribution<double> distribution(lower, upper);

	//create cities with random coordinates and push to cities list
	std::list<city> cities;
	for (int i = 0; i < POPULATION; ++i) {
		city newcity(distribution(generator), distribution(generator));
		cities.push_back(newcity);
	}

	//print cities, partition them, and print again
	for_each(cities.begin(), cities.end(), print);
	cout << "\n\n";
	auto firstFalseCityItr = partition(cities.begin(), cities.end(), close_to_origin); //cities where DISTANCE > actual distance appear first
	cout << "First false city: " << firstFalseCityItr->number << endl;
	cout << "Cities before false city have distance " << DISTANCE << endl;
	for_each(cities.begin(), cities.end(), print);
}