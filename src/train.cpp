// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage *item = new Cage;
  item->light = light;
  item->prev = item->next = nullptr;
  if (first == nullptr) {
    first = item;
  } else if (first->next == nullptr) {
    first->next = item;
    item->prev = first;
    first->prev = item;
    item->next = first;
  } else {
    first->prev->next = first->prev = item;
    item->prev = first->prev;
    item->next = first;
  }
}

int Train::getLength() {
  Cage* current = first;
  first->light = true;
  int lenght = 0;
  countOp = 0;
  while (true) {
    countOp++;
    lenght++;
    int tr_lenght;
    current = current->next;
    if (current->light) {
      current->light = false;
      tr_lenght = lenght;
      for (tr_lenght; tr_lenght > 0; tr_lenght--) {
        current = current->prev;
        countOp++;
      }
      if (!current->light) {
        return lenght;
      }
      lenght = tr_lenght;
    }
  }
}
int Train::getOpCount() {
  return countOp;
}
