#include "Animal.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
Animal::Animal()
	:m_color(nullptr), m_avgLifetime(0), m_childCount(0) {}

//init the Animal with a given attributes
Animal::Animal(const char* color, int childs, float avgLifetime)
	:m_color(nullptr) {
	SetColor(color);
	SetChildren(childs);
	SetLifeTime(avgLifetime);
}

//init the Animal from a binary file
Animal::Animal(ifstream& in_file)
	:m_color(nullptr) {
	char buff[200];
	size_t len;
	in_file.read((char*)&len, sizeof(len));
	in_file.read(buff, len);
	SetColor(buff);
	in_file.read((char*)&this->m_childCount, sizeof(this->m_childCount));
	in_file.read((char*)&this->m_avgLifetime, sizeof(this->m_avgLifetime));
}

Animal::Animal(const Animal& newAnimal)
	:m_color(nullptr) {
	*this = newAnimal;
}

//dis - constructor delete all values
Animal::~Animal() {
	if (!this->m_color)//==NULL
		return;

	delete[] this->m_color;
	this->m_color = nullptr;
}

//////////////////////////////get and set/////////////////////////////////////


//return the color of the animal
const char* Animal::GetColor() const {
	return this->m_color;
}

//return the child count of the animal
int	Animal::GetChildCount() const {
	return this->m_childCount;
}

//return the life time of the animal
float Animal::GetLifetime() const {
	return this->m_avgLifetime;
}

//setting the color
void Animal::SetColor(const char* color) {
	if (this->m_color) {//!=NULL
		delete[] this->m_color;
		this->m_color = nullptr;
	}

	if (!color) {//==NULL
		this->m_color = nullptr;
		return;
	}

	this->m_color = strdup(color);
}

//setting the number of children
void Animal::SetChildren(const int& count) {
	if (count <= 0) //number of children must be positive 
		this->m_childCount = 0;
	else
		this->m_childCount = count;
}

//setting the average life time
void Animal::SetLifeTime(const float& average) {

	if (average <= 0)//number of life time must be positive
		this->m_avgLifetime = 0;
	else
		this->m_avgLifetime = average;
}

//Settings all values of animal
void  Animal::SetAnimal(const char* color, int childs, float avgLifetime) {
	SetColor(color);
	SetChildren(childs);
	SetLifeTime(avgLifetime);
}

////////////////////////////// save and load /////////////////////////////////////

//read from the text file
void Animal::load(ifstream& ifs) {
	ifs >> *this;
	loadAddition(ifs);
}

//save data into the text file
void Animal::save(ofstream& ofs) {
	saveType(ofs);
	ofs << *this;
	saveAddition(ofs);
}

////save data into the binary file
void Animal::saveBin(ofstream& ofs) {
	saveTypeBin(ofs);
	size_t len = strlen(this->m_color) + 1;
	ofs.write((char*)&len, sizeof(len));
	ofs.write(this->m_color, len);
	ofs.write((char*)&this->m_childCount, sizeof(this->m_childCount));
	ofs.write((char*)&this->m_avgLifetime, sizeof(this->m_avgLifetime));
	saveAdditionBin(ofs);
}

//read from the binary file
void Animal::loadBin(ifstream& ifs) {
	size_t len;
	ifs.read((char*)&len, sizeof(len));
	char buff[200];
	ifs.read(buff, len);
	SetColor(buff);
	ifs.read((char*)&this->m_childCount, sizeof(this->m_childCount));
	ifs.read((char*)&this->m_avgLifetime, sizeof(this->m_avgLifetime));
	loadAdditionBin(ifs);
}

////////////////////////////// operators /////////////////////////////////////

//initialize all values 
const Animal& Animal::operator=(const Animal& other) {
	if (this == &other)//if equals
		return *this;

	this->SetAnimal(other.m_color, other.m_childCount, other.m_avgLifetime);
	return *this;
}

//print all value
ostream& operator<<(ostream& output, const Animal& other) {
	output << other.m_color << endl;
	output << other.m_childCount << endl;
	output << other.m_avgLifetime << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Animal& other) {
	char buff[200];
	input >> buff;
	other.SetColor(buff);
	input >> other.m_childCount;
	input >> other.m_avgLifetime;
	return input;
}





