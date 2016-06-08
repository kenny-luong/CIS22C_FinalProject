#ifndef _BST
#define _BST
#include "BSTNode.cpp"
#include <iostream>

template <class T>
class BST {
private:
	BSTNode<T>* root;
	BSTNode<T>* insertR(BSTNode<T>*, BSTNode<T>*);
	BSTNode<T>* removeNode(BSTNode<T>*, T, BSTNode<T>*);
	void printR(BSTNode<T>*);
	T getMin(BSTNode<T>*);
	bool findR(BSTNode<T>*, T);
public:
	BST();
	~BST();
	void insertBST(T);
	void printBST();
	bool deleteBST(T);
	bool isInTree(T);
	BSTNode<T>* getRoot() { return root; }
};

//default constructor sets root to null
template<class T>
BST<T>::BST() {
	root = nullptr;
}

//recurively inserts a node into the tree
template <class T>
BSTNode<T>* BST<T>::insertR(BSTNode<T>* r, BSTNode<T>* data) {
	if (r == nullptr){ //insert as leaf
		return data;
	}
	else {
		BSTNode<T>* leftPtr = r->getLeft();
		BSTNode<T>* rightPtr = r->getRight();
		if (data->getData() < r->getData()) { //insert as left child
			leftPtr=insertR(leftPtr, data);
			r->setLeft(leftPtr);
		}
		else { //insert as right child
			rightPtr=insertR(rightPtr, data);
			r->setRight(rightPtr);
		}
		return r;
	}
}

//public insert method
//calls recursive insert method
template <class T>
void BST<T>::insertBST(T data) {
	BSTNode<T>* n = new BSTNode<T>(data);	
	root = insertR(root, n);
}

//prints the tree via inorder traversal
template <class T>
void BST<T>::printR(BSTNode<T>* r) {
	if (r == nullptr) {
		return;
	}
	printR(r->getLeft());
	std::cout << r->getData() << " ";
	printR(r->getRight());
}

//calls the recursive inorder print method
template <class T>
void BST<T>::printBST() {
	printR(root);
	std::cout << std::endl;
}

//deletes the node containing the given key if it exists
template <class T>
bool BST<T>::deleteBST(T value) {
	if (root == nullptr) //empty tree
		return false;
	else {
		if (root->getData() == value) { //root contains key
			BSTNode<T> temp(nullptr, nullptr);
			temp.setLeft(root);
			BSTNode<T>* removedNode = removeNode(root, value, &temp);
			root = temp.getLeft();
			if (removedNode != nullptr) {
				delete removedNode;
				return true;
			}
			else
				return false;
		}
		else { //search thre rest of the tree for the key
			BSTNode<T>* removedNode = removeNode(root, value, nullptr);
			if (removedNode != nullptr) {
				delete removedNode;
				return true;
			}
			else
				return false;
		}
	}
}

//recursively searches the given tree for the key
//returns pointer to the node to be deleted
template <class T>
BSTNode<T>* BST<T>::removeNode(BSTNode<T>* r, T value, BSTNode<T>* parent) {
	if (value < r->getData()) { //move down to the left subtree if it exists
		if (r->getLeft() != nullptr)
			return removeNode(r->getLeft(), value, r);
		else
			return nullptr;
	}
	else if (value > r->getData()) { //move down to the right subtree if it exists
		if (r->getRight() != nullptr)
			return removeNode(r->getRight(), value, r);
		else
			return nullptr;
	}
	else { //found the node to be dleted
		if (r->getLeft() != nullptr && r->getRight() != nullptr) { //node is a leaf
			r->setData(getMin(r->getRight()));
			return removeNode(r->getRight(),r->getData(), r);
		}
		else if (parent->getLeft() == r) { //node is left child of a 2-node
			parent->setLeft((r->getLeft() != nullptr) ? r->getLeft() : r->getRight());
			return r;
		}
		else if (parent->getRight() == r) { //node is right child of a 2-node
			parent->setRight((r->getLeft() != nullptr) ? r->getLeft() : r->getRight());
			return r;
		}
	}
}

//returns the minimum value of a given tree
template <class T>
T BST<T>::getMin(BSTNode<T>* node) {
	if (node->getLeft() == nullptr)
		return node->getData();
	else
		return getMin(node->getLeft());
}

//desturctor iteratively deletes the root node
template <class T>
BST<T>::~BST() {
	while (root != nullptr) {
		deleteBST(root->getData());
	}
}

//recursively searches a tree and returns true if the key exists
template <class T>
bool BST<T>::findR(BSTNode<T>* r, T key) {
	if (r == nullptr)
		return false;
	else if (r->getData() == key)
		return true;
	else if (key > r->getData())
		return findR(r->getRight(), key);
	else
		return findR(r->getLeft(), key);
}

//returns true if the given key exists in the tree
template <class T>
bool BST<T>::isInTree(T key) {
	if (root == nullptr)
		return false;
	else {
		return findR(root, key);
	}
}
#endif
