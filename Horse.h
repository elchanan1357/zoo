#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public://c'tor and dis - c'tor
	Horse();//set the default color to GRAY and other params to 0
	Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type);//init the Horse with a given attributes
	Horse(ifstream& in_file);//init the Horse from a binary file
	virtual ~Horse();

	Horse(const Horse& other);//copy constructor

public://get and set
	const char* GetType() const;//return the type of the horse
	void  SetType(const char* type);

public:// load and save
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file

public:// save type
	virtual void saveType(ofstream& ofs);//save type of this class
	virtual void saveTypeBin(ofstream& ofs);//save type of this class

public://operators
	const Horse& operator=(const Horse& other);//initialize all values

protected://friend
	friend ostream& operator<<(ostream& output, const Horse& other);//print all value
	friend istream& operator>>(istream& input, Horse& other);//input all value


protected:
	char* m_type;
};

#endif // ifndef