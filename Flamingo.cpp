#include "Flamingo.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
Flamingo::Flamingo()
	:Birds(), m_avgHeight(0) {}

//init the Flamingo with a given attributes
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight)
	:Birds(color, childs, avgLifetime, incubation) {
	SetHeight(avgHeight);
}

//init the Flamingo from a binary file
Flamingo::Flamingo(ifstream& in_file)
	:Birds(in_file) {
	in_file.read((char*)&this->m_avgHeight, sizeof(this->m_avgHeight));
}

////copy constructor
Flamingo::Flamingo(const Flamingo& other)
	:Birds() {
	*this = other;
}

Flamingo::~Flamingo() {}


//////////////////////////////get and set/////////////////////////////////////

//return the avg height of the flamingo
float Flamingo::GetHeight() const {
	return this->m_avgHeight;
}

void Flamingo::SetHeight(float avgHeight) {
	if (avgHeight <= 0) {//Height must be positive
		this->m_avgHeight = 0;
		return;
	}

	this->m_avgHeight = avgHeight;
}

////////////////////////////// save and load /////////////////////////////////////

//read from the text file
void Flamingo::loadAddition(ifstream& ifs) {
	Birds::loadAddition(ifs);
	ifs >> *this;
}

//save data into the text file
void Flamingo::saveAddition(ofstream& ofs) {
	Birds::saveAddition(ofs);
	ofs << *this;
}

//read from the binary file
void Flamingo::loadAdditionBin(ifstream& ifs) {
	Birds::loadAdditionBin(ifs);
	ifs.read((char*)&this->m_avgHeight, sizeof(this->m_avgHeight));
}

//save data into the binary file
void Flamingo::saveAdditionBin(ofstream& ofs) {
	Birds::saveAdditionBin(ofs);
	ofs.write((char*)&this->m_avgHeight, sizeof(this->m_avgHeight));
}

//save type of this class
void Flamingo::saveType(ofstream& ofs) {
	ofs << "F" << endl;
}

//save type of this class
void Flamingo::saveTypeBin(ofstream& ofs) {
	char type = 'F';
	ofs.write(&type, sizeof(type));
}

////////////////////////////// operators /////////////////////////////////////

//initialize all values
const Flamingo& Flamingo::operator=(const Flamingo& other) {
	if (this == &other)//if equals
		return *this;

	this->SetAnimal(other.GetColor(), other.GetChildCount(), other.GetLifetime());// of animal
	this->SetIncubation(other.m_incubationTime);//of birds
	this->SetHeight(other.m_avgHeight);//of flamingo
	return *this;
}

//print all value
ostream& operator<<(ostream& output, const Flamingo& other) {
	output << other.m_avgHeight << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Flamingo& other) {
	input >> other.m_avgHeight;
	return input;
}
