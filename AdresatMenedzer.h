#ifndef ADRESATMENEGER_H
#define ADRESATMENEGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"


using namespace std;

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

    void wyswietlDaneAdresata(Adresat adresat);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    :plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();

};

#endif
