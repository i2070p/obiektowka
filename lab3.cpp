// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Student{
public:
	Student(string, int, int*);
	~Student();
	void Display();
private:
	int nrgr;
	int* oceny;
	string inicialy;
}		

Student::Student(string _inicialy, int _nrgr, int* o  )
{
	inicialy=_inicialy;
	nrgr = _nrgr;
	oceny = new int[10];
	oceny=o;
	
}
Student::~Student(){;}

void Student::Display()
{
	cout << "Inicialy: " << inicialy << endl;
	cout << "nr grupy: " << nrgr << endl;
	for(int i=0;i<10;i++)
	{
	cout << "oceny: " << inicialy[i] << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

