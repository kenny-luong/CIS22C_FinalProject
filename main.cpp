#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "hash.h"
#include "BST.cpp"
#include "Business.h"
#include "includes.h"

using namespace std;

int selectMainMenu();

template<class Type>
bool LoadBusinesses(BST<Type> &tree, Hash<Type> &hash) {
	ifstream businessData;
	headNode.count = 0;
	try {
		businessData.open("businesses.txt");
		if (!businessData.is_open()) {
			throw 1;
		}
	}
	catch (int x) {
		cout << "Error opening file.";
		system("pause");
		return 0;
	}

	string tempName;
	string tempAddress;
	string numOfRatingsString;
	string sumOfRatingsString;
	int numOfRatings;
	int sumOfRatings;
	Business *tempBusiness;
	while (getline(businessData, tempName)) {
		getline(businessData, tempAddress);
		getline(businessData, numOfRatingsString);
		numOfRatings = stoi(numOfRatingsString);
		getline(businessData, sumOfRatingsString);
		sumOfRatings = stoi(sumOfRatingsString);
		tempBusiness = new Business(tempName, tempAddress, numOfRatings, sumOfRatings);
		tree.insertBST(tempBusiness, tempName);
		hash.add(tempName, tempBusiness);
		headNode.count++;
	}

	businessData.close();
	return 1;
}

struct headNodeStruct {
	int count, arySize;
	BST<Business*>* pTree;
	Hash<Business*>* pHash;
} headNode;

int main() {
	BST<Business*> tree;
	Hash<Business*> hash;
	headNode.pTree = &tree;
	headNode.pHash = &hash;
	if (!LoadBusinesses(tree, hash))
		return 0;
	ofstream dataFile;
	
	while (true) {
		int mainMenu = selectMainMenu();
		cin.ignore();
		system("CLS");
		switch (mainMenu) {
		case 1: {
			string name;
			string address;
			cout << "Add a new business" << endl << endl;
			cout << "Enter the name of the business: ";
			getline(cin, name);
			cout << "Enter the address of the business: ";
			getline(cin, address);
			Business *newBusiness = new Business(name, address);
			tree.insertBST(newBusiness, name);
			hash.add(name, newBusiness);
			headNode.count++;
			dataFile.open("businesses.txt");
			tree.writeToFile(dataFile);
			dataFile.close();
			break;
		}
		case 2: {
			string name;
			cout << "Delete a business " << endl << endl;
			cout << "Enter the name of the business:";
			getline(cin, name);
			if (tree.isInTree(name)) {
				char deleteYesOrNo;
				cout << name << " was found!" << endl;
				cout << "Would you like to delete this? (Y/N): ";
				cin >> deleteYesOrNo;
				if (deleteYesOrNo == 'Y' || deleteYesOrNo == 'y') {
					if (hash.deleteObject(name)) {
						cout << "This worked" << endl;
					}
					if (tree.deleteBST(name)) {
						cout << "so did this..." << endl;
					}
					headNode.count--;
					dataFile.open("businesses.txt");
					tree.writeToFile(dataFile);
					dataFile.close();
				}
			}
			else {
				cout << "We could not find this business in our database." << endl;
				system("PAUSE");
			}
			break;
		}
		case 3: {
			string name;
			cout << "Search for a business" << endl << endl;
			cout << "Enter business name: ";
			getline(cin, name);
			if (tree.isInTree(name)) {
				cout << endl << endl << "Listing business details" << endl;
				printCharMultiTimes('-', 30);
				cout << endl << endl;
				cout << hash.getBusiness(name);
			}
			else {
				cout << "Business not found!" << endl;
			}
			system("PAUSE");
			break;
		}
		case 4: {
			cout << "Listing all data (hash)..." << endl << endl;
			printCharMultiTimes('-', 30);
			cout << endl;
			hash.displayList();
			system("PAUSE");
			break;
		}
		case 5: {
			cout << "Listing all data (inorder)..." << endl << endl;
			printCharMultiTimes('-', 30);
			cout << endl;
			tree.inorder(tree.getRoot());
			system("PAUSE");
			break;
		}
		case 8: {
			string name;
			int rating;
			cout << "Enter the name of the business you want to rate: ";
			getline(cin, name);
			if (tree.isInTree(name)) {
				cout << name << " was found!" << endl;
				cout << "What would you like to rate " << name << "?" << endl;
				cout << "[ 1 2 3 4 5 ]" << endl;
				cin >> rating;
				hash.getBusiness(name)->addRating(rating);
				dataFile.open("businesses.txt");
				tree.writeToFile(dataFile);
				dataFile.close();
				cout << hash.getBusiness(name);
				system("PAUSE");
			}
			else {
				cout << "That business could not be found" << endl;
				system("PAUSE");
			}
			break;
		}
		case 9: {
			return 0;
		}
		}
	}
}

int selectMainMenu() {
	system("CLS");
	int choice;
	cout << "Main Menu" << endl;
	cout << "1. Add a new business" << endl;
	cout << "2. Delete a business" << endl;
	cout << "3. Find a business" << endl;
	cout << "4. List businesses (hash)" << endl;
	cout << "5. List businesses (sorted)" << endl;
	cout << "6. Print indented tree" << endl;
	cout << "7. Efficiency" << endl;
	cout << "8. Team choice (Enter a rating)" << endl;
	cout << "9. Quit" << endl << endl << endl;
	cout << "Enter choice: ";
	cin >> choice;
	return choice;
}
