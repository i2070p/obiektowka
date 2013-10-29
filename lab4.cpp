#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <time.h> 
#include <ctime>
#include <fstream>
#include <vector>

#define gradecount 10; 

using namespace std;



//*************************************Student************
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
				string getOceny1();
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
        oceny = new int[10];
        for (int i=0;i<10; i++)
        {
        oceny[i] = source.oceny[i];
        }
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

string Student::getOceny1()
{   
        stringstream s2;
        int* tmp_tab = new int[10];
        string temp;
        for(int i=0; i<10;i++)
        {
                tmp_tab[i]=oceny[i];
                s2 << tmp_tab[i] << ";";
        }
        return s2.str();
}

void Student::Display()
{
        cout << getInicialy() << endl;
        cout << getNrgr() << endl;
        cout << getOceny() << endl;
}

//*************************************Grupa************

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
                //Group(string);
        void getList();
        void add(int, string, int, int*);
		void readfile(string);
		void writefile(string);

};

Group::Group(int _number)
{
        amount = _number;
        list = new Student[amount];

}

Group::Group(Group &source)
{
                amount = source.amount;
        list = new Student[source.amount];
        for(int i=0;i<source.amount;i++)
        {
                Student s(source.list[i]);
                list[i] = s;
        }
}

Group::~Group(){;}

void Group::add(int _place, string _inicialy, int _nrgr, int* o)
{
        list[_place] = Student(_inicialy,  _nrgr, o);
 /* cout << list[_place].getInicialy()<<endl;
        cout << list[_place].getNrgr()<<endl;
        cout << list[_place].getOceny()<<endl; */
}

void Group::getList()
{
        for(int i=0; i<amount; i++)
        {
             // list[i].Display();
                cout <<        list[i].getInicialy() << endl;
                cout <<        list[i].getNrgr() << endl;
                cout <<        list[i].getOceny() << endl; 
        }
}

void Group::readfile(string file)
{
       
		

        ifstream Inputfile(file);
        if(!Inputfile.is_open())
        {
                throw exception("Can't read file");                        
        }
               string line;
				int linenr=0;
                while(!Inputfile.eof())
                { 
//*************************************Deklaracje************
					string inicials="",tmp="";
					int nrgroup=0;
					 int* grades = new int[10];
					 
					int left = 0,right = 0;
					int size=0,pointer=0;

//*************************************~Deklaracje************
                        Inputfile >> line;
						while (line[right]!= 0)
						{
							right++;
							size++;
						}
						while(line[left]!=';')
						{
							inicials += line[left];
							left++;
						}
						nrgroup = line[left+1]-48;

					for(int i=left+3; i<size; i++ )
						{
							if(line[i]==';')
							{
								pointer++;
							}
							else
							{
								grades[pointer]=line[i]-48;
							}	
						}
					add(linenr,inicials,nrgroup,grades);
					linenr++;
                       
                }
        
}

void Group::writefile(string number)
{
	string times=""; 
	int temp;
	struct tm now;
	time_t t=time(0);
	localtime_s(&now, &t);
	ostringstream ss;
	ss << number;
	ss << "-";
	temp=now.tm_hour;
	ss << temp;
	temp=now.tm_min;
	ss << temp;
	temp=now.tm_sec;
	ss << temp;
	times+=ss.str();

	string filename="";
	filename+="grupa-";
	filename+=times;
	filename+=".txt";

	ofstream outputfile(filename);
	if(!outputfile.is_open())
	{
		throw exception("Can't read file");
	}

	for(int i=0; i<5; i++)
	{
		if(i!=4) 
		{
			outputfile << list[i].getInicialy() << ";"<< list[i].getNrgr()<<";"<<list[i].getOceny1()<<endl;
		}
		else
		{
			outputfile << list[i].getInicialy() << ";"<< list[i].getNrgr()<<";"<<list[i].getOceny1();
		}
	}
	outputfile.close();

}


int linecount(string file)
{
        int licznik=0;
        string tmp;
        ifstream in(file);
        if(!in.is_open())
        {
                throw exception("Can't read file");                        
        }
        if(true)
        {
                while(!in.eof())
                {
                        getline(in,tmp);
                        licznik++;
                }

        }
        return licznik;
}


int _tmain(int argc, _TCHAR* argv[])
{
        
 Group grupa1 = Group(5);
        Group grupa2 = Group(5);

        int student1_oceny[10];
        for(int i=0;i<10;i++)
        {
                student1_oceny[i] = rand() % 4+2;

        }

        for(int i=0;i<5;i++)
        {
                grupa1.add(i,"mw",210,student1_oceny);
        }

        cout << "Grupa 1:"<< endl;
    grupa1.getList(); 

        int student2_oceny[10];
        for(int i=0;i<10;i++)
        {
                student2_oceny[i] = rand() % 4+2;

        }

        for(int i=0;i<5;i++)
        {
                grupa2.add(i,"pb",120,student2_oceny);
        }
        cout << "Grupa 2:" << endl;
    grupa2.getList(); 


        cout << "Grupa 3:" << endl;
        Group grupa3 = Group(grupa2);
        grupa3.getList();


        /*Student uno = Student("ch",110,student2_oceny);
        Student duo = Student(uno);
        duo.Display();
        */

                cout << endl << endl;

                cout<< linecount("plik1.txt");

                cout << endl << endl;

				Group grupa4 = Group(5);
				grupa4.readfile("plik1.txt");
				grupa4.getList();
				grupa4.writefile("5");

        system("pause");

}

/*
plik1.txt

MW;5;2;2;3;4;4;5;5;2;3;3;
MJ;5;2;2;3;4;4;5;5;2;3;3;
WS;5;1;1;2;2;3;3;5;4;5;2;
CK;5;2;2;3;4;4;5;5;2;3;3;
GS;5;1;1;2;2;3;4;5;4;3;2;

przykladowy plik wynikowy

grupa-5-205330
MW;5;2;2;3;4;4;5;5;2;3;3;
MJ;5;2;2;3;4;4;5;5;2;3;3;
WS;5;1;1;2;2;3;3;5;4;5;2;
CK;5;2;2;3;4;4;5;5;2;3;3;
GS;5;1;1;2;2;3;4;5;4;3;2;

;

