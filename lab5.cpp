// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//*************  POMIESZCZENIE  ********************************************************

class Room
{
private:
	bool viewed;
	string descryption;
	Room *North, *East, *South, *West;	
public:
	Room(string);
	~Room();

	Room* getNorth();
	Room* getEast();
	Room* getSouth();	
	Room* getWest();
	string getDescryption();
	bool getViewed();
	void setViewed(bool);

};		

Room::Room(string _descryption)
{
	descryption=_descryption;
	viewed=false;
}

Room::~Room(){;}

string Room::getDescryption()
{
	return descryption;
}

bool Room::getViewed()
{
	return viewed;
}

void Room::setViewed(bool _viewed)
{
	viewed = _viewed;
}


Room* Room::getNorth()
{
	return(North);
}

Room* Room::getSouth()
{
	return(South);
}

Room* Room::getEast()
{
	return(East);
}

Room* Room::getWest()
{
	return(West);
}

//*************  Matryca  ********************************************************

class Matrix
{
private:
	int field_num;
	Room* position;

public:
	Matrix(int);
	~Matrix();
	void setPosition(Room*);
	
	void goNorth();
	void goEast();
	void goSouth();
	void goWest();

	void movement(char);
};

Matrix::Matrix(int _field_num)
{
	field_num = _field_num;

}

Matrix::~Matrix(){;}

void Matrix::setPosition(Room* _position)
{
	position = _position;
	position->setViewed(true);
}

void Matrix::goNorth()
{
	position = position->getNorth();
	position->setViewed(true);
}

void Matrix::goEast()
{
	position = position->getEast();
	position->setViewed(true);
}

void Matrix::goSouth()
{
	position = position->getSouth();
	position->setViewed(true);
}

void Matrix::goWest()
{
	position = position->getWest();
	position->setViewed(true);
}

void Matrix::movement(char direction)
{
	case 
}


int _tmain(int argc, _TCHAR* argv[])
{
	system("pause");
}

