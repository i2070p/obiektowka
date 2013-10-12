// lab1.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

string jednosci[10] = {"", "jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};
string dzies[10] = {"", " dziesiec", " dwadziescia", " trzydziesci", " czterdziesci", " piecdziesiat", " szescdziesiat", " siedemdziesiat", " osiemdziesiat", " dziewiecdziesiat"};
string setki[10] = {"", " sto", " dwiescie", " trzysta", " czterysta", " piecset", " szescset", " siedemset", " osiemset", " dziewiecset"};
string nastki[10] = {"dziesiec", " jedenascie", " dwanascie", " trzynascie", " czternascie", " pietnascie", " szesnascie", " siedemnascie", " osiemnascie", " dziewietnascie"};

bool tys,mln,mld,bln;

string Sto(int _kwota){
	int n,l1,l2,l3;
	n=_kwota;
	string slowo = " ";

	l1=n%10; n/=10;
	l2=n%10; n/=10;
	l3=n%10;
	if(l3!=0)
	{
		slowo+=setki[l3];
	}
	if (l2!=0)
	{
		if (l2==1)
		{
			slowo+=nastki[l1];
			return slowo;
		}
		slowo+=dzies[l2];
		}
	slowo+=jednosci[l1];
	return slowo;
};

void Wielkosc(long int _kwota){
	//bool tys,mln,mld,bln;
	long int kwota=_kwota;
	if(kwota/1000>=1){tys=true;}
	if(kwota/1000000>=1){mln=true;}
	if(kwota/1000000000>=1){mld=true;}

}

string Zapis(long int _kwota){
	string napis;
	long int kwota = _kwota;
	int temp;
	Wielkosc(kwota);
	if(mld==true){
		temp=kwota/1000000000;
		napis += Sto(temp);
		napis += " mld.";
		kwota-=(temp*1000000000);
	}
	if(mln==true){
		temp=kwota/1000000;
		napis += Sto(temp);
		napis += " mln.";
		kwota-=(temp*1000000);
	}
	if(tys==true)
	{
		temp=kwota/1000;
		napis += Sto(temp);
		napis += " tys.";
		kwota-=(temp*1000);
	}
		napis += Sto(kwota);
	return napis;	
}

int _tmain(int argc, _TCHAR* argv[])
{

    long int liczba;
	cout << "Podaj kwote: ";
	cin >> liczba;


	cout << Zapis(liczba) << endl;
	system("pause");
}

