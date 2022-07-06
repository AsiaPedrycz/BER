#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

void ZapiszDoDziennika(string tekst);
void PrzygotujPlik(string nazwa, int rozmiar, char znak);

int main()
{
    cout << "obliczanie BER"<<endl;
    ZapiszDoDziennika("Rozpoczecie pracy");

    //delay(1020);
    PrzygotujPlik("plik1.bin",100,0x55);
    PrzygotujPlik("plik2.bin",100,0x55);
    

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

void PrzygotujPlik(string nazwa, int rozmiar, char znak)
{
    ZapiszDoDziennika("Rozpoczecie tworzenia pliku o nazwie: " + nazwa );
    fstream plik;
    plik.open(nazwa, ios::binary | ios::out);
    if (plik.good())
        {
            for (int a=0; a<rozmiar; a++)
                plik << znak;
            plik.close();    
            ZapiszDoDziennika("Zakonczenie tworzenia pliku o nazwie: " + nazwa );
        }
    


}
