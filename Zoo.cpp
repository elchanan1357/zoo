#include "Zoo.h"

//////////////////////////////constructors and  dis - constructors/////////////////////////////////////

//default c'tor  - all to 0 or null
Zoo::Zoo()
	:m_name(nullptr), m_address(nullptr),
	m_ticketPrice(0), m_openHours(nullptr), m_closeHours(nullptr)
	, m_numOfAnimals(0), m_animals(nullptr) {}

//c'tor with data - init class
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
	:m_name(nullptr), m_address(nullptr), m_numOfAnimals(0), m_animals(nullptr),
	m_openHours(nullptr), m_closeHours(nullptr) {
	SetName(name);
	SetAddress(address);
	SetTicketPrice(ticket);
	SetOpenHour(open);
	SetCloseHour(close);
}

//c'tor that gets a binary file and loads the data of the zoo from the file
Zoo::Zoo(ifstream& in_file)
	:m_name(nullptr), m_address(nullptr), m_animals(nullptr)
	, m_openHours(nullptr), m_closeHours(nullptr) {
	char buffName[200], buffAddress[200], buffOpen[200], bufflose[200];
	size_t len;

	in_file.read((char*)&len, sizeof(len));//size of name
	in_file.read(buffName, len);//name
	SetName(buffName);//this -> name

	in_file.read((char*)&len, sizeof(len));//size of address
	in_file.read(buffAddress, len);//address
	SetAddress(buffAddress);//this -> address

	in_file.read((char*)&this->m_ticketPrice, sizeof(this->m_ticketPrice));//ticket

	in_file.read((char*)&len, sizeof(len));//size of open
	in_file.read(buffOpen, len);//open
	SetOpenHour(buffOpen);//this -> open

	in_file.read((char*)&len, sizeof(len));//size of close
	in_file.read(bufflose, len);//close
	SetCloseHour(bufflose);//this->close

	in_file.read((char*)&this->m_numOfAnimals, sizeof(this->m_numOfAnimals));//size
	this->m_animals = new Animal * [this->m_numOfAnimals];

	for (int i = 0; i < this->m_numOfAnimals; i++) {//read animals array
		char type;
		in_file.read(&type, sizeof(type));//type of animal

		switch (type)
		{
		case 'H':
			this->m_animals[i] = new Horse();
			break;
		case 'F':
			this->m_animals[i] = new Flamingo();
			break;
		case 'G':
			this->m_animals[i] = new GoldFish();
			break;
		case 'M':
			this->m_animals[i] = new Mermaid();
			break;
		}

		this->m_animals[i]->loadBin(in_file);
	}
}

//copy constructor
Zoo::Zoo(const Zoo& z)
	:m_name(nullptr), m_address(nullptr), m_animals(nullptr)
	, m_openHours(nullptr), m_closeHours(nullptr) {
	*this = z;
}

//d'tor
Zoo:: ~Zoo() {
	if (this->m_name) {// != NULL
		delete[] this->m_name;
		this->m_name = nullptr;
	}

	if (this->m_address) {// != NULL
		delete[] this->m_address;
		this->m_address = nullptr;
	}

	if (this->m_openHours) {// != NULL
		delete[] this->m_openHours;
		this->m_openHours = nullptr;
	}

	if (this->m_closeHours) {// != NULL
		delete[] this->m_closeHours;
		this->m_closeHours = nullptr;
	}

	if (!this->m_animals)// == NULL
		return;

	for (int i = 0; i < this->m_numOfAnimals; i++) {
		delete this->m_animals[i];
		this->m_animals[i] = nullptr;
	}
	delete[] this->m_animals;
	this->m_animals = nullptr;
}

//////////////////////////////get and set/////////////////////////////////////

//return the name of the zoo
const char* Zoo::GetName() const {
	return this->m_name;
}

//return the address of the zoo
const char* Zoo::GetAddress() const {
	return this->m_address;
}

//return the ticket price of the zoo
float Zoo::GetTicketPrice() const {
	return this->m_ticketPrice;
}

//return the open hour of the zoo
const char* Zoo::GetOpenHour() const {
	return this->m_openHours;
}

//return the close hour of the zoo
const char* Zoo::GetCloseHour() const {
	return this->m_closeHours;
}

//return the num of animals in the zoo
int	Zoo::GetNumOfAnimals() const {
	return this->m_numOfAnimals;
}

//return the animals array of the zoo
Animal** Zoo::GetAnimals() const {
	return this->m_animals;
}

void Zoo::SetName(const char* name) {
	if (this->m_name) {//!=NULL
		delete[] this->m_name;
		this->m_name = nullptr;
	}

	if (!name) {//==NULL
		this->m_name = nullptr;
		return;
	}

	this->m_name = strdup(name);
}

void Zoo::SetAddress(const char* address) {
	if (this->m_address) {//!=NULL
		delete[] this->m_address;
		this->m_address = nullptr;
	}

	if (!address) {//==NULL
		this->m_address = nullptr;
		return;
	}

	this->m_address = strdup(address);
}

void Zoo::SetTicketPrice(float ticket) {
	if (ticket <= 0) {//price must be positive
		this->m_ticketPrice = 0;
		return;
	}

	this->m_ticketPrice = ticket;
}

void Zoo::SetOpenHour(const char* open) {
	if (this->m_openHours) {//!=NULL
		delete[] this->m_openHours;
		this->m_openHours = nullptr;
	}

	if (!open) {//==NULL
		this->m_openHours = nullptr;
		return;
	}

	this->m_openHours = strdup(open);
}

void Zoo::SetCloseHour(const char* close) {
	if (this->m_closeHours) {//!=NULL
		delete[] this->m_closeHours;
		this->m_closeHours = nullptr;
	}

	if (!close) {//==NULL
		this->m_closeHours = nullptr;
		return;
	}

	this->m_closeHours = strdup(close);
}

void Zoo::SetNumOfAnimals(int size) {
	if (size) {//size must be positive
		this->m_numOfAnimals = 0;
		return;
	}

	this->m_numOfAnimals = size;
}

void Zoo::SetAnimals(Animal** animals, int size) {
	if (this->m_animals) {// != NULL
		for (int i = 0; i < this->m_numOfAnimals; i++) {
			delete this->m_animals[i];
			this->m_animals[i] = nullptr;
		}
		delete[] this->m_animals;
		this->m_animals = nullptr;
	}

	for (int i = 0; i < size; i++) {
		this->AddAnimal(animals[i]);
	}
}

////////////////////////////// save and load /////////////////////////////////////

//method to save the info to a text file
void Zoo::Save(ofstream& ofs) const {
	ofs << *this;
}

//method to load the info from a text file
void Zoo::Load(ifstream& ifs) {
	ifs >> *this;
}

//method to save the info to a binary file
void Zoo::SaveBin(ofstream& ofs) const {
	size_t len = strlen(this->m_name) + 1;
	ofs.write((char*)&len, sizeof(len));//size of name
	ofs.write(this->m_name, len);//name

	len = strlen(this->m_address) + 1;
	ofs.write((char*)&len, sizeof(len));//size of address
	ofs.write(this->m_address, len);//address

	ofs.write((char*)&this->m_ticketPrice, sizeof(this->m_ticketPrice));//ticket

	len = strlen(this->m_openHours) + 1;
	ofs.write((char*)&len, sizeof(len));//size of open
	ofs.write(this->m_openHours, len);//open

	len = strlen(this->m_closeHours) + 1;
	ofs.write((char*)&len, sizeof(len));//size of close
	ofs.write(this->m_closeHours, len);//close

	ofs.write((char*)&this->m_numOfAnimals, sizeof(this->m_numOfAnimals));//size
	for (int i = 0; i < this->m_numOfAnimals; i++) {//animals
		this->m_animals[i]->saveBin(ofs);
	}
}

//method to load the info from a binary file
void Zoo::LoadBin(ifstream& ifs) {
	char buffName[200], buffAddress[200], buffOpen[200], bufflose[200];
	size_t len;

	ifs.read((char*)&len, sizeof(len));//size of name
	ifs.read(buffName, len);//name
	SetName(buffName);//this -> name

	ifs.read((char*)&len, sizeof(len));//size of address
	ifs.read(buffAddress, len);//address
	SetAddress(buffAddress);//this -> address

	ifs.read((char*)&this->m_ticketPrice, sizeof(this->m_ticketPrice));//ticket

	ifs.read((char*)&len, sizeof(len));//size of open
	ifs.read(buffOpen, len);//open
	SetOpenHour(buffOpen);//this -> open

	ifs.read((char*)&len, sizeof(len));//size of close
	ifs.read(bufflose, len);//close
	SetCloseHour(bufflose);//this->close

	ifs.read((char*)&this->m_numOfAnimals, sizeof(this->m_numOfAnimals));//size
	this->m_animals = new Animal * [this->m_numOfAnimals];

	for (int i = 0; i < this->m_numOfAnimals; i++) {//read animals array
		char type;
		ifs.read(&type, sizeof(type));//type of animal

		switch (type)
		{
		case 'H':
			this->m_animals[i] = new Horse();
			break;
		case 'F':
			this->m_animals[i] = new Flamingo();
			break;
		case 'G':
			this->m_animals[i] = new GoldFish();
			break;
		case 'M':
			this->m_animals[i] = new Mermaid();
			break;
		}

		this->m_animals[i]->loadBin(ifs);
	}
}

////////////////////////////// operators /////////////////////////////////////

//adds an animal (only pointer, no copy needed) to the class and returns this with the change
Zoo& Zoo::operator+(Animal* an) {
	Animal** temp = new Animal * [this->m_numOfAnimals + 1];//create a copy
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		temp[i] = this->m_animals[i];//shallow copy
	}
	temp[this->m_numOfAnimals] = an;//shallow copy

	if (this->m_animals) {// != NULL
		delete[] this->m_animals;
		this->m_animals = nullptr;
	}

	this->m_animals = temp;
	this->m_numOfAnimals++;
	temp = nullptr;
	return *this;
}

//returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
Zoo  Zoo::operator+(const Zoo& other) const {
	Zoo newZoo(*this);
	for (int i = 0; i < other.m_numOfAnimals; i++) {
		newZoo += other.m_animals[i];//deep copy
	}

	return newZoo;
}

//initialize all values
const Zoo& Zoo::operator=(const Zoo& other) {
	if (this == &other)//if equals
		return *this;

	SetName(other.m_name);
	SetAddress(other.m_address);
	SetTicketPrice(other.m_ticketPrice);
	SetOpenHour(other.m_openHours);
	SetCloseHour(other.m_closeHours);
	SetNumOfAnimals(other.m_numOfAnimals);
	SetAnimals(other.m_animals, other.m_numOfAnimals);
	return *this;
}

//initialize all values
const Zoo& Zoo::operator+=(Animal* other) {
	this->AddAnimal(other);
	return *this;
}

////////////////////////////// all methods /////////////////////////////////////

//creates a copy of "an" (deep copy) and adds an animal to the array
void Zoo::AddAnimal(Animal* an) {
	Animal** temp = new Animal * [this->m_numOfAnimals + 1];//create a copy
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		temp[i] = this->m_animals[i];//shallow copy
	}

	if (typeid(*an) == typeid(Horse)) {// the type is horse
		temp[this->m_numOfAnimals] = new Horse(*(dynamic_cast<Horse*>(an)));
	}
	else if (typeid(*an) == typeid(Flamingo)) {// the type is Flamingo
		temp[this->m_numOfAnimals] = new Flamingo(*(dynamic_cast<Flamingo*>(an)));
	}
	else if (typeid(*an) == typeid(GoldFish)) {// the type is GoldFish
		temp[this->m_numOfAnimals] = new GoldFish(*(dynamic_cast<GoldFish*>(an)));
	}
	else if (typeid(*an) == typeid(Mermaid)) {// the type is Mermaid
		temp[this->m_numOfAnimals] = new Mermaid(*(dynamic_cast<Mermaid*>(an)));
	}

	if (this->m_animals) {// != NULL
		delete[] this->m_animals;
		this->m_animals = nullptr;
	}

	this->m_animals = temp;
	this->m_numOfAnimals++;
	temp = nullptr;
}

////////////////////////////// globules /////////////////////////////////////

ofstream& operator<<(ofstream& out, const Zoo& z) {
	out << z.m_name << endl;
	out << z.m_address << endl;
	out << z.m_ticketPrice << endl;
	out << z.m_openHours << endl;
	out << z.m_closeHours << endl;
	out << z.m_numOfAnimals << endl;
	for (int i = 0; i < z.m_numOfAnimals; i++) {
		z.m_animals[i]->save(out);
	}
	return out;
}

ifstream& operator >> (ifstream& in, Zoo& z) {
	char buffName[200], buffAddress[200], buffOpen[200], bufflose[200], type;
	in.getline(buffName, 200);//name
	z.SetName(buffName);//this -> name

	in.getline(buffAddress, 200);//address
	z.SetAddress(buffAddress);//this-> address

	in >> z.m_ticketPrice;//ticket price
	type = in.get();// for endl

	in.getline(buffOpen, 200);//open
	z.SetOpenHour(buffOpen);//this-> open

	in.getline(bufflose, 200);//close
	z.SetCloseHour(bufflose);//this-> close

	in >> z.m_numOfAnimals;//size 
	z.m_animals = new Animal * [z.m_numOfAnimals];
	for (int i = 0; i < z.m_numOfAnimals; i++) {//read animals array
		in >> type;//type of animal

		switch (type)
		{
		case 'H':
			z.m_animals[i] = new Horse();
			break;
		case 'F':
			z.m_animals[i] = new Flamingo();
			break;
		case 'G':
			z.m_animals[i] = new GoldFish();
			break;
		case 'M':
			z.m_animals[i] = new Mermaid();
			break;
		}

		z.m_animals[i]->load(in);
	}
	return in;
}