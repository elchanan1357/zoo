#include "Birds.h"

////////////////////constructors and dis - constructors//////////////////////////

//set the default color to GRAY and other params to 0
Birds::Birds()
	:Animal(), m_incubationTime(0) {}

//init the Birds with a given attributes
Birds::Birds(const char* color, int childs, float avgLifetime, float incubation)
	:Animal(color, childs, avgLifetime) {
	SetIncubation(incubation);
}

//init the Birds from a binary file
Birds::Birds(ifstream& in_file)
	:Animal(in_file) {
	in_file.read((char*)&this->m_incubationTime, sizeof(this->m_incubationTime));
}

Birds:: ~Birds() {}

//copy c'tor
Birds::Birds(const Birds& other)
	:Animal() {
	*this = other;
}

//////////////////////Get and set//////////////////////////

//return the incubation time of the animal
float Birds::GetIncubationTime() const {
	return this->m_incubationTime;
}

//Setting incubation time
void Birds::SetIncubation(float incubation) {
	if (incubation <= 0) {//incubation must be positive
		this->m_incubationTime = 0;
		return;
	}

	this->m_incubationTime = incubation;
}

////////////////////load and save//////////////////////////

//read from the text file
void Birds::loadAddition(ifstream& ifs) {
	ifs >> *this;
}

//save data into the text file
void Birds::saveAddition(ofstream& ofs) {
	ofs << *this;
}

//read from the binary file
void Birds::loadAdditionBin(ifstream& ifs) {
	ifs.read((char*)&this->m_incubationTime, sizeof(this->m_incubationTime));
}

//save data into the binary file
void Birds::saveAdditionBin(ofstream& ofs) {
	ofs.write((char*)&this->m_incubationTime, sizeof(this->m_incubationTime));
}

////////////////////operators//////////////////////////

//initialize all values
const Birds& Birds::operator=(const Birds& other) {
	if (this == &other)//if equals
		return *this;

	this->SetAnimal(other.GetColor(), other.GetChildCount(), other.GetLifetime());
	this->SetIncubation(other.m_incubationTime);
	return *this;
}

//print all value
ostream& operator<<(ostream& output, const Birds& other) {
	output << other.m_incubationTime << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Birds& other) {
	input >> other.m_incubationTime;
	return input;
}




