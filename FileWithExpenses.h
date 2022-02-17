#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include "FileText.h"
#include "Expense.h"
#include "AuxiliaryMethod.h"
using namespace std;

class FileWithExpenses : public FileText

{
    int idOstatniegoAdresata;

public:
    FileWithExpenses(string nazwaPlikuExpenses):FileText(nazwaPlikuExpenses){
    idOstatniegoAdresata=0;
    };
    bool saveExpenseToFile(Expense expense);
    vector <Expense> wczytajAdresatowZalogowanegoUzytkownikaZPlikuu(int idZalogowanegoUzytkownika);
    int pobierzZPlikuIdOstatniegoAdresata();

};
#endif
