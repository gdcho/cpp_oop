#include <iostream>

//Question: observer design pattern, vectors and pointers
#include "Observer.hpp"
#include "Subject.hpp"

int main() {
    Newspaper newspaper;
    Observer *optimist = new Optimist;
    Observer *pessimist = new Pessimist;

    //attach observers
    newspaper.attach(optimist);
    newspaper.attach(pessimist);

    //something important happens with newspaper. Newspaper broadcasts to all observers
    newspaper.setNews("puppies were born today");

    //pessimist doesn't want to observer newspaper anymore so detach
    newspaper.detach(pessimist);

    //something important happens with newspaper. Newspaper broadcasts to all observers
    newspaper.setNews("Pollution is down today");

    //clean up memory
    delete optimist;
    delete pessimist;

    return 0;
}