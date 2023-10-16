#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals : public virtual Animal
{
public://c'tor and dis - c'tor
	Mammals();//set the default color to GRAY and other params to 0
	Mammals(const char* color, int childs, float avgLifetime, float preg, float milk);//init the Mammals with a given attributes
	Mammals(ifstream& in_file);//init the Mammals from a binary file
	virtual ~Mammals();

	Mammals(const Mammals& newMammal);//copy constructors

public://get and set
	float GetPregnanceTime() const;//return the pregnance time of the animal
	float GetMilk() const;//return the milk liters of the animal

	void SetPregnance(const float& time);
	void SetMilk(const float& milk);

public:// load and save
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file

protected:// save type for inherit
	virtual void saveType(ofstream& ofs) = 0;//save type of this class
	virtual void saveTypeBin(ofstream& ofs) = 0;//save type of this class

public://operators
	const Mammals& operator=(const Mammals& other);//initialize all values

protected://friend
	friend ostream& operator<<(ostream& output, const Mammals& other);//print all value
	friend istream& operator>>(istream& input, Mammals& other);//input all value

protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef