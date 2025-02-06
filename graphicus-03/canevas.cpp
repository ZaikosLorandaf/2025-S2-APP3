#include "canevas.h"

Canevas::Canevas() : activeLayer{-1} {}

Canevas::~Canevas() {
}

bool Canevas::addLayerCan() {
  Layer* l = new Layer();
  layers.addItem(*l);
  return true;
}

bool Canevas::removeLayerCan(int index) {
  if (index < 0 || index > layers.getCurrentSize())
    return false;
  layers.removeItem(index);
  layers.getItem(index).setState(STATE_INIT);
  activeLayer = NO_LAYER_ACTIVE;
  return true;
}

bool Canevas::reset() {
  layers.emptyVector();
  activeLayer = NO_LAYER_ACTIVE;
  return true;
}

bool Canevas::resetLayer(int index) {
  if (layers[index].getLayerState() == STATE_INACTIVE)
    return false;
  layers.removeItem(index);
  return true;
}

bool Canevas::activateLayer(int index) {
  if (index > layers.getCurrentSize())
    for (int i = layers.getCurrentSize()+1; i <= index; i++)
      addLayerCan();
  deactivateLayer(activeLayer);
  activeLayer = index;
  return layers.getItem(index).setState(STATE_ACTIVE);
}

bool Canevas::deactivateLayer(int index) {
  if (index != activeLayer)
    return false;
  if (index == NO_LAYER_ACTIVE)
    return true;
  activeLayer = NO_LAYER_ACTIVE;
  return layers.getItem(index).setState(STATE_INACTIVE);
}

bool Canevas::addShape(Shape *p_forme) {
  if (p_forme == NULL)
    return false;
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  layers[activeLayer].addShape(p_forme);
  return true;

}

bool Canevas::removeShape(int index) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  layers.getItem(activeLayer).removeShape(index);
  return true;
}

double Canevas::area() {
  int areaSum{0};
  for (int i = 0; i < layers.getCurrentSize(); i++)
    areaSum += layers.getItem(i).getArea();
  return areaSum;
}

bool Canevas::translation(int deltaX, int deltaY) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  return layers.getItem(activeLayer).translation(deltaX, deltaY);
}

void Canevas::display(ostream & s) {
  if (layers.getCurrentSize() == -1) {
    s << "---- Aucune Couche ----\n";
    return;
  }

  for (int i = 0; i <= layers.getCurrentSize(); i++) {
    s << std::endl << "---- Couche " << i << " ----" << std::endl;
    s << "Etat: ";
    switch (layers.getItem(i).getLayerState()) {
      case 0:
        s << "Initialised\n";
        break;
      case 1:
        s << "Active\n";
        break;
      case 2:
        s << "Inactive\n";
        break;
    };

    if (layers[i].getIndex() == -1) {
      s << "Couche: vide" << std::endl;
    } else {
      for (int j = 0; j <= layers.getItem(i).getIndex(); j++)
        layers[i].getShape(j)->display(s);
    }
  }
}

