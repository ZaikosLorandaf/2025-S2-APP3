#include "rectangle.h"
#include "forme.h"

Rectangle::Rectangle(){
  setLength(1);
  setAnchor(anchor);
}
Rectangle::Rectangle(Coordonnee xy, int l, int w):Shape(xy.x, xy.y) {
  setLength(l);
  setWidth(w);
}
Rectangle::Rectangle(int x, int y, int l, int w):Shape(x, y) {
  setLength(l);
  setWidth(w);
}
Rectangle::~Rectangle(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
int Rectangle::getLength() {
  return itsLength;
}

void Rectangle::setLength(int l) {
  itsLength = l;
}

int Rectangle::getWidth() {
  return itsWidth;
}

void Rectangle::setWidth(int w) {
  itsWidth = w;
}

double Rectangle::area() {
  return itsLength * itsWidth;
}

void Rectangle::display(ostream &s) {
  s << "Rectangle (x=" << getAnchor().x
    << ", y=" << getAnchor().y
    << ", l=" << getLength()
    << ", h=" << getWidth()
    << ", aire=" << area()
    << ")" << std::endl;
}
