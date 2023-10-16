#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other params to 0
	Animal(const char* color, int childs, float avgLifetime);//init the Animal with a given attributes
	Animal(ifstream& in_file);//init the Animal from a binary file

	Animal(const Animal& newAnimal);

public:
	virtual ~Animal();

public://get
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;//return the life time of the animal

protected://set
	void SetColor(const char* color);//setting the color
	void SetChildren(const int& count);//setting the number of children
	void SetLifeTime(const float& average);//setting the average life time
	void SetAnimal(const char* color, int childs, float avgLifetime);//Settings all values of animal

public://files
	void load(ifstream& ifs);//read from the text file
	void save(ofstream& ofs);//save data into the text file
	void loadBin(ifstream& ifs);//read from the binary file
	void saveBin(ofstream& ofs);////save data into the binary file

protected://files to inherit
	virtual void loadAddition(ifstream& ifs) = 0;//read from the text file
	virtual void saveAddition(ofstream& ofs) = 0;//save data into the text file
	virtual void saveType(ofstream& ofs) = 0;//save type of this class

	virtual void loadAdditionBin(ifstream& ifs) = 0;//read from the binary file
	virtual void saveAdditionBin(ofstream& ofs) = 0;//save data into the binary file
	virtual void saveTypeBin(ofstream& ofs) = 0;//save type of this class

public://operators
	const Animal& operator=(const Animal& other);//initialize all values

public://friend
	friend ostream& operator<<(ostream& output, const Animal& other);//print all value
	friend istream& operator>>(istream& input, Animal& other);//input all value

protected:
	char* m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

#endif // ifndef