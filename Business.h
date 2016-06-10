#ifndef _BUSINESS_H
#define _BUSINESS_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Business {
private:
	std::string name;
	std::string location;
	int numRatings;
	int ratingsSum;
	int averageRating;
public:
	Business(std::string, std::string);
	Business(std::string, std::string, int, int, int);
	std::string getName() { return name; }
	std::string getLocation() { return location; }
	int getRatingsCount() { return numRatings; }
	int getRatingsSum() { return ratingsSum; }
	int getAvgRating() { return averageRating; }
	void addRating(int);
	void displayProfile();
	void writeToFile(std::ostream&);
	bool operator<(const Business&);
	bool operator>(const Business&);
	bool operator==(const Business&);
};
#endif
