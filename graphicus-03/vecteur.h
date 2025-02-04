#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "couche.h"
#include "forme.h"

#define INIT_VEC_SIZE 2

template<typename T>
class MyVector {
  private:
    int capacity;
    int currentMaxIndex{-1};

  public:
    MyVector() {
      capacity = INIT_VEC_SIZE;
      layers = new T*[capacity];
    }

    virtual ~MyVector() {
      for (int i = 0; i < currentMaxIndex; i++)
        delete layers[i];
    }

    bool addLayerVec(T* c) {
      if (c == NULL)
        return false;
      if (currentMaxIndex == capacity-1)
        increaseSize();
      currentMaxIndex++;
      layers[currentMaxIndex] = c;
      return true;
    }

    void increaseSize() {
      capacity *= 2;
      T** newTemp = new T*[capacity];
      for (int i = 0; i <= currentMaxIndex; i++)
        newTemp[i] = layers[i];

      delete[] layers;
      layers = newTemp;
    }

    bool emptyVector() {
      for (int i = 0; i < currentMaxIndex; i++)
        delete layers[i];

      capacity = INIT_VEC_SIZE;
      currentMaxIndex = -1;
      T** newCouche = new T*[capacity];
      delete[] layers;
      layers = newCouche;
      return true;

    }

    T* removeLayer(int index) {
      if (index < 0 || index > currentMaxIndex)
        return NULL;

      T* c = layers[index];
      if (index == currentMaxIndex) {
        layers[index] = NULL;
        return c;
      }
      for (int i = index; i < currentMaxIndex; i++)
        layers[i] = layers[i+1];

      layers[currentMaxIndex] = NULL;
      currentMaxIndex--;
      delete c;
      return NULL;
    }

    T* getLayer(int index) {
      return layers[index];
    }

    int getCurrentSize() { return currentMaxIndex; }
    T** layers;
};

#endif
