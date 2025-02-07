/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe Canevas. La classe Canevas gere un
 *    vecteur de pointeur de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "layer.h"
#include "shape.h"
#include "vector.h"

#define NO_LAYER_ACTIVE -1

using namespace std;

class Canevas
{
  public:
    friend Shape;

    Canevas();
    virtual ~Canevas();

    friend ostream& operator<<(ostream& s, Canevas& c);

    bool addLayerCan();
    bool removeLayerCan(int index);

    void nextLayer();
    void prevLayer();

    bool reset();
    bool resetLayer(int index);

    bool activateLayer(int index);
    bool deactivateLayer(int index);

    bool addShape(Shape *p_forme);
    bool removeShape(int index);

    double area();
    bool translation(int deltaX, int deltaY);
    void display(ostream & s);

  private:
    Vector<Layer*> layers;
    /*int activeLayer;*/
};

#endif
