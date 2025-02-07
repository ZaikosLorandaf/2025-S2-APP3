#include "canevas.h"

Canevas::Canevas() {}

Canevas::~Canevas() {
}

bool Canevas::addLayerCan() {
  /*Layer l;*/
  Layer l = *new Layer();
  layers += l;
  return true;
}

bool Canevas::removeLayerCan(int index) {
  if (index < 0 || index > layers.getQuantity())
    return false;
  layers.removeItem(index);
  layers.getItem(index).setState(STATE_INIT);
  layers.setActiveItem(NO_LAYER_ACTIVE);
  /*activeLayer = NO_LAYER_ACTIVE;*/
  return true;
}


std::ostream& operator<<(std::ostream& s, Canevas& c) {
  return s << c.layers;
}

void Canevas::nextLayer() {
  layers.getItem().setState(STATE_INACTIVE);
  ++layers;
  layers.getItem().setState(STATE_ACTIVE);
}

void Canevas::prevLayer() {
  layers.getItem().setState(STATE_INACTIVE);
  --layers;
  layers.getItem().setState(STATE_ACTIVE);
}

bool Canevas::reset() {
  layers.emptyVector();
  layers.setActiveItem(NO_LAYER_ACTIVE);
  /*activeLayer = NO_LAYER_ACTIVE;*/
  return true;
}

bool Canevas::resetLayer(int index) {
  /*if (layers[index].getLayerState() == STATE_INACTIVE)*/
  if (layers.getActiveIndex() == STATE_INACTIVE)
    return false;
  layers.removeItem(index);
  return true;
}

bool Canevas::activateLayer(int index) {
  if (index > layers.getQuantity())
    for (int i = layers.getQuantity()+1; i <= index; i++)
      addLayerCan();
  layers.getItem().setState(STATE_INACTIVE);
  layers.setActiveItem(index);
  return layers.getItem().setState(STATE_ACTIVE);
}

bool Canevas::deactivateLayer(int index) {
  /*if (index != activeLayer)*/
  if (index != layers.getActiveIndex())
    return false;
  if (index == NO_LAYER_ACTIVE)
    return true;
  layers.setActiveItem(NO_LAYER_ACTIVE);
  /*activeLayer = NO_LAYER_ACTIVE;*/
  return layers.getItem(index).setState(STATE_INACTIVE);
}

bool Canevas::addShape(Shape *p_forme) {
  if (p_forme == NULL)
    return false;
  /*if (activeLayer == NO_LAYER_ACTIVE)*/
  if (layers.getActiveIndex() == NO_LAYER_ACTIVE)
    return false;
  /*layers[activeLayer].addShape(p_forme);*/
  layers[layers.getActiveIndex()].addShape(p_forme);
  return true;

}

bool Canevas::removeShape(int index) {
  /*if (activeLayer == NO_LAYER_ACTIVE)*/
  if (layers.getActiveIndex() == NO_LAYER_ACTIVE)
    return false;
  layers.getItem().removeShape(index);
  return true;
}

double Canevas::area() {
  int areaSum{0};
  for (int i = 0; i < layers.getQuantity(); i++)
    areaSum += layers[i].getArea();
  return areaSum;
}

bool Canevas::translation(int deltaX, int deltaY) {
  if (layers.getActiveIndex() == NO_LAYER_ACTIVE)
    return false;
  return layers.getItem().translation(deltaX, deltaY);
}

void Canevas::display(ostream & s) {

  if (layers.getQuantity() == 0) {
    s << "---- Aucune Couche ----\n";
    return;
  }

  for (int i = 0; i <= layers.getQuantity(); i++) {
    s << std::endl << "---- Couche " << i << " ----" << std::endl;

    s << "Etat: ";
    if (i != layers.getActiveIndex()) {
      switch (layers[i].getLayerState()) {
        case 0:
          s << "Initialised\n";
          break;
        case 2:
          s << "Inactive\n";
          break;
      };
    } else
      s << "Active\n";

    if (layers[i].getSize() == 0)
      s << "Couche: vide" << std::endl;
    else
      for (int j = 0; j < layers.getItem(i).getSize(); j++)
        s << layers[i];
  }
}
