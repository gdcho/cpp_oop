//
// Created by jyim3 on 2023-11-16.
//

#include "components.hpp"
#include "mediator.hpp"

void Button::on_click() {
    std::cout << "Button clicked\n";
    this->mediator->notify(this);
}

//Accept data from the user and notify a mediator.
void InputField::enter_data() {
    std::cout << output_text << endl;
    cin >> input_text;
    this->mediator->notify(this, input_text);
}

void TextLabel::display_text(string prefix) {
    if(!text.empty())
    {
        cout << prefix << ": " << text << endl;
    }
}