#ifndef _BST
#define _BST
#include "BSTNode.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "includes.h"
#include "Queue.cpp"

template <class T>
class BST {
private:
	BSTNode<T>* root;
	BSTNode<T>* insertR(BSTNode<T>*, BSTNode<T>*);
	BSTNode<T>* removeNode(BSTNode<T>*, std::string, BSTNode<T>*);
	void printR(BSTNode<T>*, int, std::ostream&);
	BSTNode<T>* getMin(BSTNode<T>*);
	bool findR(BSTNode<T>*, std::string);
public:
	BST();
	~BST();
	void insertBST(T, std::string);
	void printIndentedTree(std::ostream&);
	void writeToFile(std::ostream&);
	void inorder(BSTNode<T> *root);
	bool deleteBST(std::string);
	bool isInTree(std::string);
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
		if (data->getKey() < r->getKey()) { //insert as left child
			leftPtr = insertR(leftPtr, data);
			r->setLeft(leftPtr);
		}
		else { //insert as right child
			rightPtr = insertR(rightPtr, data);
			r->setRight(rightPtr);
		}
		return r;
	}
}

//public insert method
//calls recursive insert method
template <class T>
void BST<T>::insertBST(T data, std::string key) {
	BSTNode<T>* n = new BSTNode<T>(data, key);
	root = insertR(root, n);
}

//prints the tree in an indented format
template <class T>
void BST<T>::printR(BSTNode<T>* r, int indent, std::ostream& output) {
	if (r != nullptr) {
		if (indent)
			output << std::setw(indent) << " ";
		output << r->getKey() << "\n";
		if (r->getLeft() != nullptr)
			printR(r->getLeft(), indent + 2, output);
		if (r->getRight() != nullptr)
			printR(r->getRight(), indent + 2, output);
	}
}

template<class Type>
void BST<Type>::inorder(BSTNode<Type> *root) {
	if (root != NULL) {
		inorder(root->getLeft());
		printCharMultiTimes('-', 30);
		std::cout << std::endl;
		std::cout << root->getData();
		printCharMultiTimes('-', 30);
		inorder(root->getRight());
	}
}

//calls the recursive print method
template <class T>
void BST<T>::printIndentedTree(std::ostream& output) {
	printR(root, 0, output);
}

//deletes the node containing the given key if it exists
template <class T>
bool BST<T>::deleteBST(std::string key) {
	if (root == nullptr) //empty tree
		return false;
	else {
		if (root->getKey() == key) { //root contains key
			BSTNode<T> temp(nullptr, nullptr);
			temp.setLeft(root);
			BSTNode<T>* removedNode = removeNode(root, key, &temp);
			root = temp.getLeft();
			if (removedNode != nullptr) {
				delete removedNode;
				return true;
			}
			else
				return false;
		}
		else { //search thre rest of the tree for the key
			BSTNode<T>* removedNode = removeNode(root, key, nullptr);
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
BSTNode<T>* BST<T>::removeNode(BSTNode<T>* r, std::string key, BSTNode<T>* parent) {
	if (key < r->getKey()) { //move down to the left subtree if it exists
		if (r->getLeft() != nullptr)
			return removeNode(r->getLeft(), key, r);
		else
			return nullptr;
	}
	else if (key > r->getKey()) { //move down to the right subtree if it exists
		if (r->getRight() != nullptr)
			return removeNode(r->getRight(), key, r);
		else
			return nullptr;
	}
	else { //found the node to be deleted
		if (r->getLeft() != nullptr && r->getRight() != nullptr) { //node is not a leaf
			BSTNode<T>* minNode = getMin(r->getRight());
			r->setData(minNode->getData());
			r->setKey(minNode->getKey());
			return removeNode(r->getRight(), r->getKey(), r);
		}
		else if (parent->getLeft() == r) { //node is left child of a 2-node
			parent->setLeft((r->getLeft() != nullptr) ? r->getLeft() : r->getRight());
			return r;
		}
		else if (parent->getRight() == r) { //node is right child of a 2-node
			parent->setRight((r->getLeft() != nullptr) ? r->getLeft() : r->getRight());
			return r;
		}
		else { //default case, just here for safety, shouldn't ever be reached
			return nullptr;
		}
	}
}

//returns a pointer to the node containing the minimum key of a given tree
template <class T>
BSTNode<T>* BST<T>::getMin(BSTNode<T>* node) {
	if (node->getLeft() == nullptr)
		return node;
	else
		return getMin(node->getLeft());
}

//desturctor iteratively deletes the root node
template <class T>
BST<T>::~BST() {
	while (root != nullptr) {
		deleteBST(root->getKey());
	}
}

//recursively searches a tree and returns true if the key exists
template <class T>
bool BST<T>::findR(BSTNode<T>* r, std::string key) {
	if (r == nullptr)
		return false;
	else if (r->getKey() == key)
		return true;
	else if (key > r->getKey())
		return findR(r->getRight(), key);
	else
		return findR(r->getLeft(), key);
}

//returns true if the given key exists in the tree
template <class T>
bool BST<T>::isInTree(std::string key) {
	if (root == nullptr)
		return false;
	else {
		return findR(root, key);
	}
}

template <class T>
void BST<T>::writeToFile(std::ostream& output) {
	Queue<BSTNode<T>*> q;
	if (root == nullptr)
		return;
	q.enque(root);
	BSTNode<T>* temp = nullptr;
	while (!q.isEmpty()) {
		temp = q.deque();
		output << temp->getData()->getName() << "\n";
		output << temp->getData()->getLocation() << "\n";
		output << temp->getData()->getRatingsCount() << "\n";
		output << temp->getData()->getRatingsSum() << "\n";
		if (temp->getLeft() != nullptr)
			q.enque(temp->getLeft());
		if (temp->getRight() != nullptr)
			q.enque(temp->getRight());
	}
}
#endif
