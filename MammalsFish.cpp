#include "MammalsFish.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
MammalsFish::MammalsFish()
	:Animal(), Mammals(), Fish() {}

//init the MammalsFish with a given attributes
MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
	:Animal(color, childs, avgLifetime),
	Mammals(color, childs, avgLifetime, preg, milk),
	Fish(color, childs, avgLifetime, fin, gills) {}

//init the MammalsFish from a binary file
MammalsFish::MammalsFish(ifstream& in_file)
	:Animal(in_file), Mammals(in_file), Fish(in_file) {}

//copy constructor
MammalsFish::MammalsFish(const MammalsFish& other)
	:Animal(other), Mammals(other), Fish(other) {}

MammalsFish:: ~MammalsFish() {}

////////////////////////////// load and save /////////////////////////////////////

//read from the text file (animal)
void MammalsFish::loadAddition(ifstream& ifs) {
	Mammals::loadAddition(ifs);
	Fish::loadAddition(ifs);
}

//save data into the text file (animal)
void MammalsFish::saveAddition(ofstream& ofs) {
	Mammals::saveAddition(ofs);
	Fish::saveAddition(ofs);
}

//read from the binary file (animal)
void MammalsFish::loadAdditionBin(ifstream& ifs) {
	Mammals::loadAdditionBin(ifs);
	Fish::loadAdditionBin(ifs);
}

//save data into the binary file (animal)
void MammalsFish::saveAdditionBin(ofstream& ofs) {
	Mammals::saveAdditionBin(ofs);
	Fish::saveAdditionBin(ofs);
}