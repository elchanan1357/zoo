#include "Horse.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
Horse::Horse()
	:Animal(), Mammals(), m_type(nullptr) {}

//init the Horse with a given attributes
Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type)
	:Animal(color, childs, avgLifetime), Mammals(color, childs, avgLifetime, preg, milk), m_type(nullptr) {
	SetType(type);
}

//init the Horse from a binary file
Horse::Horse(ifstream& in_file)
	:Animal(in_file), Mammals(in_file), m_type(nullptr) {
	char buff[200];
	size_t  len;
	in_file.read((char*)&len, sizeof(len));
	in_file.read(buff, len);
	SetType(buff);
}

//copy constructor
Horse::Horse(const Horse& other)
	:Animal(), Mammals(), m_type(nullptr) {
	*this = other;
}

Horse::~Horse() {
	if (!this->m_type) //== NULL
		return;

	delete[] this->m_type;
	this->m_type = nullptr;
}

//////////////////////////////get and set/////////////////////////////////////

//return the type of the horse
const char* Horse::GetType() const {
	return this->m_type;
}

void  Horse::SetType(const char* type) {
	if (this->m_type) {//!=NULL
		delete[] this->m_type;
		this->m_type = nullptr;
	}

	if (!type) {//==NULL
		this->m_type = nullptr;
		return;
	}

	this->m_type = strdup(type);
}

////////////////////////////// save and load /////////////////////////////////////

//read from the text file
void  Horse::loadAddition(ifstream& ifs) {
	Mammals::loadAddition(ifs);//call to father
	ifs >> *this;
}

//save data into the text file
void  Horse::saveAddition(ofstream& ofs) {
	Mammals::saveAddition(ofs);
	ofs << *this;
}

//read from the binary file
void  Horse::loadAdditionBin(ifstream& ifs) {
	Mammals::loadAdditionBin(ifs);
	char buff[200];
	size_t  len;
	ifs.read((char*)&len, sizeof(len));
	ifs.read(buff, len);
	SetType(buff);
}

//save data into the binary file
void  Horse::saveAdditionBin(ofstream& ofs) {
	Mammals::saveAdditionBin(ofs);
	size_t len = strlen(this->m_type) + 1;
	ofs.write((char*)&len, sizeof(len));
	ofs.write(this->m_type, len);
}

//save type of this class
void  Horse::saveType(ofstream& ofs) {
	ofs << "H" << endl;
}

//save type of this class
void  Horse::saveTypeBin(ofstream& ofs) {
	char type = 'H';
	ofs.write(&type, sizeof(type));
}

////////////////////////////// operators /////////////////////////////////////

//initialize all values
const Horse& Horse::operator=(const Horse& other) {
	if (this == &other)
		return *this;

	this->SetAnimal(other.GetColor(), other.GetChildCount(), other.GetLifetime());//of animal
	this->SetMilk(other.m_milkLiters);//of mammal
	this->SetPregnance(other.m_pregnancyTime);//of mammal
	this->SetType(other.m_type);//of horse
}

//print all value
ostream& operator<<(ostream& output, const Horse& other) {
	output << other.m_type << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Horse& other) {
	char buff[200];
	input.read(buff, 1);//read endl
	input.getline(buff, 200);
	other.SetType(buff);
	return input;
}
