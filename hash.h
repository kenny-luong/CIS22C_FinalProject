#ifndef HASH_H
#define HASH_H

#include "HashNode.h"
#include <string>

using namespace std;

template<class Type>
class Hash {
public:
  static const int SIZE = 53;
  HashNode<Type> *bucket[SIZE];
  int count;
public:
  Hash() {
    for (int i = 0; i < SIZE; i++) {
      bucket[i] = NULL;
      count = 0;
    }
  }

  int getSize() {
    return SIZE;
  }

  bool add(string keyValue, const Type& object) {
    HashNode<Type> *newNode = new HashNode<Type>;
    newNode->data = object;
    newNode->keyValue = keyValue;
    newNode->link = NULL;

    int index = hashFunction(keyValue);

    HashNode<Type> *temp = bucket[index];
    if (count < 3) {
      if (bucket[index] == NULL) {
        bucket[index] = newNode;
      } else {
        while (temp->link != NULL) {
          temp = temp->link;
        }
        temp->link = newNode;
      }
      count++;
      return true;
    }
    return false;
  }

  void displayList(string keyValue) {
    int index = hashFunction(keyValue);

    HashNode<Type> *temp = bucket[index];

    while (temp != NULL) {
      cout << temp->keyValue << endl;
      temp = temp->link;
    }
  }

  /*
    deleteObject requires that you verify the object exists already.
  */

  bool deleteObject(string keyValue) {
    int index = hashFunction(keyValue);

    HashNode<Type> *temp = bucket[index];
    HashNode<Type> *trail;

    if (bucket[index] == NULL) {
      cout << "Does not exist here." << endl;
    }
    if (keyValue == bucket[index]->keyValue) {
      bucket[index] = bucket[index]->link;
      return true;
    } else {
      while (temp != NULL) {
        trail = temp;
        temp = temp->link;
        if (temp->keyValue == keyValue) {
          trail = temp->link;
          temp->link = NULL;
          delete temp;
          return true;
        }
      }
    }
    return false;
  }

  int hashFunction(string& keyValue) {
    int value = 0;
    for (int i = 0; i < keyValue.length(); i++) {
      value += keyValue.at(i);
    }
    return value % SIZE;
  }
};

#endif
