#include <iostream>
#include <map>
#include "mediator.hpp"
#include "components.hpp"

using namespace std;

/**
 * The client code.
 */
void ClientCode() {
    LoginMediator mediator;
    mediator.execute();
}

int main() {
    ClientCode();
    return 0;
}