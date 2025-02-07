#include "layer.h"

Layer::Layer(): size{0}, state{STATE_INIT} {}

Layer::~Layer() {}

int Layer::getLayerState() {
  return state;
}

bool Layer::addShape(Shape* f) {
  if (shapes.getQuantity() > shapes.getCap())
    return false;
  shapes += f;
  size++;
  return true;
}

void Layer::removeShape(int index) {
  if (index >= size)
    return;
  size--;
  shapes.removeItem(index);
}

double Layer::getArea() {
  double sum{0};
  for (int i = 0; i < size; i++)
    sum += shapes[i]->area();
  return sum;
}

bool Layer::translation(int deltaX, int deltaY) {
  for (int i = 0; i < size; i++)
    shapes[i]->moveOrigin(deltaX, deltaY);
  return true;
}

bool Layer::setState(int s) {
  if (s > 2 || s < 0) // 2 = INACTIVE, 1 = ACTIVE, 0 = INIT
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

void Layer::display(std::ostream& s) {
  if (size == 0)
    s << "Couche: Vide";
  for (int i = 0; i < size; i++){
    shapes[i]->display(s);
  }
}

/*void Layer::display(std::ofstream& s) {*/
/*  if (size == 0)*/
/*    s << "Couche: Vide";*/
/*  else*/
/*    for (int i = 0; i < size; i++)*/
/*      s << shapes;*/
/*}*/
/**/
