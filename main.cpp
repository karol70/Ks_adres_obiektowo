#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");
    ksiazkaAdresowa.logowanieUzytkownika();
 //   ksiazkaAdresowa.usunAdresata();
   ksiazkaAdresowa.dodajAdresata();
  //  ksiazkaAdresowa.dodajAdresata();
   // ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
 /*   ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
*/
    return 0;
}
