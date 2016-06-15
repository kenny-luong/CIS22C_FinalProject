#ifndef _QUEUE
#define _QUEUE
#include "LinkedList.cpp"

template <class T>
class Queue : public LinkedList<T> {
public:
	Queue() {}; //use LinkedList's default constructor
	void enque(T);
	T deque();
	bool isEmpty();
	int count();
	void clear();
	void printQueue();
};

//Uses LinkedList's pushBack to place the node at the rear of the queue
template <class T>
void Queue<T>::enque(T data) {
	insertAt(data, getLength());
}

//Uses LinkedList's popFront to remove the front node and return its data value
//If the queue is already empty, an error message will be displayed
template <class T>
T Queue<T>::deque() {
	T ans = getRoot()->getData();
	deleteAt(0);
	return ans;
}


//Returns true if the queue is empty, else returns false
template <class T>
bool Queue<T>::isEmpty() {
	return (getLength() == 0);
}

//Returns the number of nodes in the queue, excluding the head node
template <class T>
int Queue<T>::count() {
	return getLength();
}

//Clears the queue by iteratively dequeueing
template <class T>
void Queue<T>::clear() {
	int len = getLength();
	for (int i = 0; i < len; i++) {
		popFront();
	}
}

//Prints the contents of the queue and displays which end is the front and which is the rear
//Does not modify the contents of the queue
//If the queue is empty, an appropriate message is printed instead
template <class T>
void Queue<T>::printQueue() {
	if (getLength() > 0) {
		std::cout << "Front of queue" << endl;
		printList();
		std::cout << "Rear of queue" << endl;
	}
	else {
		std::cout << "Queue is empty" << endl;
	}
}
#endif
