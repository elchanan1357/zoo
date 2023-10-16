#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public://c'tor and dis c'tor
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName);//init the Mermaid with a given attributes
	Mermaid(ifstream& in_file);//init the Mermaid from a binary file
	virtual ~Mermaid();

	Mermaid(const Mermaid& other);//copy constructor

public://get and set
	const char* GetFirstName() const;//return the first name of the mermaid
	const char* GetLastName() const;//return the last name of the mermaid

	void SetFirstName(const char* firstName);
	void SetLastName(const char* lastName);

public://load and save 
	virtual void loadAddition(ifstream& ifs);//read from the text file
	virtual void saveAddition(ofstream& ofs);//save data into the text file
	virtual void saveType(ofstream& ofs);//save type of this class

	virtual void loadAdditionBin(ifstream& ifs);//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs);//save data into the binary file
	virtual void saveTypeBin(ofstream& ofs);//save type of this class

public://operators
	const Mermaid& operator=(const Mermaid& other);//initialize all values

public://friend
	friend ostream& operator<<(ostream& output, const Mermaid& other);//print all value
	friend istream& operator>>(istream& input, Mermaid& other);//input all value

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef