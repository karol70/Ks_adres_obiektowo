#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.logowanieUzytkownika();
  //  ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wylogowanieUzytkownika();
  //  ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
  //  ksiazkaAdresowa.rejestracjaUzytkownika();


   // ksiazkaAdresowa.wypiszWszystkichUzytkownikow();



    return 0;
}
