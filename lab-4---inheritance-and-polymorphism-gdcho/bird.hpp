//
// Created by David Cho on 2024-09-23.
//

#ifndef BIRD_HPP
#define BIRD_HPP

#include "animal.hpp"
#include <iostream>

/**
 * @brief Bird class that inherits from Animal
 *
 * Purpose: To represent a Bird object that inherits from Animal
 * Public: Constructors, Destructor, move, sleep, eat, print
 * Operator Overloads: Output stream
 *
 */
class Bird : public Animal {
public:
    // Constructors
    Bird();
    Bird(int age, double x, double y, double z);
    Bird(const Bird& other);

    // Virtual Destructor
    ~Bird() override;

    /**
     * @brief move
     * @param x
     * @param y
     * @param z
     * @Precondition: x, y, z are valid coordinates
     * @Postcondition: x, y, z are updated
     * @return Prints to the output stream
     */
    void move(double x, double y, double z) override;

    /**
     * @brief sleep
     * @Precondition: Pointed Bird object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void sleep() override;

    /**
     * @brief eat
     * @Precondition: Pointed Bird object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void eat() override;

    /**
     * @brief print
     * @param out
     * @Precondition: Pointed Bird object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void print(std::ostream& out) const override;

    /**
     * @brief operator<<
     * @param out
     * @param bird
     * @Precondition: Pointed Bird object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    friend std::ostream& operator<<(std::ostream& out, const Bird& bird);
};

#endif // BIRD_HPP
