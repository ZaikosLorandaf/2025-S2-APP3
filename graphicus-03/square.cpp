#include "square.h"
#include "rectangle.h"


Square::Square():Rectangle(){}
Square::Square(Coordonnee xy, int l):Rectangle(xy, l, l) {}
Square::Square(int x, int y, int l):Rectangle(x, y, l, l) {}
Square::~Square(){}



void Square::display(std::ostream &s) {
  s << "S " << getAnchor().x << " "
    << getAnchor().y << " " << getLength() << std::endl;
}


