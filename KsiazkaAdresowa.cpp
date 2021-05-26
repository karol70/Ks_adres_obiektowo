#include "KsiazkaAdresowa.h"

using namespace std;



void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();

}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}

int KsiazkaAdresowa::logowanieUzytkownika()
{
   uzytkownikMenedzer.logowanieUzytkownika();
   if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
   {
       adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
   }
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
 {
     uzytkownikMenedzer.wylogowanieUzytkownika();
     delete adresatMenedzer;
     adresatMenedzer = NULL;
 }

 int KsiazkaAdresowa::dodajAdresata()
 {
     if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
     {
        adresatMenedzer ->dodajAdresata();
     }
     else
     {
     cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
     system("pause");
     }

 }

 void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
 {
     if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
     {
       adresatMenedzer->wyswietlWszystkichAdresatow();
     }

 }

 void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
 {
     adresatMenedzer -> wyszukajAdresatowPoImieniu();
 }

 void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
 {
     adresatMenedzer -> wyszukajAdresatowPoNazwisku();
 }

 void KsiazkaAdresowa::usunAdresata()
 {
     adresatMenedzer -> usunWybranegoAdresataZPliku();
 }

 void KsiazkaAdresowa::edytujAdresata()
 {
     adresatMenedzer -> edytujAdresata();
 }

