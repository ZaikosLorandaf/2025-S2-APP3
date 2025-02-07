#ifndef __LAYER_H__
#define __LAYER_H__

#define STATE_INIT 0
#define STATE_ACTIVE 1
#define STATE_INACTIVE 2

#include "shape.h"
#include "vector.h"

class Layer {
  public:
    Layer();
    virtual ~Layer();

    friend std::ostream& operator<<(std::ostream& s, Layer& l);
    int getLayerState();
    bool addShape(Shape* f);
    void removeShape(int index);

    double getArea();
    bool translation(int deltaX, int deltaY);

    bool setState(int s);
    int getSize();
    Shape getShape(int index);

    bool reset();

    void display(std::ostream& s);
  private:
    Vector<Shape*> shapes;
    int size;
    int state;
};

#endif

