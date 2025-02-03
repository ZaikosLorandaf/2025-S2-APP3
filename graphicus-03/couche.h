#ifndef COUCHE_H
#define COUCHE_H

#define STATE_INIT 0
#define STATE_ACTIVE 1
#define STATE_INACTIVE 2


#include "forme.h"

const int MAX_FORMES = 5;

class Layer {
  public:
    Layer();
    virtual ~Layer();
    int getStateLay();
    bool addShapeLay(Shape* f);
    Shape* removeShape(int index);
    Shape* getShapeLay(int index);
    double getArea();
    bool translation(int deltaX, int deltaY);
    bool reset();
    bool setState(int s);
    int getIndex();
    void display(ostream &s);
  private:
    Shape* formes[MAX_FORMES];
    int sizeIndex{-1};
    int state{0};
};

#endif

