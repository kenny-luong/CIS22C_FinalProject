#ifndef _BUSINESS_H
#define _BUSINESS_H
#include <string>
#include "BusinessOwner.h"
#include "ReviewContainer.h"

class Business {
private:
	std::string name;
	std::string description;
	BusinessOwner owner;
	ReviewContainer reviews;
	int averageRating;
public:
	Business();
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	BusinessOwner getBusinessOwner() { return owner; }
	ReviewContainer getReviews() { return reviews; }
	int getAverageRating() { return averageRating; }
	void setName(std::string);
	void setDescription(std::string);
	void setOwner(BusinessOwner&);
	void setReviews(ReviewContainer&);
	void setAverageRating(int);
	void displayProfile();
	void displayReviews();
};
#endif
