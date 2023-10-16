#include "Mermaid.h"
//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//set the default color to GRAY and other params to 0
Mermaid::Mermaid()
	:Animal(), MammalsFish(), m_firstName(nullptr), m_lastName(nullptr) {}

//init the Mermaid with a given attributes
Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)
	:Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), m_firstName(nullptr), m_lastName(nullptr) {
	SetFirstName(firstName);
	SetLastName(lastName);
}

//init the Mermaid from a binary file
Mermaid::Mermaid(ifstream& in_file)
	:Animal(in_file), MammalsFish(in_file), m_firstName(nullptr), m_lastName(nullptr) {
	size_t  len;
	in_file.read((char*)&len, sizeof(len));//read size

	char buff1[200], buff2[200];
	in_file.read(buff1, len);//read first name from file
	this->SetFirstName(buff1);//initialize into this -> first name

	in_file.read((char*)&len, sizeof(len));//read size
	in_file.read(buff2, len);//read second name from file
	this->SetLastName(buff2);//initialize into this -> second name
}

//copy constructor
Mermaid::Mermaid(const Mermaid& other)
	:Animal(), MammalsFish(), m_firstName(nullptr), m_lastName(nullptr) {
	*this = other;
}

Mermaid:: ~Mermaid() {
	if (this->m_firstName) {// != NULL
		delete[] this->m_firstName;
		this->m_firstName = nullptr;
	}

	if (this->m_lastName) {// != NULL
		delete[] this->m_lastName;
		this->m_lastName = nullptr;
	}
}

//////////////////////////////get and set/////////////////////////////////////

//return the first name of the mermaid
const char* Mermaid::GetFirstName() const {
	return this->m_firstName;
}

//return the last name of the mermaid
const char* Mermaid::GetLastName() const {
	return this->m_lastName;
}

void Mermaid::SetFirstName(const char* firstName) {
	if (this->m_firstName) {//!=NULL
		delete[] this->m_firstName;
		this->m_firstName = nullptr;
	}

	if (!firstName) {//==NULL
		this->m_firstName = nullptr;
		return;
	}

	this->m_firstName = strdup(firstName);
}

void Mermaid::SetLastName(const char* lastName) {
	if (this->m_lastName) {//!=NULL
		delete[] this->m_lastName;
		this->m_lastName = nullptr;
	}

	if (!lastName) {//==NULL
		this->m_lastName = nullptr;
		return;
	}

	this->m_lastName = strdup(lastName);
}

////////////////////////////// save and load /////////////////////////////////////

//read from the text file
void Mermaid::loadAddition(ifstream& ifs) {
	MammalsFish::loadAddition(ifs);// call to father
	ifs >> *this;
}

//save data into the text file
void Mermaid::saveAddition(ofstream& ofs) {
	MammalsFish::saveAddition(ofs);// call to father
	ofs << *this;
}

//save type of this class
void Mermaid::saveType(ofstream& ofs) {
	ofs << "M" << endl;
}

//read from the binary file
void Mermaid::loadAdditionBin(ifstream& ifs) {
	MammalsFish::loadAdditionBin(ifs);// call to father
	char buff1[200], buff2[200];
	size_t  len;
	ifs.read((char*)&len, sizeof(len));
	ifs.read(buff1, len);
	this->SetFirstName(buff1);

	ifs.read((char*)&len, sizeof(len));
	ifs.read(buff2, len);
	this->SetLastName(buff2);
}

//save data into the binary file
void Mermaid::saveAdditionBin(ofstream& ofs) {
	MammalsFish::saveAdditionBin(ofs);// call to father
	size_t  len = strlen(this->m_firstName) + 1;
	ofs.write((char*)&len, sizeof(len));
	ofs.write(this->m_firstName, len);

	len = strlen(this->m_lastName) + 1;
	ofs.write((char*)&len, sizeof(len));
	ofs.write(this->m_lastName, len);
}

//save type of this class
void Mermaid::saveTypeBin(ofstream& ofs) {
	char type = 'M';
	ofs.write(&type, sizeof(type));
}

////////////////////////////// operators /////////////////////////////////////

//initialize all values
const Mermaid& Mermaid::operator=(const Mermaid& other) {
	if (this == &other)//if equals
		return *this;

	this->SetAnimal(other.m_color, other.m_childCount, other.m_avgLifetime);//of animal
	this->SetMilk(other.m_milkLiters);//of mammal
	this->SetPregnance(other.m_pregnancyTime);//of mammal
	this->SetFin(other.m_finCount);//of fish
	this->SetGills(other.m_gillsCount);//of fish
	this->SetFirstName(other.m_firstName);//of mermaid
	this->SetLastName(other.m_lastName);//of mermaid
	return *this;
}

//print all value
ostream& operator<<(ostream& output, const Mermaid& other) {
	output << other.m_firstName << endl;
	output << other.m_lastName << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Mermaid& other) {
	char buff1[200], buff2[200];
	input.read(buff1, 1);//read endl

	input.getline(buff1, 200);
	other.SetFirstName(buff1);

	input.getline(buff2, 200);
	other.SetLastName(buff2);
	return input;
}

