//
// Created by David Cho on 2024-09-23.
//

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

/**
 * @brief The Animal class
 *
 * Purpose: This class is the base class for all animals.
 * Protected: age, id, alive, x, y, z, idCounter
 * Public: Constructors, Destructor, and virtual functions
 * Accessor Methods: getId, getX, getY, getZ
 * Operator Overloads: Output stream
 *
 */
class Animal {
protected:
    // age of the animal
    int age;
    // unique id of the animal
    long id;
    // alive status of the animal
    bool alive;
    // location of the animal
    double x, y, z;
    // counter for the id
    static long idCounter;

public:
    // Constructors
    Animal();
    Animal(int age, double x, double y, double z = 0.0);
    Animal(const Animal& other);

    // Virtual Destructor
    virtual ~Animal();

    /**
     * @brief move
     * @param x
     * @param y
     * @param z
     * @Precondition: x, y, z are valid coordinates
     * @Postcondition: x, y, z are updated
     * @return Prints to the output stream
     */
    virtual void move(double x, double y, double z = 0.0);

    /**
     * @brief sleep
     * @Precondition: Pointed Animal object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    virtual void sleep();

    /**
     * @brief eat
     * @Precondition: Pointed Animal object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    virtual void eat();

    /**
     * @brief print
     * @param out
     * @Precondition: Pointed Animal object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    virtual void print(std::ostream& out) const;

    /**
     * @brief setAlive
     * @param aliveStatus
     * @Precondition: aliveStatus is a boolean
     * @Postcondition: alive is updated
     * @return void
     */
    void setAlive(bool aliveStatus);

    /**
     * @brief getId
     * @Precondition: There is a valid id
     * @Postcondition: None
     * @return long
     */
    long getId() const;

    /**
     * @brief getX
     * @Precondition: There is a valid x coordinate
     * @Postcondition: None
     * @return double
     */
    double getX() const;

    /**
     * @brief getY
     * @Precondition: There is a valid y coordinate
     * @Postcondition: None
     * @return double
     */
    double getY() const;

    /**
     * @brief getZ
     * @Precondition: There is a valid z coordinate
     * @Postcondition: None
     * @return double
     */
    double getZ() const;

    /**
     * @brief operator<<
     * @param out
     * @param animal
     * @Precondition: out is a valid ostream object, animal is a valid Animal object
     * @Postcondition: animal is printed to the output stream
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& out, const Animal& animal);
};

#endif // ANIMAL_HPP
