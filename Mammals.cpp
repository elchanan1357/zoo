#include "Mammals.h"

//////////////////////////constructors/////////////////////////////////

//set the default color to GRAY and other params to 0
Mammals::Mammals()
	:Animal(), m_pregnancyTime(0), m_milkLiters(0) {}

//init the Mammals with a given attributes
Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk)
	:Animal(color, childs, avgLifetime) {
	SetPregnance(preg);
	SetMilk(milk);
}

//init the Mammals from a binary file
Mammals::Mammals(ifstream& in_file)
	:Animal(in_file) {
	in_file.read((char*)&this->m_pregnancyTime, sizeof(this->m_pregnancyTime));
	in_file.read((char*)&this->m_milkLiters, sizeof(this->m_milkLiters));
}

//copy constructors
Mammals::Mammals(const Mammals& newMammal)
	:Animal() {
	*this = newMammal;
}

Mammals:: ~Mammals() {}

//////////////////////////get and set/////////////////////////////////

//return the pregnance time of the animal
float Mammals::GetPregnanceTime() const {
	return this->m_pregnancyTime;
}

//return the milk liters of the animal
float Mammals::GetMilk() const {
	return this->m_milkLiters;
}

//setting the pregnancy time
void Mammals::SetPregnance(const float& time) {
	if (time <= 0) {//the time must be positive
		this->m_pregnancyTime = 0;
		return;
	}

	this->m_pregnancyTime = time;
}

//setting the liters of milk
void Mammals::SetMilk(const float& milk) {
	if (milk <= 0) {//the liters must be positive
		this->m_milkLiters = 0;
		return;
	}

	this->m_milkLiters = milk;
}

//////////////////////////load and save/////////////////////////////////

//read from the text file
void Mammals::loadAddition(ifstream& ifs) {
	ifs >> *this;
}

//save data into the text file
void Mammals::saveAddition(ofstream& ofs) {
	ofs << *this;
}

//read from the binary file
void Mammals::loadAdditionBin(ifstream& ifs) {
	ifs.read((char*)&this->m_pregnancyTime, sizeof(this->m_pregnancyTime));
	ifs.read((char*)&this->m_milkLiters, sizeof(this->m_milkLiters));
}

//save data into the binary file
void Mammals::saveAdditionBin(ofstream& ofs) {
	ofs.write((char*)&this->m_pregnancyTime, sizeof(this->m_pregnancyTime));
	ofs.write((char*)&this->m_milkLiters, sizeof(this->m_milkLiters));
}


//print all value
ostream& operator<<(ostream& output, const Mammals& other) {
	output << other.m_pregnancyTime << endl;
	output << other.m_milkLiters << endl;
	return output;
}

//input all value
istream& operator>>(istream& input, Mammals& other) {
	input >> other.m_pregnancyTime >> other.m_milkLiters;
	return input;
}

////////////////////////// operators /////////////////////////////////

//initialize all values
const Mammals& Mammals::operator=(const Mammals& other) {
	if (this == &other)
		return *this;

	this->SetAnimal(other.GetColor(), other.GetChildCount(), other.GetLifetime());
	this->SetMilk(other.m_milkLiters);
	this->SetPregnance(other.m_pregnancyTime);
	return *this;
}