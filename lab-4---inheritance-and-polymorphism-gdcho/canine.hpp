//
// Created by David Cho on 2024-09-23.
//

#ifndef CANINE_HPP
#define CANINE_HPP

#include "animal.hpp"

/**
 * @brief Canine class that inherits from Animal
 *
 * Purpose: To represent a Canine object that inherits from Animal
 * Public: Constructors, Destructor, move, sleep, eat, hunt, print
 * Specific Methods: hunt, allows a Canine to hunt another Animal
 * Operator Overloads: Output stream
 *
 */
class Canine : public Animal {
public:
    // Constructors
    Canine();
    Canine(int age, double x, double y);
    Canine(const Canine& other);

    // Virtual Destructor
    ~Canine() override;

    /**
     * @brief move
     * @param x
     * @param y
     * @param z
     * @Precondition: x, y, z are valid coordinates
     * @Postcondition: x, y, z are updated
     * @return Prints to the output stream
     */
    void move(double x, double y, double z = 0.0) override;

    /**
     * @brief sleep
     * @Precondition: Pointed Canine object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void sleep() override;

    /**
     * @brief eat
     * @Precondition: Pointed Canine object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void eat() override;

    /**
     * @brief hunt
     * @param animal
     * @Precondition: Pointed Canine object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void hunt(Animal* animal);

    /**
     * @brief print
     * @param out
     * @Precondition: Pointed Canine object is valid
     * @Postcondition: None
     * @return Prints to the output stream
     */
    void print(std::ostream& out) const override;

    /**
     * @brief operator<<
     * @param out
     * @param canine
     * @Precondition: out is a valid ostream object, canine is a valid Canine object
     * @Postcondition: canine is printed to the output stream
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& out, const Canine& canine);};

#endif // CANINE_HPP
