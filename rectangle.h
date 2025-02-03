#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "forme.h"

class Rectangle: public Shape {
  public:
    Rectangle();
    Rectangle(Coordonnee xy, int l, int w);
    Rectangle(int x, int y, int l, int w);
    virtual ~Rectangle();

    int getLength();
    void setLength(int l);

    int getWidth();
    void setWidth(int w);

    double area() override;

    void display(ostream &s) override;

  private:
    int itsLength;
    int itsWidth;
};
#endif
