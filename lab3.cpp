#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
// Student
class Student{
private:
        int nrgr;
        int* oceny;
        string inicialy;
		//Student(){;};

public:
		Student(){;};
        Student(string, int, int*);
		Student(Student &);
        ~Student();
        string getInicialy();
		string getOceny();
		string getNrgr();
		void Display();
		void setStudent(string, int, int*);

}   ;             


Student::Student(string _inicialy, int _nrgr, int* o  )
{
        setStudent(_inicialy,  _nrgr, o);
        
}
Student::~Student(){;}

Student::Student(Student &source)
{
	nrgr=source.nrgr;
	oceny = source.oceny;
	inicialy = source.inicialy;
}

void Student::setStudent(string _inicialy, int _nrgr, int* o  )
{
	inicialy = _inicialy;
	nrgr= _nrgr;
	oceny = new int [10];
	for(int i=0;i<10;i++)
	{
	oceny[i]=o[i];
	}
}

string Student::getInicialy()
{
	return inicialy;
}

string Student::getNrgr()
{
	stringstream s1;
	s1 << nrgr;
	return s1.str();

}

string Student::getOceny()
{   
	stringstream s2;
	int* tmp_tab = new int[10];
	string temp;
	for(int i=0; i<10;i++)
	{
		tmp_tab[i]=oceny[i];
		s2 << tmp_tab[i] << " ";
	}
	return s2.str();
}

void Student::Display()
{
	cout << getInicialy() << endl;
	cout << getNrgr() << endl;
	cout << getOceny() << endl;
}

//Grupa

class Group
{
private:
	Student* list;
	int amount;
	Group(){};
public:
	Group(int);
	~Group();
	Group(Group &);
	void getList();
	void add(int, string, int, int*);

};

Group::Group(int _number)
{
	int amount = _number;
	list = new Student[amount];

}

Group::Group(Group &source)
{
	list= source.list;
}

Group::~Group(){;}

void Group::add(int _place, string _inicialy, int _nrgr, int* o)
{
	list[_place] = Student(_inicialy,  _nrgr, o);
}

void Group::getList()
{
	for(int i=0; i<amount; i++)
	{
		// list[i].Display();
		cout <<	list[i].getInicialy() << endl;
		cout <<	list[i].getNrgr() << endl;
		cout <<	list[i].getOceny() << endl; 
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
/*	string s;
	int x;
	int y[10];

	cout << "Podaj inicialy Studenta: "<<endl;
	cin >> s;
	cout << "Podaj grupe Studenta: "<<endl;
	cin >> x;
	for (int i=0;i<10;i++)
	{
		cout << "Podaj ocene nr "<< i+1 << " Studenta: "<<endl;
		cin >> y[i];
	}

	Student student1 = Student(s,x,y);
	cout << student1.getInicialy()<<endl;
*/	
 Group grupa1 = Group(5);
	Group grupa2 = Group(5);

	int student1_oceny[10];
	for(int i=0;i<10;i++)
	{
		student1_oceny[i] = rand() % 4+2;
		//cout << student1_oceny[i] << endl;

	}

	for(int i=0;i<5;i++)
	{
		grupa1.add(i,"mw",210,student1_oceny);
	}
    grupa1.getList(); 


/*  Student guwniak = Student("mw",210,student1_oceny);
	cout<<guwniak.getInicialy();
	cout<<guwniak.getNrgr();
	cout<<guwniak.getOceny(); */
        system("pause");
}
