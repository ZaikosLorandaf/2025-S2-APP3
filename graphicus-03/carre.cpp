#include "carre.h"
#include "rectangle.h"


Square::Square():Rectangle(){}
Square::Square(Coordonnee xy, int l):Rectangle(xy, l, l) {}
Square::Square(int x, int y, int l):Rectangle(x, y, l, l) {}
Square::~Square(){}



void Square::display(ostream &s) {
  s << "Carre (x=" << getAnchor().x
    << ", y=" << getAnchor().y
    << ", cote=" << getLength()
    << ", aire=" << area()
    << ")" << std::endl;
}


