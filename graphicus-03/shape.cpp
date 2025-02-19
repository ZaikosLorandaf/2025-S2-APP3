#include "shape.h"

Shape::Shape(int x1, int y1) {
  anchor.x = x1;
  anchor.y = y1;
}

Shape::~Shape() {}

std::ostream& operator<<(std::ostream& s, Shape& shape){
  shape.display(s);
  return s;
}

void Shape::moveOrigin(int deltaX, int deltaY) {
   anchor.x += deltaX;
   anchor.y += deltaY;
}

Coordonnee Shape::getAnchor() {
   return anchor;
}

void Shape::setAnchor(Coordonnee c) {
   anchor = c;
}
