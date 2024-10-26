#include <iostream>
using namespace std;

/*
An interface for the Service. Both proxy and service must fully implement all
abstract methods
 */
class ServiceInterface {
public:
    virtual void doSomething() = 0;
};

//The actual service where the work is done
class Service : public ServiceInterface {
public:
    void doSomething() override {
        cout << "doing service code" << endl;
    }
};

/*
Proxy contains a pointer to the actual service. Any calls made to the proxy
are directed to the actual service. Some pre and post code may be done before
and after the call to service
 */
class Proxy : public ServiceInterface {

    Service* service;

public:
    Proxy(Service* s) : service(s) {}

    void doSomething() override {
        cout << "doing proxy code before" << endl;
        service->doSomething();
        cout << "doing proxy code after" << endl;
    }
};

/*
 * Simulates client using a service
 * Typically client only has access to the proxy
 * This is to illustrate that the client should not have any idea which version
 * of the service they get. But the service will work regardless
 */
void client(ServiceInterface *si) {
    //can use real service as usual, or proxy version
    //client doesn't know
    si->doSomething();
}

int main() {
    //instantiate real and proxy services, pass pointer of real service to proxy
    Service *youtube = new Service;
    Proxy *proxy_youtube = new Proxy(youtube);

    client(youtube);

    cout << endl;

    client(proxy_youtube);

    delete youtube;
    delete proxy_youtube;
    return 0;
}