//
// Created by jyim3 on 2023-11-16.
//

#include "mediator.hpp"

LoginMediator::LoginMediator() {
    status_text = new TextLabel;

    //create users and passwords in database
    credentials_db["Jeff"] = "123";
    credentials_db["aaa"] = "111";
    credentials_db["zorak_the_destroyer"] = "i_am_133t";

    //initializing components, also passing in mediator (self) to components
    login_btn = new Button(this);
    exit_btn = new Button(this);
    user_inputfield = new InputField(this, "Enter username");
    password_inputfield = new InputField(this, "Enter password");
}

/*
    Execution loop for accepting user input and simulating a log in screen
    UI.
 */
void LoginMediator::execute() {
    enum MENU {USERNAME = 1, PASSWORD, LOGIN, EXIT};

    while(!exit_screen)
    {
        cout << "Welcome!" << endl;
        cout << "Login Screen" << endl;
        cout << "-------------------------------" << endl;
        status_text->display_text("Status");
        cout << "Username: "  << user_inputfield->input_text << endl;
        string password;
        for(int i=0; i < password_inputfield->input_text.size(); i++)
        {
            password += "*";
        }
        cout << "Password: "  << password << endl;
        cout << endl;
        cout << "--------------\t\t-------------" << endl;
        cout << "|Login Button|\t\t|Exit Button|" << endl;
        cout << "--------------\t\t-------------" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1 - Enter username" << endl;
        cout << "2 - Enter password" << endl;
        cout << "3 - Press login button" << endl;
        cout << "4 - Press exit button" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case MENU::USERNAME:
                user_inputfield->enter_data(); //Calling component
                break;
            case MENU::PASSWORD:
                password_inputfield->enter_data(); //Calling component
                break;
            case MENU::LOGIN:
                login_btn->on_click(); //Calling component
                break;
            case MENU::EXIT:
                exit_btn->on_click(); //Calling component
                break;
        }
    }
}

/*
    This method is responsible for handling communication between all the
    log in components and facilitating any events triggered (Eg: on click).
    :param sender: an object, a log in screen component
    :param event: optional parameters needed to facilitate notification.
*/
void LoginMediator::notify(BaseComponent *sender, std::string event) {
    //handle user_inputfield notifications
    if (sender == user_inputfield) {
        if(event != "")
        {
            if(credentials_db.count(event) <= 0)
            {
                status_text->text = "User doesn't exist";
            } else
            {
                status_text->text = "User exists";
            }
        }
    }
        //handle password_inputfield notifications
    else if (sender == password_inputfield) {
        if(event != "")
            status_text->text = "Password entered";
    }
        //handle login_btn notifications
    else if(sender == login_btn)
    {
        //successful login if username and password matches
        bool success = (credentials_db.count(user_inputfield->input_text) > 0 && (credentials_db[user_inputfield->input_text] == password_inputfield->input_text));
        if(success) {
            cout << "You logged in!" << endl;
            exit_screen = true;
        } else
        {
            status_text->text = "Login failed";
        }
    }
        //handle exit_btn notifications
    else if (sender == exit_btn) {
        exit_screen = true;
    }
}

LoginMediator::~LoginMediator() {
    delete login_btn;
    delete exit_btn;
    delete user_inputfield;
    delete password_inputfield;
    delete status_text;
}
