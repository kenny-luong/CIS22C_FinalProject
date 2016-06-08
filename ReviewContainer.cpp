#include "ReviewContainer.h"

/*
Pushes Review object into vector
@params Review object
*/
void ReviewContainer::add(Review review) {
	reviews.push_back(review);
	count++;
}

/*
If the count is greater than 0, will remove object at designated index
@params integer signifying the index of the object to be removed
*/
void ReviewContainer::deleteReview(int index) {
	if (count > 0) {
		reviews.erase(reviews.begin()+index);
		count--;
	}
}

//TODO: finish logic to display reviews
void ReviewContainer::displayReviews() {
	for (int i = 0; i < reviews.size(); i++) {
		//stuff
	}
}

//Allows subscript access to the container
//@params integer index of the object to be returned
Review& ReviewContainer::operator[](int index) {
	return reviews[index];
}
