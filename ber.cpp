#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

void ZapiszDoDziennika(string tekst);

int main()
{
    cout << "obliczanie BER"<<endl;
    ZapiszDoDziennika("Test tego");

    //delay(1020);
    ZapiszDoDziennika("2 test");

    return 0;

}

void ZapiszDoDziennika(string tekst)
{
    time_t odcisk;
    time (&odcisk);
    printf ("Data zdarzenia: %s", ctime(&odcisk));
    fstream plikdziennika;
    plikdziennika.open("Log.txt", ios::app);
    if (plikdziennika.good())
        {
            plikdziennika << "Data zdarzenia: "<< ctime(&odcisk) << " - " << tekst << endl;
            plikdziennika.close();
        }
} 

