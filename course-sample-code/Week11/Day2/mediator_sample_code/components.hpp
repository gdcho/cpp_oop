//
// Created by jyim3 on 2023-11-16.
//

#ifndef Q1_COMPONENTS_HPP
#define Q1_COMPONENTS_HPP

using namespace std;
#include <iostream>

class Mediator;
/**
 * The Base Component provides the basic functionality of storing a mediator's
 * instance inside component objects.
 */
class BaseComponent {
protected:
    Mediator *mediator;

public:
    BaseComponent(Mediator *mediator = nullptr) : mediator(mediator) {}
    void set_mediator(Mediator *mediator) {
        this->mediator = mediator;
    }
};

/**
    A re-usable button component. This can be used in any screen and
    just needs a reference to Mediator to work.
 */
class Button : public BaseComponent {
public:
    using BaseComponent::BaseComponent; //"inherit constructor"

    /*
        notify the mediator about the click event.
        :return:
     */
    void on_click();
};

/*
    An input field that allows user to enter some data. This can be
    reused in any screen and just needs a reference to a Mediator to
    work.
 */
class InputField : public BaseComponent {
public:
    InputField(Mediator *mediator = nullptr, string output_text = "") : BaseComponent(mediator), output_text(output_text) {}
    string output_text;
    string input_text;

    //Accept data from the user and notify a mediator.
    void enter_data();
};

/*
    Displays a line of text. You can have this class reference a
    mediator to keep things consistent and you probably would have to in
    a more complex system, but I chose not to because it would never use
    it.
 */
class TextLabel {
public:
    string text = "";

    /*
        Display text if it is initalized.
        :param prefix: a str, a prefex tag
     */
    void display_text(string prefix);
};

#endif //Q1_COMPONENTS_HPP
