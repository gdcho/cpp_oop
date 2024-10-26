//
// Created by jyim3 on 2023-11-16.
//

#ifndef Q1_MEDIATOR_HPP
#define Q1_MEDIATOR_HPP

#include "components.hpp"
#include <map>
/*
    All Mediators must implement a common interface so that all the
    other components that communicate via the Mediator can talk to it.
 */
class Mediator {
public:
    /*
        NOTE: This notify method was just created for the sample code.
        The interface can be any number of attributes and functions that
        all mediators have in common. This would depend on the
        application.
        :param sender: an object, the component notifying the mediator
        :param event: the parameters passed in to facilitate a notification.
     */
    virtual void notify(BaseComponent *sender, std::string event = "") = 0;
};

/*
    The Login Mediator is responsible for handling any and all communication
    between all the components that make up a log in screen. In this case, to
    keep things simple it also has the added responsibility of driving the
    log in screen execution. This isn't mandatory.
 */
class LoginMediator : public Mediator {
private:
    Button *login_btn;
    Button *exit_btn;

    InputField *user_inputfield;
    InputField *password_inputfield;

    TextLabel* status_text;
    bool exit_screen = false;

    map<string, string> credentials_db;

public:
    /*
        Initialize the log in screen components and some test data.
        All components have a reference to the mediator.
     */
    LoginMediator();

    /*
        Execution loop for accepting user input and simulating a log in screen
        UI.
     */
    void execute();

    /*
        This method is responsible for handling communication between all the
        log in components and facilitating any events triggered (Eg: on click).
        :param sender: an object, a log in screen component
        :param event: optional parameters needed to facilitate notification.
    */
    void notify(BaseComponent *sender, std::string event);
    ~LoginMediator();
};

#endif //Q1_MEDIATOR_HPP
