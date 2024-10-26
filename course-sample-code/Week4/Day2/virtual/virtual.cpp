#include <iostream>
using namespace std;

class Polygon
{
  protected:
    int width, height;
  public:
    void set_values (int a, int b) { width = a; height = b; }
    virtual int area () { return 0; } // THIS IS A BAD EXAMPLE, BUT OK UNTIL LATER THIS WEEK
};

class Rectangle: public Polygon
{
  public:
    int area () { return width * height; }
};

class Triangle: public Polygon
{
  public:
    int area () { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon * prect = &rect;
  Polygon * ptri = &trgl;
  //Polygon * ppoly = &poly;
  prect->set_values (4,5);
  ptri->set_values (4,5);
  //ppoly->set_values (4,5);
  cout << prect->area() << '\n';
  cout << ptri->area() << '\n';
  //cout << ppoly->area() << '\n';
  return 0;
}