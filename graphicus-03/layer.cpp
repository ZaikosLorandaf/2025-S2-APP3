#include "layer.h"

Layer::Layer(): size{0}, state{STATE_INIT} {}

Layer::~Layer() {}

int Layer::getLayerState() {
  return state;
}

bool Layer::addShape(Shape* f) {
  if (shapes.getCurrentSize() >= shapes.getCap())
    return false;
  shapes.addItem(f);
  size++;
  return true;
}

void Layer::removeShape(int index) {
  if (index >= size)
    return;
  size--;
  delete shapes.removeItem(index);
}

double Layer::getArea() {
  double sum{0};
  for (int i = 0; i < shapes.getCurrentSize(); i++)
    sum += shapes[i]->area();
  return sum;
}

bool Layer::translation(int deltaX, int deltaY) {
  for (int i = 0; i < size; i++)
    shapes[i]->moveOrigin(deltaX, deltaY);
  return true;
}

bool Layer::setState(int s) {
  if (s > 2 || s < 0)
    return false;
  state = s;
  return true;
}

int Layer::getSize() {
  return size;
}

Shape* Layer::getShape(int index) {
  if (index >= size)
    return NULL;
  return shapes[index];
}

bool Layer::reset() {
  for (int i = 0; i < size; i++)
    if (shapes[i] != NULL)
      delete shapes[i];
  size = 0;
  state = STATE_INIT;
  return true;
};

