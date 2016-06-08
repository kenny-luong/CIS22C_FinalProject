#ifndef REVIEW_CONTAINER_H
#define REVIEW_CONTAINER_H

#include <vector>
#include "Review.h"

class ReviewContainer {
private:
	std::vector<Review> reviews;
	int count;
public:
	ReviewContainer();
	void add(Review);
	void deleteReview(int);
	void displayReviews();
	Review& operator[](int);
};
#endif
