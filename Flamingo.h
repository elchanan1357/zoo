#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public://c'tor and dis - c'tor
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight);//init the Flamingo with a given attributes
	Flamingo(ifstream& in_file);//init the Flamingo from a binary file
	virtual ~Flamingo();

	Flamingo(const Flamingo& other);////copy constructor

public://get and set
	float GetHeight() const;//return the avg height of the flamingo
	void SetHeight(float avgHeight);

public:// load and save
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file

public:// save type
	virtual void saveType(ofstream& ofs);//save type of this class
	virtual void saveTypeBin(ofstream& ofs);//save type of this class

public://operators
	const Flamingo& operator=(const Flamingo& other);//initialize all values

public://friend
	friend ostream& operator<<(ostream& output, const Flamingo& other);//print all value
	friend istream& operator>>(istream& input, Flamingo& other);//input all value

protected:
	float m_avgHeight;
};

#endif // ifndef