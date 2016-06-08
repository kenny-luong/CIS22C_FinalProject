#ifndef _REVIEW_H
#define _REVIEW_H
#include "Business.h"
#include "Member.h"
class Review {
private:
	Member author;
	Business business;
	std::string body;
	int rating;
public:
	Review(Member, Business, std::string, int);
	void setAuthor(Member);
	void setBusiness(Business);
	void setBody(std::string);
	void setRating(int);
	Member getAuthor();
	Business getBusiness();
	std::string getBody();
	int getRating();
};
#endif
