#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public://c'tor and dis c'tor
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL);//init the GoldFish with a given attributes
	GoldFish(ifstream& in_file);//init the GoldFish from a binary file
	virtual ~GoldFish();

	GoldFish(const GoldFish& other);//copy constructor

public://get and set
	float GetWeight() const;//return the avg weight of the gold fish
	float GetLength() const;//return the avg length of the gold fish

	void SetWeight(float avgW);
	void SetLength(float avgL);

public://load and save 
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file
	virtual void saveType(ofstream& ofs);//save type of this class

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file
	virtual void saveTypeBin(ofstream& ofs);//save type of this class

public://operators
	const GoldFish& operator=(const GoldFish& other);//initialize all values

public://friend
	friend ostream& operator<<(ostream& output, const GoldFish& other);//print all value
	friend istream& operator>>(istream& input, GoldFish& other);//input all value


protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef