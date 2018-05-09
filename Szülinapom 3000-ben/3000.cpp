//Használat: ./fajl [ev] [honap] [nap] [hanyadik_nap_a_heten]

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

	int szul_datum[4];
	szul_datum[0] = atoi(argv[1]);
	szul_datum[1] = atoi(argv[2]);
	szul_datum[2] = atoi(argv[3]);
	szul_datum[3] = atoi(argv[4]);
	int ev = 2000, honap = 1, nap = 1, hetnapja = 5; //1000 ev
	int honapok[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	string napok[7] = {"Hétfõ", "Kedd", "Szerda", "Csütörtök", "Péntek", "Szombat", "Vasárnap"};

	while(ev != 3000){
		hetnapja += 365;
		if(ev % 4 == 0 && !(ev % 100 == 0 && ev % 400 != 0)){
			hetnapja++;
		}
		ev++;
	}

	hetnapja += honapok[szul_datum[1]-1];
	hetnapja += szul_datum[2]-1;
	cout << napok[hetnapja%7] << endl;

	return 0;
}
