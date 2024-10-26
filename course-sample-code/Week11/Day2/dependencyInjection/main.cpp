#include <iostream>
using namespace std;

class DataSource {
public:
    virtual void readFile() = 0;
    virtual ~DataSource() = default;
};

class TextFile : public DataSource {
public:
    string filename;
    TextFile(string filename) : filename(filename) {}
    void readFile() override {
        cout << "reading TextFile from " << filename << endl;
    }
};

class JSONFile : public DataSource {
public:
    string filename;
    JSONFile(string filename) : filename(filename) {}
    void readFile() override {
        cout << "reading JSON from " << filename << endl;
    }
};

class UI {
public:
    DataSource *data_source;

    //---No dependency injection---
    UI(string filename) {
        //JSONFile object INSTANTIATED in constructor. UI class COUPLED with concrete JSONFile
        data_source = new JSONFile(filename);
    }

    //---Dependency injection---
    UI(DataSource *data_source) {
        this->data_source = data_source; //data_source injected from outside of constructor. UI class NOT COUPLED with concrete JSONFile
    }

    void run() {
        this->data_source->readFile();
    }

    ~UI() {
        delete data_source;
    };
};

int main() {
    string filename = "file.json";

    //---No constructor dependency injection---
    //Pass filename into UI class, the UI class will instantiate the JSONFile inside
    //This causes UI class to be COUPLED with JSONFile
    //UI can't read TextFile objects without refactoring code in UI's constructor
    UI ui_no_dependency_injection(filename);
    ui_no_dependency_injection.run();

    //---Constructor Dependency injection JSON---
    //UI (CLIENT) depends on DataSource (SERVICE). Current main function acts as the INJECTOR
    //main function instantiates DataSource (SERVICE)
    //passes (injects) the DataSource into the UI (CLIENT)
    DataSource *json_file = new JSONFile(filename); //create dependent object
    UI ui_with_dependency_injection(json_file); //inject json_file into ui
    ui_with_dependency_injection.run();

    //---Constructor Dependency injection TXT---
//    DataSource *text_file = new TextFile("Textfile.txt"); //create dependent object
//    UI ui_with_dependency_injection(text_file); //inject text_file into ui
//    ui_with_dependency_injection.run();

    return 0;
}
