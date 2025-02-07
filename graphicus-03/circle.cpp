#include "circle.h"
#include <cmath>

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

void Circle::display(std::ostream &s) {
  s << "S " << getAnchor().x << " "
    << getAnchor().y << " "
    << getRadius() << std::endl;
}
