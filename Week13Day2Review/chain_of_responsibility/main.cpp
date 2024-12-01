#include <iostream>
#include <string>
using namespace std;

// Abstract handler
class Handler {
protected:
    Handler* nextHandler = nullptr; // Pointer to the next handler in the chain

public:
    virtual ~Handler() {}

    // Set the next handler in the chain
    void setNext(Handler* handler) {
        nextHandler = handler;
    }

    // Handle the request or pass it to the next handler
    virtual void handleRequest(const string& request) {
        if (nextHandler) {
            nextHandler->handleRequest(request); // Pass the request to the next handler
        } else {
            cout << "Request complete." << endl;
        }
    }
};

// Concrete handler A
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const string& request) override {
        string findString = "Jeff"; //looking for this in the request
        if (request.find(findString) != string::npos) {
            cout << "Processed name: " << findString << endl;
            Handler::handleRequest(request); // Pass to next handler
        } else {
            cout << "ConcreteHandlerA cannot handle the request. " << findString << " not found" << endl;
        }
    }
};

// Concrete handler B
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const string& request) override {
        string findString = "1234"; //looking for this in the request
        if (request.find(findString) != string::npos) {
            cout << "Processed password: " << findString << endl;
            Handler::handleRequest(request); // Pass to next handler
        } else {
            cout << "ConcreteHandlerB cannot handle the request. " << findString << " not found" << endl;
        }
    }
};

// Concrete handler C
class ConcreteHandlerC : public Handler {
public:
    void handleRequest(const string& request) override {
        string findString = "Vancouver"; //looking for this in the request
        if (request.find(findString) != string::npos) {
            cout << "Processed region: " << findString << endl;
            Handler::handleRequest(request); // Pass to next handler
        } else {
            cout << "ConcreteHandlerC cannot handle the request. " << findString << " not found" << endl;
        }
    }
};

int main() {
    //create an information validation checker using Chain of Responsibility
    //each handler checks for a specific substring in the request

    // Create handlers (stack-allocated)
    ConcreteHandlerA handlerA; //checks for Jeff
    ConcreteHandlerB handlerB; //checks for 1234
    ConcreteHandlerC handlerC; //checks for Vancouver

    // Set up the chain of responsibility
    handlerA.setNext(&handlerB);
    handlerB.setNext(&handlerC);

    // Test the chain
    string request = "Jeff 1234 Vancouver";
    cout << "Sending request: " << request << endl;
    handlerA.handleRequest(request);

    request = "Jeff 1234 Narnia";
    cout << "\nSending request: " << request << endl;
    handlerA.handleRequest(request); // request can't pass through all handlers

    return 0;
}
