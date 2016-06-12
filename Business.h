#ifndef _BUSINESS_H
#define _BUSINESS_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

class Business {
private:
	std::string name;
	std::string location;
	int numRatings;
	int ratingsSum;
	double averageRating;
public:
	Business();
	Business(std::string); // Garbage contructor used just for testing file saving / loading
	Business(std::string, std::string);
	Business(std::string, std::string, int, int);
	void setName(std::string);
	std::string getName() { return name; }
	std::string getLocation() { return location; }
	int getRatingsCount() { return numRatings; }
	int getRatingsSum() { return ratingsSum; }
	int getAvgRating() { return averageRating; }
	void addRating(int);
	void setAverageRating(int, int);
	void displayProfile();
	void writeToFile(std::ostream&);
	bool operator<(const Business&);
	bool operator>(const Business&);
	bool operator==(const Business&);
	friend std::ostream& operator<<(std::ostream&, const Business&);
};
#endif
