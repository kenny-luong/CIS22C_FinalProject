#define _CRT_SECURE_NO_WARNINGS

#include "Business.h"
#include <iomanip>

Business::Business() {}

/*
	Gargabe constructor used just for testing purposes.
	TODO: Remove this when done testing.
*/

Business::Business(std::string name) {
	this->name = name;
}

Business::Business(std::string n, std::string l) {
	name = n;
	location = l;
	numRatings = 0;
	ratingsSum = 0;
	averageRating = 0;
}

Business::Business(std::string n, std::string l, int nR, int rS) {
	name = n;
	location = l;
	numRatings = nR;
	ratingsSum = rS;
	setAverageRating(rS, nR);
}

void Business::setName(std::string name) {
	this->name = name;
}

void Business::addRating(int rating) {
	std::cout << "Rating: " << rating << std::endl;
	this->numRatings++;
	this->ratingsSum += rating;
	setAverageRating(this->ratingsSum, this->numRatings);
}

void Business::setAverageRating(int ratingsSum, int numRatings) {
	this->averageRating = static_cast<double>(ratingsSum) / numRatings;
}



void Business::writeToFile(std::ostream& output) {
	output << name << "\n";
	output << location << "\n";
	output << numRatings << "\n";
	output << ratingsSum << "\n";
	output << averageRating << "\n";
}

bool Business::operator<(const Business& b) {
	return (name < b.name);
}

bool Business::operator>(const Business& b) {
	return (name > b.name);
}

bool Business::operator==(const Business& b) {
	return name == b.name;
}

std::ostream& operator<<(std::ostream& os, const Business &b) {
	os << "Name: " << b.name << std::endl;
	os << "Address: " << b.location << std::endl;
	os << std::setprecision(2);
	os << "Average rating: " << b.averageRating << std::endl;
	os << "Number of ratings submitted: " << b.numRatings << std::endl;
	return os;
}
