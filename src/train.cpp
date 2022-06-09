// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->prev = cage->next = nullptr;
  if (first == nullptr) {
    first = cage;
  } else if (first->next == nullptr) {
    first->next = cage;
    cage->prev = first;
    first->prev = cage;
    cage->next = first;
  } else {
    first->prev->next = first->prev = cage;
    cage->prev = first->prev;
    cage->next = first;
  }
}

int Train::getLength() {
  Cage* current = first;
  first->light = true;
  int len = 0;
  countOp = 0;
  while (true) {
    countOp++;
    len++;
    int tr_len;
    current = current->next;
    if (current->light) {
      current->light = false;
      tr_len = len;
      for (tr_len; tr_len > 0; tr_len--) {
        current = current->prev;
        countOp++;
      }
      if (!current->light) {
        return len;
      }
      len = tr_len;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
