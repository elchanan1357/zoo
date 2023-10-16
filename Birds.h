#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public Animal
{
public://c'tor and dis - c'tor
	Birds();//set the default color to GRAY and other params to 0
	Birds(const char* color, int childs, float avgLifetime, float incubation);//init the Birds with a given attributes
	Birds(ifstream& in_file);//init the Birds from a binary file
	virtual ~Birds();

	Birds(const Birds& other);//copy c'tor

public://Get and set
	float GetIncubationTime() const;//return the incubation time of the animal
	void SetIncubation(float incubation);//Setting incubation time

public:// load and save
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file

protected:// save type for inherit
	virtual void saveType(ofstream& ofs) = 0;//save type of this class
	virtual void saveTypeBin(ofstream& ofs) = 0;//save type of this class

public://operators
	const Birds& operator=(const Birds& other);//initialize all values

public://friend
	friend ostream& operator<<(ostream& output, const Birds& other);//print all value
	friend istream& operator>>(istream& input, Birds& other);//input all value

protected:
	float m_incubationTime;
};

#endif // ifndef