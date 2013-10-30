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
	if(position->getNorth!=NULL)
	{
	position = position->getNorth();
	position->setViewed(true);
	}
}

void Matrix::goEast()
{
	if(position->getEast!=NULL)
	{
	position = position->getEast();
	position->setViewed(true);
	}
}

void Matrix::goSouth()
{
	if(position->getSouth!=NULL)
	{
	position = position->getSouth();
	position->setViewed(true);
	}
}

void Matrix::goWest()
{
	if(position->getWest!=NULL)
	{
	position = position->getWest();
	position->setViewed(true);
	}
}

void Matrix::movement(char direction)
{
	switch (direction)
	{
	case 'n':
		goNorth();
			break;

	case 'e':
		goEast();
			break;

	case 's':
		goSouth();
			break;

	case 'w':
		goWest();
			break;

	default:
		cout<<"Niema takiego kierunku" << endl << "Dopuszczalne kierunki: n, e, s, w"<< endl;
		break;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	system("pause");
}

