#ifndef FILETEXT_H
#define FILETEXT_H
#include <iostream>
#include <fstream>

using namespace std;

class FileText {

    const string NAZWA_PLIKU;

public:

    FileText(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }
    string pobierzNazwePliku();
    bool czyPlikJestPusty();

};
#endif
