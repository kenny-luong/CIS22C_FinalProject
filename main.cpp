#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "hash.h"
#include "BST.cpp"
#include "Business.h"

// #include "User.h"
// #include "BinarySearchTree.h"

using namespace std;

template<class Type>
bool openTextFile (BST<Type> &tree, Hash<Type> &hash) {
    ifstream businessData;

    try {
        businessData.open("businesses.txt");
        if (!businessData.is_open()) {
                throw 1;
        }
    }
    catch (int x) {
        cout << "Error openning file.";
        system("pause");
        return 0;
    }

    string tempInput;

    businessData.close();

    businessData.open("businesses.txt", ios::in);

    while (!businessData.eof()) {
      getline(businessData, tempInput);
      Business *tempBusiness = new Business(tempInput);

      tree.insertBST(*tempBusiness, tempBusiness->getName());
      hash.add(tempBusiness->getName(), *tempBusiness);
      delete tempBusiness;
    }

    businessData.close();
    return 1;
}

int main() {
  BST<Business> tree;
  Hash<Business> hash;
  openTextFile(tree, hash);

  hash.displayList();
}
