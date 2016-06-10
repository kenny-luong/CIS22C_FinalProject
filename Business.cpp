#include "Business.h"

Business::Business() {
	name = "";
	description = "";
	averageRating = 0;
}

void Business::setName(std::string n) {
	name = n;
}

void Business::setDescription(std::string d) {
	description = d;
}
void Business::setOwner(BusinessOwner& o) {
	owner = o;
}

void Business::setReviews(ReviewContainer& rc) {
	reviews = rc;
}

void Business::setAverageRating(int a) {
	averageRating = a;
}

void Business::displayProfile() {
	//TODO
}

void Business::displayReviews() {
	//TODO
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
