#include "couche.h"
#include "forme.h"

Layer::Layer() {
  state = STATE_INIT;
  for (int i = 0; i < MAX_FORMES; i++)
    formes[i] = NULL;
}
Layer::~Layer() {
  for (int i = 0; i < MAX_FORMES; i++)
    if (formes[i] != NULL)
      delete formes[i];
}

int Layer::getStateLay() {
  return state;
}

bool Layer::addShapeLay(Shape* f) {
  if (sizeIndex >= MAX_FORMES-1)
    return false;
  sizeIndex++;
  formes[sizeIndex] = f;
  return true;
}

Shape* Layer::removeShape(int index) {
  if (index > sizeIndex)
    return NULL;
  Shape* f = formes[index];
  delete f;
  for (int i = index; i <= sizeIndex; i++)
    formes[i] = formes[i+1];
  formes[sizeIndex] = NULL;
  sizeIndex--;
  return NULL;
}

Shape* Layer::getShapeLay(int index) {
  if (index > sizeIndex)
    return NULL;
  return formes[index];
}

double Layer::getArea() {
  double sum{0};
  for (int i = 0; i < sizeIndex; i++)
    sum += formes[i]->area();
  return sum;
}

bool Layer::translation(int deltaX, int deltaY) {
  for (int i = 0; i < sizeIndex; i++)
    formes[i]->moveOrigin(deltaX, deltaY);
  return true;
}

bool Layer::reset() {
  for (int i = 0; i < MAX_FORMES; i++)
    if (formes[i] != NULL) {
      delete formes[i];
      formes[i] = NULL;
    }
  sizeIndex = -1;
  state = STATE_INIT;
  return true;
};

bool Layer::setState(int s) {
  if (s > 2 || s < 0)
    return false;
  state = s;
  return true;
}

int Layer::getIndex() {
  return sizeIndex;
}
