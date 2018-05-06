#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char* argv[])
{
  ifstream fajl(argv[1]);
  int get_c,elozo;
  int szam = 0, szo = 0, karakter = 0, sor = 0, betu = 0;
  while(fajl.good())
  {
    get_c = fajl.get();
    if(isdigit(get_c) != 0)
      szam++;
    if(isalpha(get_c) != 0)
      betu++;
    if(get_c == '\n')
      sor++;

    if(get_c == '\n' || get_c == '\t' || get_c == ' ')
    {
      if(elozo != '\n' || elozo != '\t' || elozo != ' ')
        szo++;
    }
    elozo = get_c;
  }
  fajl.close();
  cout << "A fájlban " << betu << "db betű található." << endl;
  cout << "A fájlban " << szam << "db szám található." << endl;
  cout << "A fájlban " << szo << "db szó található." << endl;
  cout << "A fájlban " << sor << "db sor található." << endl;
  karakter = szam + betu;
  cout << "A fájlban " << karakter << "db karakter található." << endl;


  return 0;
}
