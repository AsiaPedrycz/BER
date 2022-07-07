#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

void ZapiszDoDziennika(string tekst);
void PrzygotujPlik(string nazwa, int rozmiar, char znak);
void menu();

int main()
{
int liczba;

do
{
    system("cls");
    menu();
    cout<<"Wybierz pozycje menu"<<endl<<"Wybieram: ";
    cin >> liczba;
        switch(liczba)
        {
        case 1:
            system("cls");
            cout << "wybor 1"<<endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "wybor 2"<<endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "wybor 3"<<endl;
            system("pause");
            break;
         //default:
           // break;
        }
} while( liczba != 0 );

    
   // cout << "obliczanie BER"<<endl;
   // ZapiszDoDziennika("Rozpoczecie pracy");

    //delay(1020);
   // PrzygotujPlik("plik1.bin",100,0x55);
   // PrzygotujPlik("plik2.bin",100,0x55);
    
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

void menu()
{
    cout << "======================================="<<endl;
    cout << "Wybierz interesujacy cie program"<<endl;
    cout << "[1] - Porownaj takie same male pliki" <<endl;
    cout << "[2] - Porownaj rozne male pliki" << endl;
    cout << "[3] - Porownaj rozne duze pliki" <<endl;
    cout << "[0] - wyjscie z programu" <<endl;
    cout << "======================================="<<endl;
};