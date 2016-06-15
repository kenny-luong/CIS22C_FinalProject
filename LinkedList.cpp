#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "BSTNode.cpp"
#include <iostream>
#include <string>

template <class T>
class LinkedList{
private:
	BSTNode<T>* root; //address of the first node in the list
	int length;
public: //these are protected so that inherited classes only use methods useful to the class
	LinkedList();
	~LinkedList();
	BSTNode<T>* getRoot() { return root; }
	void insertAt(T, int);
	void deleteAt(int);
	void printList();
	int find(T);
	int getLength() { return length; }
};

//Default constructor
//length is set to zero
//root pointer set to null
template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	root = nullptr;
}

//default destructor
//iteratively deletes the first node until empty
template <class T>
LinkedList<T>::~LinkedList() {
	while (length > 0) {
		deleteAt(0);
	}
}

//Print the data contained in all nodes in the list
//If the list is empty, a proper message is shown
template <class T>
void LinkedList<T>::printList() {
	if (length != 0) {
		BSTNode<T>* nextNode = root;
		while (nextNode != nullptr) {
			std::cout << nextNode->getData() << endl;
			nextNode = nextNode->getRight();
		}
	}
	else {
		std::cout << "List is empty" << endl;
		return;
	}
}

//Insert a node anywhere in the list
//indexes start at 0
template <class T>
void LinkedList<T>::insertAt(T data, int index) {
	if (index<0 || index>length) { //index is outside of valid range
		std::cout << "Invalid index" << std::endl;
		return;
	}
	BSTNode<T>* n = new BSTNode<T>(data);
	if (index == 0) { //beginning of list
		if (root == nullptr) {
			root = n;
			n->setRight(nullptr);
		}
		else {
			n->setRight(root->getRight());
			root = n;
		}
		length++;
	}
	else if (index == length) { //end of list
		if (root == nullptr) {
			root = n;
			n->setRight(nullptr);
		}
		else {
			BSTNode<T>* end = root;
			while (end->getRight() != nullptr) {
				end = end->getRight();
			}
			end->setRight(n);
			n->setRight(nullptr);
		}
		length++;
	}
	else { //in between nodes
		BSTNode<T>* curr=root;
		for (int i = 0; i < index-1; i++) { //find the node before that index
			curr = curr->getRight();
		}
		n->setRight(curr->getRight());
		curr->setRight(n);
		length++;
	}
}

//Delete a node at a specific index
template <class T>
void LinkedList<T>::deleteAt(int index) {
	if (index < 0 || index >= length) { //index is not valid
		std::cout << "Invalid index" << std::endl;
		return;
	}
	else if (root == nullptr) {
		std::cout << "List is already empty" << std::endl;
		return;
	}
	BSTNode<T>* deleteMe;
	if (index == 0) { //delete the first node
			deleteMe = root;
			root = deleteMe->getRight();
			delete deleteMe;
			length--;
	}
	else if (index == length-1) { //delete the last node	
		BSTNode<T>* curr = root;
		for (int i = 0; i < length - 2; i++) {
			curr = curr->getRight();
		}
		deleteMe = curr->getRight();
		curr->setRight(nullptr);
		delete deleteMe;
		length--;
	}
	else {
		deleteMe = root;
		for (int i = 0; i < index; i++) { //find the desired node to be deleted
			deleteMe = deleteMe->getRight();
		}
		BSTNode<T>* before = root;
		while (before->getRight() != deleteMe) { //find the node before the one to be deleted
			before = before->getRight();
		}
		before->setRight(deleteMe->getRight());
		delete deleteMe;
		length--;
	}
}

//Returns the index of the node containing the inputted data
//If no nodes contain the data, -1 will be returned
template <class T>
int LinkedList<T>::find(T data) {
	BSTNode<T>* currentAtIndex = root;
	for (int i = 0; i < length; i++) {
		if (currentAtIndex->getData() == data) {
			return i;
		}
		currentAtIndex = currentAtIndex->getRight();
	}
	return -1;
}
#endif
