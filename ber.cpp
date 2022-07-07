#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <charconv>
#include <string>

using namespace std;

//prototypy funkcji  



void ZapiszDoDziennika(string tekst);
void PrzygotujPlik(string nazwa, int rozmiar, char znak);
void menu();
void ObliczamBER(string plik1, string plik2);

int main(int argc, char* argv[])
{
int liczba;

if (argc==3) 
    {
        cout<< "Uruchomienie programu z parametrami"<<endl;
        cout<< "Wpisz polecenie w cmd: ber.exe plik1.bin plik2.bin"<<endl;
        cout<<"test"<<endl;
        string p1 = argv[1];
        string p2 = argv[2];
        cout<<p1<<endl;
        cout<<p2<<endl;
        ZapiszDoDziennika("Uruchomienie programu z parametrami ");
        ObliczamBER(p1,p2);
        ZapiszDoDziennika("Koniec działania programu");
        system("pause");

    }

do
{
    system("cls");
    cout<<"PROGRAM DO OBLICZANIA WARTOSCI BER"<<endl;
    menu();
    cout<<"Wybierz pozycje menu"<<endl<<"Wybieram: ";
    cin >> liczba;
        switch(liczba)
        {
        case 1:
            system("cls");
            cout << "Tworzenie dwoch takich samych malych plikow"<<endl;
            PrzygotujPlik("plik1.bin",100,0x55);
            PrzygotujPlik("plik2.bin",100,0x55);
            ZapiszDoDziennika("Utworzono dwa identyczne male pliki po 100B");
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Tworzenie dwoch roznych malych plikow"<<endl;
            PrzygotujPlik("plik1.bin",100,0x55);
            PrzygotujPlik("plik2.bin",100,0x50);
            ZapiszDoDziennika("Utworzono dwa rozne male pliki po 100B");
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Tworzenie dwoch roznych duzych plikow"<<endl;
            PrzygotujPlik("plik1.bin",400*1048576,0x55);
            PrzygotujPlik("plik2.bin",400*1048576,0x50);
            ZapiszDoDziennika("Utworzono dwa rozne duze pliki po 400MB");
            system("pause");
            break;
         default:
            cout << "Wybierz inna wartosc. Ta jest nieobslugiwana!"<<endl;
			system("pause");
			system("cls");
			cin.clear();
            break;
        }
} while( liczba != 0 );


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


void ObliczamBER(string plik1, string plik2)
{
    double ilosc;
    double roznych;
    float ber;
    clock_t czas0;
    clock_t czas1;
    fstream plik1_dane;
    fstream plik2_dane;
    //bool porownanie;

    plik1_dane.open(plik1, ios::binary | ios::in);
    plik2_dane.open(plik2, ios::binary | ios::in);
    ZapiszDoDziennika("Otwarto dwa pliko do porownan");

    if (plik1_dane.good() && plik2_dane.good())
        {
            ZapiszDoDziennika("Rozpeczecie obliczania BER");
            char z1 = 0x00;
            char z2 = 0x00;
            czas0 = clock();

            while (!plik1_dane.eof())
            {
                plik1_dane >> z1;
                plik2_dane >> z2;
                //cout<<"z1: "<<to_string(z1)<<" z2: "<<to_string(z2) << endl;

                if (z1==z2)
                    {
                        ilosc+=1;
                    }
                else
                    {
                        roznych +=1;
                        ilosc+=1;
                    }             
            }
            ber = (float) roznych/ilosc;
            czas1 = clock();
            ZapiszDoDziennika("Roznych bitow jest: " + to_string(roznych));
            ZapiszDoDziennika("Ilosc porownanych jest: " + to_string(ilosc));
            ZapiszDoDziennika("BER wynosi: " + to_string(ber));

        }
    else
        {
            ZapiszDoDziennika("Nie mozna otworzyc plikow do porownania");
        }
}