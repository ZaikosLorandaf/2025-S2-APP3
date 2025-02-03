#include "canevas.h"
#include "couche.h"
#include "vecteur.h"
#include <csignal>

Canevas::Canevas(){
  vector = new MyVector();
}
Canevas::~Canevas() {
  delete vector;
}

bool Canevas::addLayerCan() {
  Layer* l = new Layer();
  vector->addLayerVec(l);
  return true;
}

bool Canevas::removeLayerCan(int index) {
  if (index < 0 || index > vector->getCurrentSize())
    return false;
  vector->removeLayer(index);
  vector->getLayer(index)->setState(STATE_INIT);
  activeLayer = NO_LAYER_ACTIVE;
  return true;
}

bool Canevas::reset() {
  vector->emptyVector();
  activeLayer = NO_LAYER_ACTIVE;
  return true;
}

bool Canevas::resetLayer(int index) {
  if (vector->getLayer(index)->getStateLay() == STATE_ACTIVE)
    return false;
  return vector->getLayer(index)->reset();
}

bool Canevas::activateLayer(int index) {
  if (index > vector->getCurrentSize())
    for (int i = vector->getCurrentSize()+1; i <= index; i++)
      addLayerCan();
  deactivateLayer(activeLayer);
  activeLayer = index;
  return vector->getLayer(index)->setState(STATE_ACTIVE);
}

bool Canevas::deactivateLayer(int index) {
  if (index != activeLayer)
    return false;
  if (index == NO_LAYER_ACTIVE)
    return true;
  activeLayer = NO_LAYER_ACTIVE;
  return vector->getLayer(index)->setState(STATE_INACTIVE);
}

bool Canevas::addShape(Shape *p_forme) {
  if (p_forme == NULL)
    return false;
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  vector->getLayer(activeLayer)->addShapeLay(p_forme);
  return true;
}

bool Canevas::removeShape(int index) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  vector->getLayer(activeLayer)->removeShape(index);
  return true;
}

double Canevas::area() {
  int areaSum{0};
  for (int i = 0; i < vector->getCurrentSize(); i++)
    areaSum += vector->getLayer(i)->getArea();
  return areaSum;
}

bool Canevas::translation(int deltaX, int deltaY) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  return vector->getLayer(activeLayer)->translation(deltaX, deltaY);
}

void Canevas::display(ostream & s) {
  if (vector->getCurrentSize() == -1) {
    s << "---- Aucune Couche ----\n";
    return;
  }

  for (int i = 0; i <= vector->getCurrentSize(); i++) {
    s << std::endl << "---- Couche " << i << " ----" << std::endl;

    /*vector->getLayer(i)->display(s);*/

    s << "Etat: ";
    switch (vector->getLayer(i)->getStateLay()) {
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

    if (vector->getLayer(i)->getIndex() == -1) {
      s << "Couche: vide" << std::endl;
    } else {
      for (int j = 0; j <= vector->getLayer(i)->getIndex(); j++)
        vector->getLayer(i)->getShapeLay(j)->display(s);
    }

  }
}

