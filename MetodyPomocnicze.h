#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze
{
public:
     static string konwerjsaIntNaString(int liczba);
     string wczytajLinie();
     string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
     static int konwersjaStringNaInt(string liczba);
     int wczytajLiczbeCalkowita();
     char wczytajZnak();



};
#endif
