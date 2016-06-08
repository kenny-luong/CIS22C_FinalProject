#ifndef _BST_NODE
#define _BST_NODE

template <class T>
class BSTNode {
private:
	T data; //data contained in the node
	BSTNode<T>* left; //pointer to the left node in the list
	BSTNode<T>* right; //pointer to the right node in the list
public:
	BSTNode();
	BSTNode(T);
	BSTNode(BSTNode<T>*, BSTNode<T>*);
	void setData(T);
	T getData();
	void setLeft(BSTNode<T>*);
	void setRight(BSTNode<T>*);
	BSTNode<T>* getLeft();
	BSTNode<T>* getRight();
};

//Default constructor
//left and right are set to null by default
//data will remain uninitialized value (type dependent)
template <class T>
BSTNode <T>::BSTNode() {
	left = nullptr;
	right = nullptr;
}

//Allows user to initiliaze node with data
//left and right set to null by default
template <class T>
BSTNode <T>::BSTNode(T newData) {
	data = newData;
	left = nullptr;
	right = nullptr;
}

//Allows user to initilize all attributes
template <class T>
BSTNode <T>::BSTNode(BSTNode<T>* newLeft, BSTNode<T>* newRight) {
	left = newLeft;
	right = newRight;
}

//sets the data contained within the node
template <class T>
void BSTNode <T>::setData(T newData) {
	data = newData;
}

//returns the data in the node
template <class T>
T BSTNode<T>::getData() {
	return data;
}

//sets the pointer to the left node
template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* newLeft) {
	left = newLeft;
}

//sets the pointer to the right node
template <class T>
void BSTNode<T>::setRight(BSTNode<T>* newRight) {
	right = newRight;
}

//returns the address of the left node
template <class T>
BSTNode<T>* BSTNode<T>::getLeft() {
	return left;
}

//returns the address of the right node
template <class T>
BSTNode<T>* BSTNode<T>::getRight() {
	return right;
}
#endif
