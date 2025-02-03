#include "vecteur.h"

MyVector::MyVector() {
  capacity = INIT_VEC_SIZE;
  layers = new Layer*[capacity];
}

MyVector::~MyVector() {
  for (int i = 0; i < currentMaxIndex; i++)
    delete layers[i];
}

bool MyVector::addLayerVec(Layer* c) {
  if (c == NULL)
    return false;
  if (currentMaxIndex == capacity-1)
    increaseSize();
  currentMaxIndex++;
  layers[currentMaxIndex] = c;
  return true;
}

void MyVector::increaseSize() {
  capacity *= 2;
  Layer** newTemp = new Layer*[capacity];
  for (int i = 0; i <= currentMaxIndex; i++)
    newTemp[i] = layers[i];

  delete[] layers;
  layers = newTemp;
}

int MyVector::getCurrentSize() {
  return currentMaxIndex;
}

bool MyVector::emptyVector() {
  for (int i = 0; i < currentMaxIndex; i++)
    delete layers[i];

  capacity = INIT_VEC_SIZE;
  currentMaxIndex = -1;
  Layer** newCouche = new Layer*[capacity];
  delete[] layers;
  layers = newCouche;
  return true;
}

Layer* MyVector::removeLayer(int index) {
  if (index < 0 || index > currentMaxIndex)
    return NULL;

  Layer* c = layers[index];
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

Layer* MyVector::getLayer(int index) {
  return layers[index];
}

