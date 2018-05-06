#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

using namespace std;

int main()
{
    int x = 0, y = 0;
    int x1 = x-1, y1 = y-1;
    int width = 75, height = 25;

    char wall = '=';

    while(true){
        usleep(100000);
        system("clear");

        x += pow(-1, x1/(width-3));
        y += pow(-1, y1/(height-3));
        x1++;
        y1++;

///Felső fal
        for(int i = 0; i < width; i++){
            cout << wall;
        }
        cout << endl;
///Labda előtti falak, tér
        for(int i = 0; i < y-1; i++){
            cout << wall;
            for(int j = 0; j < width-2; j++){
                cout << " ";
            }
            cout << wall << endl;
        }
///Labda sora
        cout << wall;
        for(int i = 0; i < x-1; i++){
            cout << " ";
        }
        cout << "o";
        for(int i = x+1; i < width-1; i++){
            cout << " ";
        }
        cout << wall << endl;
///Labda utáni sorok
        for(int i = y; i < height-2; i++){
            cout << wall;
            for(int j = 0; j < width-2; j++){
                cout << " ";
            }
            cout << wall << endl;
        }
        for(int i = 0; i < width; i++){
            cout << wall;
        }

    }
    return 0;
}
