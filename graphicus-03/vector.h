#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "shape.h"
#include <vector>

#define INIT_VEC_SIZE 2

template<typename T>
class Vector {
  private:
    int capacity;
    int currentMax;

  public:
    Vector() : capacity(INIT_VEC_SIZE), currentMax{0} {
      vectorItem = new T[capacity];
    }

    virtual ~Vector() {
      delete[] vectorItem;
    }

    T operator[] (int index) {
      return getItem(index);
    }

    bool addItem(T &c) {
      if (currentMax == capacity)
        increaseSize();
      vectorItem[currentMax] = c;
      currentMax++;
      return true;
    }

    void increaseSize() {
      capacity *= 2;
      T* newTemp = new T[capacity];
      for (int i = 0; i < currentMax; i++)
        newTemp[i] = vectorItem[i];

      delete[] vectorItem;
      vectorItem = newTemp;
    }

    bool emptyVector() {
      delete[] vectorItem;
      capacity = INIT_VEC_SIZE;
      currentMax = 0;
      vectorItem = new T[capacity];
      return true;

    }

    T removeItem(int index) {
      if (index < 0 || index > currentMax)
        return T();
      T item = vectorItem[index];
      if (index == currentMax) {
        vectorItem[index] = T();
        return item;
      }
      for (int i = index; i < currentMax; i++)
        vectorItem[i] = vectorItem[i+1];
      vectorItem[currentMax] = T();
      currentMax--;
      return item;
    }

    T getItem(int index) {
    if (index < 0 || index >= currentMax)
      return T();
    return vectorItem[index];
    }

    int getCap() { return capacity; }
    int getCurrentSize() { return currentMax; }
    T* vectorItem;
};

#endif
