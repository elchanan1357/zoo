#include "Fish.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
Fish::Fish()
	:Animal(), m_finCount(0), m_gillsCount(0) {}

//init the Fish with a given attributes
Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills)
	:Animal(color, childs, avgLifetime) {
	SetFin(fin);
	SetGills(gills);
}

//init the Fish from a binary file
Fish::Fish(ifstream& in_file)
	:Animal(in_file) {
	in_file.read((char*)&this->m_finCount, sizeof(this->m_finCount));
	in_file.read((char*)&this->m_gillsCount, sizeof(this->m_gillsCount));
}

//copy constructor
Fish::Fish(const Fish& other)
	:Animal() {
	*this = other;
}

Fish:: ~Fish() {}

//////////////////////////////get and set/////////////////////////////////////

//return the fin count of the animal
int	Fish::GetFinCount() const {
	return this->m_finCount;
}

//return the gills count of the animal
int Fish::GetGillsCount() const {
	return this->m_gillsCount;
}

void Fish::SetFin(int fin) {
	if (fin <= 0) {		//number of fin must be positive
		this->m_finCount = 0;
		return;
	}

	this->m_finCount = fin;
}

void Fish::SetGills(int gills) {
	if (gills <= 0) {//number of gills must be positive
		this->m_gillsCount = 0;
		return;
	}

	this->m_gillsCount = gills;
}

////////////////////////////// save and load /////////////////////////////////////

//read from the text file
void Fish::loadAddition(ifstream& ifs) {
	ifs >> *this;
}

//save data into the text file
void Fish::saveAddition(ofstream& ofs) {
	ofs << *this;
}

//read from the binary file
void Fish::loadAdditionBin(ifstream& ifs) {
	ifs.read((char*)&this->m_finCount, sizeof(this->m_finCount));
	ifs.read((char*)&this->m_gillsCount, sizeof(this->m_gillsCount));
}

//save data into the binary file
void Fish::saveAdditionBin(ofstream& ofs) {
	ofs.write((char*)&this->m_finCount, sizeof(this->m_finCount));
	ofs.write((char*)&this->m_gillsCount, sizeof(this->m_gillsCount));
}

////////////////////////////// operators /////////////////////////////////////

//initialize all values
const Fish& Fish::operator=(const Fish& other) {
	if (this == &other)//if equals
		return *this;

	this->SetAnimal(other.m_color, other.m_childCount, other.m_avgLifetime);
	this->SetFin(other.m_finCount);
	this->SetGills(other.m_gillsCount);
	return *this;
}

//print all value
ostream& operator<<(ostream& output, const Fish& other) {
	output << other.m_finCount << endl;
	output << other.m_gillsCount << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Fish& other) {
	input >> other.m_finCount >> other.m_gillsCount;
	return input;
}
