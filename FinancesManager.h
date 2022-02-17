#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <ostream>
#include "Income.h"
#include "Expense.h"
#include "FileWithRevenue.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethod.h"
using namespace std;

class FinancesManager
{
const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
vector <Income> incomes;
vector <Expense> expenses;
FileWithRevenue fileWithRevenue;
FileWithExpenses fileWithExpenses;
Income addNewIncome();
Expense addNewExpense();
void wyswietlDaneAdresata(Income income);

public:

FinancesManager(string nazwaPlikuZAdresatami,string nazwaPlikuZAdresatamiii, int idZalogowanegoUzytkownika)
        :fileWithRevenue(nazwaPlikuZAdresatami),fileWithExpenses(nazwaPlikuZAdresatamiii), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
        {
incomes = fileWithRevenue.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
expenses = fileWithExpenses.wczytajAdresatowZalogowanegoUzytkownikaZPlikuu(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };



void addIncome();
void addExpense();
void wyswietlWszystkichAdresatow();
void wyszukajAdresatowPoImieniu();
void wyszukajAdresatowPoNazwisku();
void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
int usunAdresata();
int podajIdWybranegoAdresata();
void edytujAdresata();
char wybierzOpcjeZMenuEdycja();
void sortingIncomes();
void sortingExpenses();
void balanceCurrenMonth();
float showExpensesCurrentMonth();
float showIncomesCurrentMonth();
void balancePenultimateMonth();
void balanceForChosenDate();
float showExpensesPenultimateMonth();
float showIncomesPenultimateMonth();
float showIncomesForChosenDate(int date1, int date2);
float showExpensesForChosenDate(int date1, int date2);
};
#endif
