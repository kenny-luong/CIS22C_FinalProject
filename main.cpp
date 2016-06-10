#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "hash.h"
// #include "User.h"
// #include "BinarySearchTree.h"

using namespace std;

int hash(string& key);

int main() {
  cout << "Hello world" << endl;
}

int hash(string& key) {
  int value = 0;
  for (int i = 0; i < key.length(); i++) {
    value += key.at(i);

  }
  return (value % 101);
}
