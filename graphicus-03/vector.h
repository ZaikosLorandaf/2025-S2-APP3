#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "shape.h"
#include <sstream>

#define INIT_VEC_SIZE 2

template<typename T>
class Vector {
  private:
    int capacity{INIT_VEC_SIZE};
    int quantity{0};
    int activeIndex{-1};

  public:
    T* vectorItem;
    // File Read
    /*friend std::istream& operator>>(std::istream& s, Vector<T>& vec) {}*/

    // File Write
    friend std::ostream& operator<<(std::ostream& s, Vector<T>& vec) {
      for (int i = 0; i < vec.getQuantity(); i++)
        if (vec.vectorItem[i] != nullptr)
          s << *(vec.vectorItem[i]) << std::endl;
      return s;
    }

    friend std::ofstream& operator<<(std::ofstream& s, Vector<T>& vec) {
      for (int i = 0; i < vec.getQuantity(); i++)
        if (vec.vectorItem[i] != nullptr)
          s << *(vec.vectorItem[i]) << std::endl;
      return s;
    }

    friend std::ostringstream& operator<<(std::ostringstream& s, Vector<T>& vec) {
      for (int i = 0; i < vec.getQuantity(); i++)
        if (vec.vectorItem[i] != nullptr)
          s << *(vec.vectorItem[i]) << std::endl;
      return s;
    }


    Vector() {
      vectorItem = new T[capacity];
    }

    virtual ~Vector() {
      /*delete vectorItem;*/
    }

    Vector(const Vector<T>& copy): capacity{copy.capacity}, quantity{copy.quantity} {
      vectorItem = new T[capacity];
      for (int i = 0; i < quantity; i++)
        vectorItem[i] = copy.vectorItem[i];
    }

    T& operator[] (int index) { return getItem(index); }

    void operator++ () {
      if (activeIndex == quantity-1)
        return;
      activeIndex++;
    }

    void operator-- () {
      if (activeIndex == 0)
        return;
      activeIndex--;
    }

    void operator+= (const T &c) {
      if (quantity == capacity)
        increaseSize();
      vectorItem[quantity] = c;
      quantity++;
    }

    /*bool addItem(const T &c) {*/
    /*  if (quantity == capacity)*/
    /*    increaseSize();*/
    /*  vectorItem[quantity] = c;*/
    /*  quantity++;*/
    /*  return true;*/
    /*}*/

    void increaseSize() {
      capacity *= 2;
      T* newTemp = new T[capacity];
      for (int i = 0; i < quantity; i++)
        newTemp[i] = vectorItem[i];
      /*delete[] vectorItem;*/
      vectorItem = newTemp;
    }

    bool emptyVector() {
      /*delete[] vectorItem;*/
      vectorItem = NULL;
      capacity = INIT_VEC_SIZE;
      quantity = 0;
      vectorItem = new T[capacity];
      return true;
    }

    void removeItem(int index) {
      if (index < 0 || index >= quantity)
        throw std::out_of_range("Index out of range");
      if (index == quantity-1) {
        vectorItem[index].~T();
        vectorItem[index] = T();
      }
      for (int i = index; i < quantity; i++)
        vectorItem[i] = vectorItem[i+1];
      vectorItem[quantity].~T();
      vectorItem[quantity] = T();
      quantity--;
    }

    T& getItem(int index) {
      if (index < 0 || index > quantity)
        throw std::out_of_range("Index out of range");
      return vectorItem[index];
    }

    T& getItem() { return vectorItem[activeIndex]; }


    void setActiveItem(int i) { activeIndex = i; }
    int getActiveIndex() { return activeIndex; }

    int getCap() { return capacity; }
    int getQuantity() { return quantity; }
};

#endif
