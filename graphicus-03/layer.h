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
    int getLayerState();
    bool addShape(Shape* f);
    void removeShape(int index);
    double getArea();
    bool translation(int deltaX, int deltaY);
    bool setState(int s);
    int getIndex();
    Shape* getShape(int index);
    bool reset();
  private:
    Vector<Shape*> shapes;
    int sizeIndex{-1};
    int state{STATE_INIT};
};

#endif

