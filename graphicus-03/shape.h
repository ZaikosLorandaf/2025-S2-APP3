#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "coordonnee.h"
#include <iostream>

using namespace std;

class Shape {
public:
  Shape(int x = 0, int y = 0);
  virtual ~Shape();
  void moveOrigin(int deltaX, int deltaY);
  Coordonnee getAnchor();
  void setAnchor(Coordonnee c);
  virtual double area() = 0;
  virtual void display(ostream & s) = 0;
protected:
  Coordonnee anchor{0};
};

#endif
