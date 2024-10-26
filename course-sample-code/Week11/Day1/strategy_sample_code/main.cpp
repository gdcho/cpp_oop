#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */
class Weapon
{
public:
    string name;
    virtual ~Weapon() {}
    virtual void attack() const = 0;
};

/**
 * The Context defines the interface of interest to clients.
 */

class Character
{
    /**
     * @var Strategy The Context maintains a reference to one of the Strategy
     * objects. The Context does not know the concrete class of a strategy. It
     * should work with all strategies via the Strategy interface.
     */
private:
    Weapon *strategy;
    /**
     * Usually, the Context accepts a strategy through the constructor, but also
     * provides a setter to change it at runtime.
     */
public:
    Character(Weapon *strategy = nullptr) : strategy(strategy)
    {
        cout << "Created Character" << endl;
    }
    /**
     * Usually, the Context allows replacing a Strategy object at runtime.
     */
    void change_weapon(Weapon *strategy)
    {
        if(this->strategy != nullptr) {
            cout << "Changing weapon from " << this->strategy->name << " to " << strategy->name << endl;
        } else {
            cout << "Changing weapon to " << strategy->name << endl;
        }
        this->strategy = strategy;
    }
    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing +multiple versions of the algorithm on its own.
     */
    void attack() const
    {
        this->strategy->attack();
    }
};

/**
 * Concrete Strategies implement the algorithm while following the base Strategy
 * interface. The interface makes them interchangeable in the Context.
 */
class Sword : public Weapon
{
public:
    Sword() {
        name = "Sword";
    }
    void attack() const override
    {
        cout << "Short attack with " << name << endl;
    }
};
class Spear : public Weapon
{
public:
    Spear() {
        name = "Spear";
    }
    void attack() const override
    {
        cout << "Long attack with " << name << endl;
    }
};

/**
 * The client code picks a concrete strategy and passes it to the context. The
 * client should be aware of the differences between strategies in order to make
 * the right choice.
 */
void ClientCode()
{
    Character character;
    Sword sword;
    Spear spear;

    enum weapons{SWORD = 1, SPEAR, EXIT};

    int choice = EXIT;
    do {
        cout << "Pick an option:" << endl;
        cout << "1: Equip SWORD and attack" << endl;
        cout << "2: Equip SPEAR and attack" << endl;
        cout << "3: Run away!" << endl;

        cin >> choice;
        switch (choice) {
            case SWORD:
                character.change_weapon(&sword);
                character.attack();
                break;
            case SPEAR:
                character.change_weapon(&spear);
                character.attack();
                break;
            default:
                choice = EXIT;
        }

    } while(choice != EXIT);
}

int main()
{
    ClientCode();
    return 0;
}