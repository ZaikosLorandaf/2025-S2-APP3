#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "shape.h"
#include <vector>

#define INIT_VEC_SIZE 2

template<typename T>
class Vector {
  private:
    int capacity;
    int currentMaxIndex;

  public:
    Vector() : capacity(INIT_VEC_SIZE), currentMaxIndex{0} {
      vectorItem = new T[capacity];
    }

    virtual ~Vector() {
      delete[] vectorItem;
    }

    T operator[] (int index) {
      return getItem(index);
    }

    bool addItem(T &c) {
      if (currentMaxIndex == capacity-1)
        increaseSize();
      currentMaxIndex++;
      vectorItem[currentMaxIndex] = c;
      return true;
    }

    void increaseSize() {
      capacity *= 2;
      T* newTemp = new T[capacity];
      for (int i = 0; i <= currentMaxIndex; i++)
        newTemp[i] = vectorItem[i];

      delete[] vectorItem;
      vectorItem = newTemp;
    }

    bool emptyVector() {
      delete[] vectorItem;
      capacity = INIT_VEC_SIZE;
      currentMaxIndex = -1;
      vectorItem = new T[capacity];
      return true;

    }

    T removeItem(int index) {
      if (index < 0 || index > currentMaxIndex)
        return T();
      T item = vectorItem[index];
      if (index == currentMaxIndex) {
        vectorItem[index] = T();
        return item;
      }
      for (int i = index; i < currentMaxIndex; i++)
        vectorItem[i] = vectorItem[i+1];
      vectorItem[currentMaxIndex] = T();
      currentMaxIndex--;
      return item;
    }

    T getItem(int index) {
    if (index < 0 || index > currentMaxIndex)
      return T();
    return vectorItem[index];
    }

    int getCap() { return capacity; }
    int getCurrentSize() { return currentMaxIndex; }
    T* vectorItem;
};

#endif
