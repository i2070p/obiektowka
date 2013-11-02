// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

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

		void setNorth(Room*);
		void setEast(Room*);
		void setSouth(Room*);
		void setWest(Room*);

        string getDescryption();
        bool getViewed();
        void setViewed();

};                

Room::Room(string _descryption)
{
        descryption=_descryption;
        viewed=false;
		North = NULL;
		East = NULL;
		South = NULL;
		West = NULL;
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

void Room::setViewed()
{
        viewed = true;
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

void Room::setNorth(Room* _North)
{
	North = _North;
}

void Room::setEast(Room* _East)
{
	East = _East;
}

void Room::setSouth(Room* _South)
{
	South = _South;
}

void Room::setWest(Room* _West)
{
	West = _West;
}


//*************  Matryca  ********************************************************

class Matrix
{
private:
        int field_num;
        Room* position;
        int patern[3][3];
        Room*** rooms;

public:
        Matrix(int,int**);
        ~Matrix();
        void setPosition(Room*);
        
        void goNorth();
        void goEast();
        void goSouth();
        void goWest();
	//	void setRooms(int*[]);

        void movement(char);
};

Matrix::Matrix(int _field_num, int** _rooms_maze)
{
        field_num = _field_num;


		rooms = new Room**[field_num];
		for(int i=0;i<field_num;i++)
        {
			rooms[i] = new Room*[field_num];
        }


		int counter=0;	
		for(int i=0;i<field_num;i++)
		{
			for(int j=0;j<field_num;i++)
			{
				stringstream ss;
				ss << "Room: " << ++counter;
				rooms[i][j] = new Room(ss.str());
			}

		}




	for(int i=0;i<field_num;i++)
		{
			for(int j=0;j<field_num;j++)
			{
				if(_rooms_maze[i][j] == 1)
				{
			    	//dla north
					if(i-1>=0) if(_rooms_maze[i-1][j]==1) rooms[i][j]->setNorth(rooms[i-1][j]);
					//dla east
					if(j+1<field_num) if(_rooms_maze[i][j+1]==1) rooms[i][j]->setEast(rooms[i][j+1]);
					//dla south
					if(i+1<field_num) if(_rooms_maze[i+1][j]==1) rooms[i][j]->setSouth(rooms[i+1][j]);
					//dla west
			     	if(j-1>=0) if(_rooms_maze[i][j-1]==1) rooms[i][j]->setWest(rooms[i][j-1]); 
				}

			}

		}

	setPosition(rooms[0][0]);

}

Matrix::~Matrix(){;}

void Matrix::setPosition(Room* _position)
{
        position = _position;
        position->setViewed();
}

void Matrix::goNorth()
{
        if(position->getNorth()!=NULL)
        {
        position = position->getNorth();
        position->setViewed();
        }
}

void Matrix::goEast()
{
        if(position->getEast()!=NULL)
        {
        position = position->getEast();
        position->setViewed();
        }
}

void Matrix::goSouth()
{
        if(position->getSouth()!=NULL)
        {
        position = position->getSouth();
        position->setViewed();
        }
}

void Matrix::goWest()
{
        if(position->getWest()!=NULL)
        {
        position = position->getWest();
        position->setViewed();
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
  	int** pokoje = new int*[3];
		for(int i=0;i<3;i++)
		{
			pokoje[i]=new int[3];
		}
	
		pokoje[0][0] = 1; pokoje[0][1] = 1; pokoje[0][2] = 0;
		pokoje[1][0] = 0; pokoje[1][1] = 1; pokoje[1][2] = 0;
		pokoje[2][0] = 0; pokoje[2][1] = 1; pokoje[2][2] = 1;

		

		Matrix matryca = Matrix(3,pokoje);
        system("pause");
		return 0;
       
}
