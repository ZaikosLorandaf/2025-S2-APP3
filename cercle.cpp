#include "cercle.h"
#include <cfenv>
#include <cmath>
#include <iomanip>

Circle::Circle(){}
Circle::Circle(Coordonnee xy, int r):Shape(xy.x, xy.y) {
  setRadius(r);
}
Circle::Circle(int x, int y, int r):Shape(x, y) {
  setRadius(r);
}
Circle::~Circle(){};

int Circle::getRadius() {
  return itsRadius;
}

void Circle::setRadius(int r){
  itsRadius = r;
}

double Circle::area() {
  return itsRadius*itsRadius*M_PI;
}

void Circle::display(ostream &s) {
  s << "Cercle (x=" << getAnchor().x
    << ", y=" << getAnchor().y
    << ", r=" << getRadius()
    << std::fixed
    << std::setprecision(2)
    << ", aire=" << area()
    << ")" << std::endl;
}
