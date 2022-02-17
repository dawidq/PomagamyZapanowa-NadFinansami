#ifndef AUXILIARYMETHOD_H
#define AUXILIARYMETHOD_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>
using namespace std;
class AuxiliaryMethod
{
    public:
   static string konwerjsaIntNaString(int liczba);
   static int konwersjaStringNaInt(string liczba);
   static string wczytajLinie();
   static string loadSystemDate();
   static string giveDate();
   static bool checkDate(string date);
   static char wczytajZnak();
   static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
   static float zamienPrzecinekNaKropke(string wartosc);
   static int wczytajLiczbeCalkowita();
   static int conversionDateStringToInt(string date);
   static string conversionDateIntToString(int dateInt);
   static string conversionFloatToString(float liczba);
};
#endif
