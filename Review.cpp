#include "Review.h"

Review::Review(Member member, Business b, std::string text, int rate) {
	author = member;
	business = b;
	body = text;
	rating = rate;
}

void Review::setAuthor(Member auth) {
	author = auth;
}

void Review::setBusiness(Business b) {
	business = b;
}

void Review::setBody(std::string text) {
	body = text;
}

void Review::setRating(int rate) {
	rating = rate;
}

Member Review::getAuthor() {
	return author;
}

Business Review::getBusiness() {
	return business;
}

std::string Review::getBody() {
	return body;
}

int Review::getRating() {
	return rating;
}
