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
#include "forme.h"
#include "couche.h"
#include "vecteur.h"

#define NO_LAYER_ACTIVE -1

using namespace std;

class Canevas
{
  public:
    Canevas();
    virtual ~Canevas();

    bool addLayerCan();
    bool removeLayerCan(int index);

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
    MyVector *vector;
    int activeLayer{-1};
};

#endif
