#include <iostream>
using namespace std;

class Shape
{
  private:
    int counter;
  protected:
    int width, height;
  public:
    void set_values (int a, int b) { width = a; height = b; }
    virtual int area () {return 0;}
};

class Rectangle: public Shape 
{
  public:
    int area() { return width * height; }
};

class Triangle: public Shape 
{
  public:
    int area() { return width * height / 2; }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Shape * shape1 = &rect;
  Shape * shape2 = &trgl;
  shape1->set_values (4,5);
  shape2->set_values (4,5);
  //cout << shape1->counter; // WILL THIS WORK?
  cout << shape1->area() << '\n';
  cout << shape2->area() << '\n';
  return 0;
}