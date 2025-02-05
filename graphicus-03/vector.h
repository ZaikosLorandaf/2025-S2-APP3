#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "shape.h"
#include <vector>

#define INIT_VEC_SIZE 2

template<typename T>
class Vector {
  private:
    int capacity{INIT_VEC_SIZE};
    int quantity{0};

  public:
    Vector() {
      vectorItem = new T[capacity];
    }

    /*Vector(int cap) : quantity{0} {*/
    /*  vectorItem = new T[cap];*/
    /*}*/


    virtual ~Vector() {
      delete[] vectorItem;
    }

    Vector(const Vector<T>& copy): capacity(copy.capacity), quantity(copy.quantity) {
      vectorItem = new T[capacity];
      for (int i = 0; i < quantity; i++)
        vectorItem[i] = copy.vectorItem[i];
    }

    T operator[] (int index) {
      return getItem(index);
    }

    bool addItem(T &c) {
      if (quantity == capacity)
        increaseSize();
      vectorItem[quantity] = c;
      quantity++;
      return true;
    }

    void increaseSize() {
      capacity *= 2;
      T* newTemp = new T[capacity];
      for (int i = 0; i < quantity; i++)
        newTemp[i] = vectorItem[i];

      delete[] vectorItem;
      vectorItem = newTemp;
    }

    bool emptyVector() {
      delete[] vectorItem;
      capacity = INIT_VEC_SIZE;
      quantity = 0;
      vectorItem = new T[capacity];
      return true;

    }

    T removeItem(int index) {
      if (index < 0 || index > quantity)
        return T();
      T item = vectorItem[index];
      if (index == quantity) {
        vectorItem[index] = T();
        return item;
      }
      for (int i = index; i < quantity; i++)
        vectorItem[i] = vectorItem[i+1];
      vectorItem[quantity] = T();
      quantity--;
      return item;
    }

    T getItem(int index) {
    if (index < 0 || index >= quantity)
      return T();
    return vectorItem[index];
    }

    int getCap() { return capacity; }
    int getCurrentSize() { return quantity; }
    T* vectorItem;
};

#endif
