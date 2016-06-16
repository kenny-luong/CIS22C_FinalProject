#ifndef HASH_H
#define HASH_H

#include "HashNode.h"
#include <iostream>
#include <string>
#include "Business.h"
#include "includes.h"

using namespace std;

template<class Type>
class Hash {
private:
	int SIZE;
	int collisionCount;
	HashNode<Type> *bucket;
	int longestBucket;
	int indexOfLongestBucket;
public:
	Hash() {}
	Hash(int arraySize) {
		SIZE = arraySize;
		bucket = new HashNode<Type>[SIZE];

		collisionCount = 0;
		longestBucket = 0;
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

		HashNode<Type> *temp = &bucket[index];

		if (bucket[index].data == NULL) {
			bucket[index].data = object;
			return true;
		}
		else {
			if (bucket[index].count < 3) {
				while (temp->link != NULL) {
					temp = temp->link;
				}
				temp->link = newNode;
				if (bucket[index].count > longestBucket) {
					longestBucket = bucket[index].count;
					indexOfLongestBucket = index;
				}
				bucket[index].count++;
				cout << endl << "There already exists an entry at " << index << " so " << keyValue << " was placed in a bucket." << endl << endl;
				collisionCount++;
				return true;
			}
			else {
				std::cout << "Bucket at index " << index << " is full." << std::endl;
				std::cout << keyValue << " was not added." << std::endl;
			}
		}
		return false;
	}

	int getLongestBucket() { return longestBucket;  }
	int getIndexOfLongestBucket() { return indexOfLongestBucket;  }
	int getCollisionCount() { return collisionCount;  }

	void displayList() {
		for (int i = 0; i < SIZE; i++) {
			if (bucket[i].data != NULL) {
				printCharMultiTimes('-', 30);
				cout << endl << "Index: " << i << endl;
				printCharMultiTimes('-', 30);
				cout << endl;
				bucket[i].displayBucket(&bucket[i]);
			}
		}
	}

	bool contains(string keyValue) {
		int index = hashFunction(keyValue);

		HashNode<Type> *temp = &bucket[index];

		if (bucket[index].data == NULL) {
			return false;
		}
		else {
			if (keyValue == bucket[index].data->getName()) {
				return true;
			}
			else {
				while (temp->link != NULL) {
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

		HashNode<Type> *temp = &bucket[index];
		HashNode<Type> *trail;

		if (keyValue == bucket[index].data->getName()) {
			return temp->data;
		}
		else {
			while (temp != NULL) {
				trail = temp;
				temp = temp->link;
				if (temp->keyValue == keyValue) {
					return temp->data;
				}
			}
			return nullptr; //default case, shouldn't be reached
		}
	}


	/*
	deleteObject requires that you verify the object exists already.
	*/

	bool deleteObject(string keyValue) {
		int index = hashFunction(keyValue);

		HashNode<Type> *temp = &bucket[index];
		HashNode<Type> *trail;

		if (bucket[index].data == NULL) {
			return false;
		}
		else {
			if (keyValue == bucket[index].data->getName() && bucket[index].count == 0) {
				bucket[index].data = NULL;
				return true;
			}
			else if (keyValue == bucket[index].data->getName() && bucket[index].count > 0) {
				bucket[index].data = bucket[index].link->data;
				bucket[index].link = bucket[index].link->link;
				bucket[index].count--;
			}
			else {
				while (temp != NULL) {
					trail = temp;
					temp = temp->link;
					if (temp->keyValue == keyValue) {
						trail->link = temp->link;
						delete temp;
						bucket[index].count--;
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
		return (((16 * value) + 18) % 271) % SIZE;
	}
};

#endif
