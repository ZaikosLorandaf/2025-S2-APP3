#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "forme.h"

class Circle: public Shape {
  public:
    Circle();
    Circle(Coordonnee xy, int r);
    Circle(int x, int y, int r);
    ~Circle();

    int getRadius();
    void setRadius(int r);

    double area() override;
    void display(ostream &s) override;
  private:
      int itsRadius;
      int itsX;
      int itsY;
};

#endif
