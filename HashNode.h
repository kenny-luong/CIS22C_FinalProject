#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <string>

template <class Type>
class HashNode {
public:
  std::string keyValue;
  Type data;
  HashNode<Type> *link;
};

#endif
