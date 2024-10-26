//
// Created by David Cho on 2024-09-17.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "myStack.hpp"

TEST_CASE("A new stack is empty", "testTag1")
{
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.full() == false);
}

TEST_CASE("Top index of empty stack", "testTag2")
{
    MyStack tester;
    REQUIRE_THROWS_AS(tester.top(), std::runtime_error);
}

TEST_CASE("Pop in empty stack", "testTag3")
{
    MyStack tester;
    REQUIRE_THROWS_AS(tester.pop(), std::out_of_range);
}

TEST_CASE("Check for full stack (full)", "testTag4")
{
    MyStack tester;
    tester.push(1);
    tester.push(2);
    tester.push(1);
    tester.push(2);
    tester.push(1);
    tester.push(2);
    tester.push(1);
    tester.push(2);
    tester.push(1);
    tester.push(2);
    REQUIRE(tester.full() == true);
}

TEST_CASE("Check for full stack (false)", "testTag5")
{
    MyStack tester;
    tester.push(1);
    REQUIRE(tester.full() == false);
}

TEST_CASE("Printing pushed elements", "testTag6")
{
    MyStack tester;
    tester.push(1);
    tester.push(2);
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    tester.print();
    std::cout.rdbuf(oldCout);
    REQUIRE(output.str() == "Stack from bottom to top: 1 2 \n");
}

TEST_CASE("Pushed elements response (true)", "testTag7")
{
    MyStack tester;
    tester.push(1);
    REQUIRE(tester.push(2) == true);
}

TEST_CASE("Pushed elements response (false) and see if it is full", "testTag8")
{
    MyStack tester;
    tester.push(1);
    tester.push(2);
    tester.push(3);
    tester.push(4);
    tester.push(5);
    tester.push(6);
    tester.push(7);
    tester.push(8);
    tester.push(9);
    tester.push(10);
    REQUIRE(tester.push(2) == false);
    REQUIRE(tester.full() == true);
    REQUIRE(tester.empty() == false);
}

TEST_CASE("Popped element response", "testTag9")
{
    MyStack tester;
    tester.push(1);
    REQUIRE(tester.pop() == true);
    REQUIRE_THROWS_AS(tester.pop(), std::out_of_range);
}

TEST_CASE("Show top index", "testTag10")
{
    MyStack tester;
    REQUIRE_THROWS_AS(tester.top(), std::runtime_error);
    tester.push(3);
    REQUIRE(tester.top() == 3);
}

TEST_CASE("Pop in range and out of range", "test")
{
    MyStack tester;
    tester.push(1);
    REQUIRE(tester.pop() == true);
    REQUIRE_THROWS_AS(tester.pop(), std::out_of_range);
}


