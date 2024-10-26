#include <iostream>
#include <map>
using namespace std;

//Various UI components
struct InputField {
    string text;
    virtual void enter_data() {
        cin >> text;
    }
    string get_input() {
        return text;
    }
};

struct TextLabel {
    void display_text(string text) {
        cout << text << endl;
    }
};

struct UserIDInputfield : public InputField{
    TextLabel *status_text;
    UserIDInputfield(TextLabel *text_lbl) {
        status_text = text_lbl;
        text = "";
    }

    void enter_data(map<string,string> &credentials) {
        cout << "Enter text:" << endl;
        cin >> text;
        if(credentials.count(text) <= 0)
        {
            status_text->display_text("Invalid user ID"); //this input field can only be used with status_text
        }
    }
};

struct UserPasswordInputfield : public InputField{
    TextLabel *status_text;
    UserPasswordInputfield(TextLabel *text_lbl) {
        status_text = text_lbl;
        text = "";
    }

    void enter_data(map<string,string> &credentials) {
        cout << "Enter text:" << endl;
        cin >> text;
        for (auto it = credentials.begin(); it != credentials.end(); ++it) {
            if (it->second == text) {
                status_text->display_text("Valid password");
                return;
            }
        }
        status_text->display_text("Invalid password");
    }
};

struct Screen {
    void back() {}
};

struct LogInScreen : Screen {
    void log_in() {
        cout << "Entered login screen" << endl;
    }
};

//More UI components that are TIGHTLY coupled with other UI components
struct LogInButton {
    LogInScreen* login_screen;
    UserIDInputfield* username_inputfield;
    UserPasswordInputfield* pwd_inputfield;

    LogInButton(LogInScreen* login_screen, UserIDInputfield* username_inputfield, UserPasswordInputfield* pwd_inputfield) :
        login_screen(login_screen),
        username_inputfield(username_inputfield),
        pwd_inputfield(pwd_inputfield) {
    }

    bool on_click(map<string,string> credentials) {
        if(credentials[username_inputfield->get_input()] == pwd_inputfield->get_input()) {
            cout << "Login success" << endl;
            login_screen->log_in(); //this button can ONLY be used with a login_screen
        }
        else
        {
            cout << "Login failed" << endl;
        }
    }
};

struct ExitButton {
    Screen *screen;
    ExitButton(Screen *screen) : screen(screen){}

    void on_click(map<string, string> credentials) {
        screen->back(); //this button is only interacting with the screen back function
    }
};

int main() {
    //database of usernames and passwords
    map<string, string> credentials = map<string,string>{ {"Jeff", "123"}};

    //Declare labels and inputfields to gather username and password
    TextLabel usernameLabel;
    TextLabel passwordLabel;
    UserIDInputfield username_inputfield(&usernameLabel);
    UserPasswordInputfield pwd_inputfield(&passwordLabel);

    //query for username
    usernameLabel.display_text("Enter username");
    username_inputfield.enter_data(credentials);

    //query for password
    passwordLabel.display_text("Enter password");
    pwd_inputfield.enter_data(credentials);

    //press login button to enter login screen if credentials match
    LogInScreen login_screen;
    LogInButton logInButton(&login_screen, &username_inputfield, &pwd_inputfield);
    logInButton.on_click(credentials);

    return 0;
}