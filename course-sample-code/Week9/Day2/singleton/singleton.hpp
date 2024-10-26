//
// Created by A00257049 on 2019-03-27.
//

#ifndef SINGLETON_SINGLETON_HPP
#define SINGLETON_SINGLETON_HPP
class singleton
{
public:
    static singleton& get_instance()
    {
        static singleton instance;
        return instance; // Instantiated on first use.
    }
private:
    int value;
    singleton() = default; //private constructor

public:
    singleton(singleton const&)       = delete; //deleting copy constructor
    void operator=(singleton const&)  = delete; //deleting assignment operator

    int get_value() {
        return value++;
    }
};
#endif //SINGLETON_SINGLETON_HPP
