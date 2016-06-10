#include "Business.h"

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

Business::Business(std::string n, std::string l, int nR, int rS, int aR) {
	name = n;
	location = l;
	numRatings = nR;
	ratingsSum = rS;
	averageRating = aR;
}

void Business::addRating(int rating) {
	numRatings++;
	ratingsSum += rating;
	averageRating = ratingsSum / numRatings;
}

void Business::displayProfile() {
	std::cout << name << std::endl;
	std::cout << location << std::endl;
	std::cout << "Average rating: " << averageRating << std::endl;
	std::cout << "Number of ratings submitted: " << numRatings << std::endl;
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
