// Copyright 2021 NNTU-CS
#include "train.h"

Train::Cage* Train::create(bool light) {
  Cage* item = new Cage;
  item->light = light;
  item->next = nullptr;
  item->prev = nullptr;
  return item;
}

Train::Train() {
  first = tail = nullptr;
  countOp = length = Count = 0;
}

void Train::addCage(bool light) {
  if (!(first)) {
    first = create(light);
    tail = first;
  } else {
    tail->next = create(light);
    tail->next->prev = tail;
    tail = tail->next;
  if (!tail->next) {
      tail->next = first;
  } else {
      first->prev = tail;
  }
}

int Train::getLength() {
  first->light = true;
  Cage* temp = first;
  while (true) {
      length++;
      for (int i = 0; i < length; i++) {
          temp = temp->next;
          countOp++;
      }
      if (temp->light) {
          temp->light = false;
          for (int i = 0; i < length; i++) {
              temp = temp->prev;
              countOp++;
          }
      } else {
          while (!temp->light) {
              length++;
              temp = temp->next;
              countOp++;
          }
          temp->light = false;
          for (int i = 0; i < length; i++) {
              temp = temp->prev;
              countOp++;
          }
      }
      if (!temp->light) {
          break;
      }
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
