#include "GoldFish.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
GoldFish::GoldFish()
	:Animal(), MammalsFish(), m_avgWeight(0), m_avgLength(0) {}

//init the GoldFish with a given attributes
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL)
	:Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills) {
	SetWeight(avgW);
	SetLength(avgL);
}

//init the GoldFish from a binary file
GoldFish::GoldFish(ifstream& in_file)
	:Animal(in_file), MammalsFish(in_file) {
	in_file.read((char*)&this->m_avgWeight, sizeof(this->m_avgWeight));
	in_file.read((char*)&this->m_avgLength, sizeof(this->m_avgLength));
}

//copy constructor
GoldFish::GoldFish(const GoldFish& other)
	:Animal(), MammalsFish() {
	*this = other;
}

GoldFish::~GoldFish() {}

//////////////////////////////get and set/////////////////////////////////////

//return the avg weight of the gold fish
float GoldFish::GetWeight() const {
	return this->m_avgWeight;
}

//return the avg length of the gold fish
float GoldFish::GetLength() const {
	return this->m_avgLength;
}

void GoldFish::SetWeight(float avgW) {
	if (avgW <= 0) {//number of weight must be positive
		this->m_avgWeight = 0;
		return;
	}

	this->m_avgWeight = avgW;
}

void GoldFish::SetLength(float avgL) {
	if (avgL <= 0) {//number of length must be positive
		this->m_avgLength = 0;
		return;
	}

	this->m_avgLength = avgL;
}

////////////////////////////// save and load /////////////////////////////////////

//read from the text file
void GoldFish::loadAddition(ifstream& ifs) {
	MammalsFish::loadAddition(ifs);//call to father
	ifs >> *this;
}

//save data into the text file
void GoldFish::saveAddition(ofstream& ofs) {
	MammalsFish::saveAddition(ofs);//call to father
	ofs << *this;
}

//save type of this class
void GoldFish::saveType(ofstream& ofs) {
	ofs << "G" << endl;
}

//read from the binary file
void GoldFish::loadAdditionBin(ifstream& ifs) {
	MammalsFish::loadAdditionBin(ifs);//call to father
	ifs.read((char*)&this->m_avgWeight, sizeof(this->m_avgWeight));
	ifs.read((char*)&this->m_avgLength, sizeof(this->m_avgLength));
}

//save data into the binary file
void GoldFish::saveAdditionBin(ofstream& ofs) {
	MammalsFish::saveAdditionBin(ofs);//call to father
	ofs.write((char*)&this->m_avgWeight, sizeof(this->m_avgWeight));
	ofs.write((char*)&this->m_avgLength, sizeof(this->m_avgLength));
}

//save type of this class
void GoldFish::saveTypeBin(ofstream& ofs) {
	char type = 'G';
	ofs.write(&type, sizeof(type));
}

////////////////////////////// operators /////////////////////////////////////

//initialize all values
const GoldFish& GoldFish::operator=(const GoldFish& other) {
	if (this == &other)//if equals
		return *this;

	this->SetAnimal(other.m_color, other.m_childCount, other.m_avgLifetime);//of animal
	this->SetMilk(other.m_milkLiters);//of mammal
	this->SetPregnance(other.m_pregnancyTime);//of mammal
	this->SetFin(other.m_finCount);//of fish 
	this->SetGills(other.m_gillsCount);//of fish
	this->SetWeight(other.m_avgWeight);//of gold fish
	this->SetLength(other.m_avgLength);//of gold fish
	return *this;
}

//print all value
ostream& operator<<(ostream& output, const GoldFish& other) {
	output << other.m_avgWeight << endl;
	output << other.m_avgLength << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, GoldFish& other) {
	input >> other.m_avgWeight >> other.m_avgLength;
	return input;
}
