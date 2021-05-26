#include <iostream>
#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

using namespace std;

char wybierzOpcjeZMenuUzytkownika();
char wybierzOpcjeZMenuGlownego();

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");

    int idZalogowanegoUzytkownika = 0;
    int idOstatniegoAdresata = 0;
    int idUsunietegoAdresata = 0;
    char wybor;

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
               ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
               ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
               ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
               ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                idZalogowanegoUzytkownika =0;
                break;
            }
        }
    }
    return 0;
}



   char wybierzOpcjeZMenuGlownego()
{
    char wybor;
    MetodyPomocnicze metodyPomocnicze;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}
char wybierzOpcjeZMenuUzytkownika()
{
    char wybor;
    MetodyPomocnicze metodyPomocnicze;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}


