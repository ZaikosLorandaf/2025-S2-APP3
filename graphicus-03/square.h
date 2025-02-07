#ifndef __carre_H__
#define __carre_H__

#include "coordonnee.h"
#include "shape.h"
#include "rectangle.h"

class Square: public Rectangle {
  public:
    Square();
    Square(Coordonnee xy, int l);
    Square(int x, int y, int l);
    ~Square();

    void display(std::ostream &s) override;
};
#endif
