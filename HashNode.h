#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <string>
#include <iostream>

template <class Type>
class HashNode {
public:
  std::string keyValue;
  Type data;
  HashNode<Type> *link;
  int count;
  HashNode() {
    count = 0;
  }

  void displayBucket(HashNode<Type> *bucket) {
    HashNode<Type> *temp = bucket;

    while (temp != NULL) {
      std::cout << temp->keyValue << std::endl;
      temp = temp->link;
    }
  }
};

#endif
