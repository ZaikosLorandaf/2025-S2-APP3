#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "shape.h"

class Circle: public Shape {
  public:
    Circle();
    Circle(Coordonnee xy, int r);
    Circle(int x, int y, int r);
    ~Circle();

    int getRadius();
    void setRadius(int r);

    double area() override;
    void display(std::ostream &s) override;
  private:
      int itsRadius;
      int itsX;
      int itsY;
};

#endif
