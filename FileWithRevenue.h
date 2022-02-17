#ifndef FILEWITHREVENUE_H
#define FILEWITHREVENUE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "FileText.h"
#include "Income.h"
#include "AuxiliaryMethod.h"
using namespace std;

class FileWithRevenue : public FileText

{
    int idOstatniegoAdresata;

public:
    FileWithRevenue(string nazwaPlikuZAdresatami):FileText(nazwaPlikuZAdresatami){
    idOstatniegoAdresata=0;
    };
    bool dopiszAdresataDoPliku(Income income);
    vector <Income> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzZPlikuIdOstatniegoAdresata();

};
#endif
