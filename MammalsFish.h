#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills);//init the MammalsFish with a given attributes
	MammalsFish(ifstream& in_file);//init the MammalsFish from a binary file
	virtual ~MammalsFish();

	MammalsFish(const MammalsFish& other);//copy constructor

public://load and save
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file
	virtual void saveType(ofstream& ofs) = 0;//save type of this class

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file
	virtual void saveTypeBin(ofstream& ofs) = 0;//save type of this class
};

#endif // ifndef