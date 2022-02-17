#ifndef FINANCESBOOK_H
#define FINANCESBOOK_H
#include <iostream>


#include "UserManager.h"
#include "FinancesManager.h"
using namespace std;

class FinancesBook
{
UserManager userManager;
FinancesManager *financesManager;

const string NAZWA_PLIKU_Z_ADRESATAMI;
const string NAZWA_PLIKU_Z_ADRESATAMIII;
public:
FinancesBook(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami,string nazwaPlikuZAdresatamiii)
: userManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_Z_ADRESATAMIII(nazwaPlikuZAdresatamiii)
{
    financesManager = NULL;
};
~FinancesBook()
{
    delete financesManager;
    financesManager = NULL;
};
void rejestracjaUzytkownika();
void wypiszWszystkichUzytkownikow();
int logowanieUzytkownika();
void zmianaHaslaZalogowanegoUzytkownika();
void wylogowanieUzytkownika();
void addIncome();
void addExpense();
void wyswietlWszystkichAdresatow();
void wyszukajAdresatowPoImieniu();
void wyszukajAdresatowPoNazwisku();
void usunAdresata();
void edytujAdresata();
void balanceCurrenMonth();
void balanceForChosenDate();
void balancePenultimateMonth();
void sortingExpenses();
int pobierzIdZalogowanegoUzytkownika();
char wybierzOpcjeZMenuUzytkownika();
char wybierzOpcjeZMenuGlownego();
};
#endif
