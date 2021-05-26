#include "PlikZAdresatami.h"


bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true) {
            plikTekstowy <<liniaZDanymiAdresata;
        } else {
            plikTekstowy << liniaZDanymiAdresata<<endl ;
        }

        idOstatniegoAdresata++;
        plikTekstowy.close();
        system("pause");
        return true;
    }
    return false;
}


string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector<Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
        plikTekstowy.close();
    }
    if (daneOstaniegoAdresataWPliku !="") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;

}
Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str())) ;
                break;
            case 2:
                adresat.ustawIdUzytkownika( atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami (string daneJednegoAdresataOddzielonePionowymiKreskami) {

    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata) {


    Adresat adresat;
    vector<Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    fstream tymczasowyPlikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open("tymczasowyPlikTekstowy.txt", ios::out | ios::app);


    if (plikTekstowy.good() == true)
        {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
            {
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            if (idUsuwanegoAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku))
            {

                if (tymczasowyPlikTekstowy.good() == true)
                    {
                        tymczasowyPlikTekstowy << daneOstaniegoAdresataWPliku<<endl ;
                    }
            }
            }
        }

        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunPlik(pobierzNazwePliku());
        zmienNazwePliku("tymczasowyPlikTekstowy.txt",pobierzNazwePliku());
        cout << "Wybrany adresat zostal usuniety"<<endl;
        system("pause");
    }


void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;

}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    string liniaZDanymiAdresata ="";
    fstream plikTekstowy;
    fstream tymczasowyPlikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open("tymczasowyPlikTekstowy.txt", ios::out | ios::app);

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    if (plikTekstowy.good() == true)
        {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
            {
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            if (adresat.pobierzId() != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku))
            {

                if (tymczasowyPlikTekstowy.good() == true)
                    {
                        tymczasowyPlikTekstowy << daneOstaniegoAdresataWPliku<<endl ;
                    }
            }
            else
                tymczasowyPlikTekstowy << liniaZDanymiAdresata<<endl;
            }
        }
         plikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunPlik(pobierzNazwePliku());
        zmienNazwePliku("tymczasowyPlikTekstowy.txt",pobierzNazwePliku());
}

