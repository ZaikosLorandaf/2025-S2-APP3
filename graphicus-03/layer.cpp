#include "layer.h"

Layer::Layer() {}

Layer::~Layer() {}

int Layer::getLayerState() {
  return state;
}

bool Layer::addShape(Shape* f) {
  if (shapes.getCurrentSize() >= shapes.getCap())
    return false;
  shapes.addItem(f);
  return true;
}

void Layer::removeShape(int index) {
  if (index > sizeIndex)
    return;
  delete shapes.removeItem(index);
  sizeIndex--;
}

double Layer::getArea() {
  double sum{0};
  for (int i = 0; i < shapes.getCurrentSize(); i++)
    sum += shapes[i]->area();
  return sum;
}

bool Layer::translation(int deltaX, int deltaY) {
  for (int i = 0; i < sizeIndex; i++)
    shapes[i]->moveOrigin(deltaX, deltaY);
  return true;
}

bool Layer::setState(int s) {
  if (s > 2 || s < 0)
    return false;
  state = s;
  return true;
}

int Layer::getIndex() {
  return sizeIndex;
}

Shape* Layer::getShape(int index) {
  if (index > sizeIndex)
    return NULL;
  return shapes[index];
}

bool Layer::reset() {
  for (int i = 0; i < sizeIndex; i++)
    if (shapes[i] != NULL)
      delete shapes[i];
  sizeIndex = -1;
  state = STATE_INIT;
  return true;
};

