#include "rectangle.h"

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

void Rectangle::display(std::ostream &s) {
  s << "S " << getAnchor().x << " "
    << getAnchor().y << " "
    << getLength() << " "
    << getWidth() << std::endl;
}
