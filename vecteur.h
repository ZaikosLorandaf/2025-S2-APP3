#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "couche.h"
#include "forme.h"

#define INIT_VEC_SIZE 2

class MyVector {
  public:
    MyVector();
    virtual ~MyVector();
    bool addLayerVec(Layer* c);
    int getCurrentSize();
    void increaseSize();
    bool emptyVector();
    Layer* removeLayer(int index);
    Layer* getLayer(int index);
    void destroyerOfLayers();
    int getTempCapa();
    Layer** layers;
  private:
    int capacity;
    int currentMaxIndex{-1};
};

#endif
