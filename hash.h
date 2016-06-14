#ifndef HASH_H
#define HASH_H

#include "HashNode.h"
#include <string>
#include "Business.h"
#include "includes.h"

using namespace std;

template<class Type>
class Hash {
public:
  static const int SIZE = 53;
  HashNode<Type> *bucket[SIZE];
public:
  Hash() {
    for (int i = 0; i < SIZE; i++) {
      bucket[i] = NULL;
    }
  }

  int getSize() {
    return SIZE;
  }

  bool add(string keyValue, Type object) {
    HashNode<Type> *newNode = new HashNode<Type>;
    newNode->data = object;
    newNode->keyValue = keyValue;
    newNode->link = NULL;

    int index = hashFunction(keyValue);

    HashNode<Type> *temp = bucket[index];

    if (bucket[index] == NULL) {
      bucket[index] = newNode;
      bucket[index]->count++;
    } else {
      if (bucket[index]->count < 3) {
        while (temp->link != NULL) {
          temp = temp->link;
        }
        temp->link = newNode;
        bucket[index]->count++;
      } else {
        std::cout << "Bucket at index " << index << " is full." << std::endl;
        std::cout << keyValue << " was not added." << std::endl;
      }
    }
    return true;

    return false;
  }


  void displayList() {
    for (int i = 0; i < SIZE; i++) {
      if (bucket[i] != NULL) {
        printCharMultiTimes('-', 30);
        cout << endl << "Index: " << i << endl;
        printCharMultiTimes('-', 30);
        cout << endl;
        bucket[i]->displayBucket(bucket[i]);
      }
    }
  }

  bool contains(string keyValue) {
    int index = hashFunction(keyValue);

    HashNode<Type> *temp = bucket[index];
    HashNode<Type> *trail;

    if (bucket[index] == NULL) {
      return false;
    } else {
      if (keyValue == bucket[index]->data.getName()) {
        return true;
      } else {
        while (temp != NULL) {
          trail = temp;
          temp = temp->link;
          if (temp->keyValue == keyValue) {
            return true;
          }
        }
      }
    }
    return false;
  }

  Business *getBusiness(string keyValue) {
    int index = hashFunction(keyValue);

    HashNode<Type> *temp = bucket[index];
    HashNode<Type> *trail;

    if (keyValue == bucket[index]->data.getName()) {
        return &temp->data;
    } else {
      while (temp != NULL) {
        trail = temp;
        temp = temp->link;
        if (temp->keyValue == keyValue) {
          return &temp->data;
        }
      }
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
      return false;
    } else {
      if (keyValue == bucket[index]->data.getName()) {
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
