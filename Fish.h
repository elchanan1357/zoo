#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public virtual Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish(const char* color, int childs, float avgLifetime, int fin, int gills);//init the Fish with a given attributes
	Fish(ifstream& in_file);//init the Fish from a binary file
	virtual ~Fish();

	Fish(const Fish& other);//copy constructor

public://set and get
	int	GetFinCount() const;//return the fin count of the animal
	int	GetGillsCount() const;//return the gills count of the animal

	void SetFin(int fin);
	void SetGills(int gills);

public://load and save
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file

protected:// save type for inherit
	virtual void saveType(ofstream& ofs) = 0;//save type of this class
	virtual void saveTypeBin(ofstream& ofs) = 0;//save type of this class

public://operators
	const Fish& operator=(const Fish& other);//initialize all values

public://friend
	friend ostream& operator<<(ostream& output, const Fish& other);//print all value
	friend istream& operator>>(istream& input, Fish& other);//input all value

protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef